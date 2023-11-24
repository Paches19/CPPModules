/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:49 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/24 13:33:03 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char* argv[]) : _success(false)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input numbers provided." << std::endl;
		return;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (!isNumber(arg))
		{
			std::cerr << "Error: Invalid argument \"" << arg
				<< "\". Only positive integers are allowed." << std::endl;
			return ;
		}
		int number = std::atoi(argv[i]);
		if (number >= 0)
		{
			_numbersDeque.push_back(number);
			_numbersList.push_back(number);
		}
		else
		{
			std::cerr << "Error: Invalid argument \"" << arg
				<< "\". Only positive integers are allowed." << std::endl;
			return ;
		}
	}
	_success = true;
}

PmergeMe::PmergeMe(std::deque<int> source) : _numbersDeque(source), _success(false){}

PmergeMe::PmergeMe(std::list<int> source) : _numbersList(source), _success(false){}

PmergeMe::PmergeMe(const PmergeMe& other) :_numbersDeque(other._numbersDeque),
	_numbersList(other._numbersList), _success(other._success) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_numbersDeque = other._numbersDeque;
		_numbersList = other._numbersList;
		_success = other._success;
	}
	return *this;
}

template<typename T>
bool PmergeMe::isSorted(const T& container)
{
	if (container.empty())
		return true;

	typename T::const_iterator it = container.begin();
	typename T::const_iterator next = it;
	++next;

	while (next != container.end()) {
		if (*it > *next) {
			return false;
		}
		++it;
		++next;
	}

	return true;
}

void PmergeMe::sortAndPrint()
{
	if (!_success)
		return ;
	clock_t start, end;
	double timeToExecute;

	if (PmergeMe::isSorted(_numbersDeque))
	{
		std::cout << "Conjunto ya ordenado" << std::endl;
		return ;
	}
	// printContainer(_numbersDeque, "std::deque", 1);
	start = clock();
	mergeInsertionSort(_numbersDeque);
	end = clock();
	timeToExecute = ((double) (end - start)) / CLOCKS_PER_SEC;
	printContainer(_numbersDeque, "std::deque", 0);
	std::cout << "Time to process a range of " << _numbersDeque.size() <<
		" elements with std::deque: " << timeToExecute << " s\n";
	std::cout << std::endl;
	
	// printContainer(_numbersList, "std::list", 1);
	start = clock();
	mergeInsertionSort(_numbersList);
	end = clock();
	timeToExecute = ((double) (end - start)) / CLOCKS_PER_SEC;
	printContainer(_numbersList, "std::list", 0);
	std::cout << "Time to process a range of " << _numbersList.size() << " elements with std::list: " << timeToExecute << " s\n";
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // 
// 						FUNCIONES LISTA								//
// // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // 

// Función para formar pares de elementos
void PmergeMe::formPairs(std::list<int>& container, std::list<Pair>& pairs, std::list<long>& singleElements)
{
	std::list<int>::iterator it = container.begin();
	while (it != container.end())
	{
		int first = *it++;
		if (it != container.end())
		{
			int second = *it++;
			// Asegúrate de que 'first' es el mayor y 'second' es el menor
			if (first < second) std::swap(first, second);
				pairs.push_back(Pair(first, second));
		} else
			// Si el número de elementos es impar, guarda el elemento solitario
			singleElements.push_back(first);
	}
}

void PmergeMe::merge(std::list<Pair>& left, std::list<Pair>& right, std::list<Pair>& result)
{
    while (!left.empty() && !right.empty())
	{
        if (left.front().a <= right.front().a)
		{
            result.push_back(left.front());
            left.pop_front();
        }
		else
		{
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty())
	{
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty())
	{
        result.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::mergeSort(std::list<Pair>& container)
{
    if (container.size() <= 1) return;

    std::list<Pair>::iterator middle = container.begin();
    std::advance(middle, container.size() / 2);

    std::list<Pair> left(container.begin(), middle);
    std::list<Pair> right(middle, container.end());

    mergeSort(left);
    mergeSort(right);

    container.clear();
    merge(left, right, container);
}

void PmergeMe::insertInMainChain(std::list<int>& mainChain, std::list<int>& pendElements)
{
	std::list<int> jacobsthalSequence = PmergeMe::generateJacobsthalSequence<std::list<int> >(pendElements.size());

	int lastIndx = 0;
	for (std::list<int>::iterator jIt = jacobsthalSequence.begin(); jIt != jacobsthalSequence.end(); ++jIt)
	{
		if (*jIt == lastIndx)
			continue ;
		int idx = *jIt;
		if (idx >= static_cast<int>(pendElements.size()))
			idx = static_cast<int>(pendElements.size() - 1);
		std::list<int>::iterator itPend = pendElements.begin();
		std::advance(itPend, idx);
		
		int pendValue = *itPend;
		std::list<int>::iterator itMain = findInsertPosition(mainChain, pendValue);
		mainChain.insert(itMain, pendValue);
		// Insertar elementos anteriores no insertados
		while (--idx > lastIndx || (lastIndx == 0 && idx == 0))
		{
			itPend = pendElements.begin();
			std::advance(itPend, idx);
			pendValue = *itPend;
			itMain = findInsertPosition(mainChain, pendValue);
			mainChain.insert(itMain, pendValue);
		}
		lastIndx = *jIt;
		if (*jIt >= static_cast<int>(pendElements.size()))
			break ;
	}
}

void PmergeMe::mergeInsertionSort(std::list<int>& container)
{
    if (container.empty() || isSorted(container))
        return; // El contenedor ya está ordenado o está vacío.

    // Paso 1: Crear pares
    std::list<Pair> pairs;
    std::list<int>::iterator it = container.begin();
    while (it != container.end())
	{
        long first = *it++;
        long second = (it != container.end()) ? *it++ : (long) INT_MIN - 1;
        pairs.push_back(Pair(first > second ? first : second, first > second ? second : first));
    }
    // Ordena los pares por 'ak'
    mergeSort(pairs);
    // Separar los pares ordenados en 'mainChain' y 'pendElements'
    std::list<int> mainChain;
    std::list<int> pendElements;
    for (std::list<Pair>::iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt)
	{
		if (pairIt->a <= INT_MAX && pairIt->a >= 0)
        	mainChain.push_back(pairIt->a);
        if (pairIt->b <= INT_MAX && pairIt->b >= 0)
            pendElements.push_back(pairIt->b);
    }
	// Paso 4: Insertar los elementos pendientes en la cadena principal
    insertInMainChain(mainChain, pendElements);
    container = mainChain;
}

std::list<int>::iterator PmergeMe::findInsertPosition(std::list<int>& mainChain, int value)
{
    std::list<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it <= value)
        ++it;
    return it;
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // 
// 						FUNCIONES DEQUE								//
// // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // 

// Función para formar pares de elementos
void PmergeMe::formPairs(std::deque<int>& container, std::deque<Pair>& pairs, std::deque<long>& singleElements)
{
	std::deque<int>::iterator it = container.begin();
	while (it != container.end()) {
		int first = *it++;
		if (it != container.end()) {
			int second = *it++;
			// Asegúrate de que 'first' es el mayor y 'second' es el menor
			if (first < second) std::swap(first, second);
			pairs.push_back(Pair(first, second));
		} else {
			// Si el número de elementos es impar, guarda el elemento solitario
			singleElements.push_back(first);
		}
	}
}

void PmergeMe::merge(std::deque<Pair>& left, std::deque<Pair>& right, std::deque<Pair>& result)
{
    while (!left.empty() && !right.empty())
	{
        if (left.front().a <= right.front().a)
		{
            result.push_back(left.front());
            left.pop_front();
        }
		else
		{
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty())
	{
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty())
	{
        result.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::mergeSort(std::deque<Pair>& container)
{
    if (container.size() <= 1) return;

    std::deque<Pair>::iterator middle = container.begin();
    std::advance(middle, container.size() / 2);

    std::deque<Pair> left(container.begin(), middle);
    std::deque<Pair> right(middle, container.end());

    mergeSort(left);
    mergeSort(right);

    container.clear();
    merge(left, right, container);
}

void PmergeMe::insertInMainChain(std::deque<int>& mainChain, std::deque<int>& pendElements)
{
	std::deque<int> jacobsthalSequence = PmergeMe::generateJacobsthalSequence<std::deque<int> >(pendElements.size());

	int lastIndx = 0;
	for (std::deque<int>::iterator jIt = jacobsthalSequence.begin(); jIt != jacobsthalSequence.end(); ++jIt)
	{
		if (*jIt == lastIndx)
			continue ;
		int idx = *jIt;
		if (idx >= static_cast<int>(pendElements.size()))
			idx = static_cast<int> (pendElements.size() - 1);

		int pendValue = pendElements[idx];
		int insertPos = findInsertPosition(mainChain, pendValue);
        mainChain.insert(mainChain.begin() + insertPos, pendValue);

        // Inserta elementos pendientes anteriores que no se han insertado aún
        while (--idx > lastIndx || (lastIndx == 0 && idx == 0))
		{
            pendValue = pendElements[idx];
            insertPos = findInsertPosition(mainChain, pendValue);
            mainChain.insert(mainChain.begin() + insertPos, pendValue);
        }
		// Actualiza el índice del último elemento insertado
        lastIndx = *jIt;
		if (*jIt >= static_cast<int>(pendElements.size()))
			break ;
    }
}

void PmergeMe::mergeInsertionSort(std::deque<int>& container)
{
    if (container.empty() || isSorted(container))
        return; // El contenedor ya está ordenado o está vacío.

    // Paso 1: Crear pares
    std::deque<Pair> pairs;
    std::deque<int>::iterator it = container.begin();
    while (it != container.end())
	{
        long first = *it++;
        long second = (it != container.end()) ? *it++ : (long) INT_MIN - 1;
        pairs.push_back(Pair(first > second ? first : second, first > second ? second : first));
    }
    // Ordena los pares por 'ak'
    mergeSort(pairs);
    // Separar los pares ordenados en 'mainChain' y 'pendElements'
    std::deque<int> mainChain;
    std::deque<int> pendElements;
    for (std::deque<Pair>::iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt)
	{
		if (pairIt->a <= INT_MAX && pairIt->a >= 0)
        	mainChain.push_back(pairIt->a);
        if (pairIt->b <= INT_MAX && pairIt->b >= 0)
            pendElements.push_back(pairIt->b);
    }
	// Paso 4: Insertar los elementos pendientes en la cadena principal
    insertInMainChain(mainChain, pendElements);
    container = mainChain;
}

int PmergeMe::findInsertPosition(std::deque<int>& mainChain, int value)
{
    for (int i = 0; i < static_cast<int>(mainChain.size()); i++)
	{
        if (mainChain[i] >= value)
            return i;
    }
	return static_cast<int>(mainChain.size());
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // 
// 						FUNCIONES TEMPLATE							//
// // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // 

template<typename T>
T PmergeMe::generateJacobsthalSequence(size_t size)
{
    T sequence;
    int jacobsthalPrev = 0;
    int jacobsthalCurr = 1;

    while (sequence.size() < size)
	{
        sequence.push_back(jacobsthalPrev);
        int nextJacobsthal = jacobsthalCurr + 2 * jacobsthalPrev;
        jacobsthalPrev = jacobsthalCurr;
        jacobsthalCurr = nextJacobsthal;
    }
    return sequence;
}

template<typename T>
void PmergeMe::printContainer(T& container, const std::string& name, bool init)
{
	if (init)
   		std::cout << "Before sorting with " << name << ": ";
	else
		std::cout << "After sorting with " << name << ": ";
    std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

bool PmergeMe::isNumber(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

