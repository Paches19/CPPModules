/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:49 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/23 13:27:35 by adpachec         ###   ########.fr       */
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
	// start = clock();
	// mergeInsertionSort(_numbersDeque);
	// end = clock();
	// timeToExecute = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printContainer(_numbersDeque, "std::deque", 0);
	// std::cout << "Time to process a range of " << _numbersDeque.size() <<
	// 	" elements with std::deque: " << timeToExecute << " s\n";
	// std::cout << std::endl;
	
	// printContainer(_numbersList, "std::list", 1);
	start = clock();
	mergeInsertionSort(_numbersList);
	end = clock();
	timeToExecute = ((double) (end - start)) / CLOCKS_PER_SEC;
	printContainer(_numbersList, "std::list", 0);
	std::cout << "Time to process a range of " << _numbersList.size() << " elements with std::list: " << timeToExecute << " s\n";
}

template<typename T>
void PmergeMe::merge(T& left, T& right)
{
	T result;
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
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
	left = result;
}

template<typename T>
void PmergeMe::mergeSort(T& container)
{
	if (container.size() <= 1)
		return;

	typename T::iterator middle = container.begin();
	std::advance(middle, container.size() / 2);
	
	T left(container.begin(), middle);
	T right(middle, container.end());
	
	mergeSort(left);
	mergeSort(right);
	
	merge(left, right);
	
	container = left;
}

template<typename T>
void PmergeMe::mergeInsertionSort(T& container)
{
if (container.empty() || isSorted(container)) {
		return; // El contenedor ya está ordenado o está vacío.
	}

	// Paso 1: Dividir en pares y ordenar cada par
	std::list<int> mainChain;
	std::list<int> pendElements;

	typename T::iterator it = container.begin();
	while (it != container.end())
	{
		int first = *it;
		++it;
		if (it != container.end()) {
			int second = *it;
			++it;
			mainChain.push_back(std::min(first, second));
			pendElements.push_back(std::max(first, second));
		} else {
			mainChain.push_back(first); // Si hay un número impar de elementos
		}
	}
	mergeSort(mainChain);
	// std::cout << "Main Chain "<< std::endl;
	// std::copy(mainChain.begin(), mainChain.end(), std::ostream_iterator<int>(std::cout, " "));
	// std::cout << std::endl;
	// std::cout << "Pend Chain "<< std::endl;
	// std::copy(pendElements.begin(), pendElements.end(), std::ostream_iterator<int>(std::cout, " "));
	// std::cout << std::endl;
	// Paso 2: Insertar los elementos pendientes en la cadena principal
    while (!pendElements.empty())
	{
        std::list<int>::iterator lowestCostElementIt = pendElements.begin();
        int lowestCost = calculateInsertionCost(pendElements, *lowestCostElementIt);
        // Encuentra el elemento con el coste más bajo
        for (std::list<int>::iterator it2 = ++pendElements.begin(); it2 != pendElements.end(); ++it2)
		{
            int cost = calculateInsertionCost(pendElements, *it2);
            if (cost < lowestCost)
			{
                lowestCost = cost;
                lowestCostElementIt = it2;
            }
        }
        // Encuentra la posición de inserción en mainChain para el elemento seleccionado
        std::list<int>::iterator insertPos = findInsertPosition(mainChain, *lowestCostElementIt);
        // Inserta el elemento en la posición encontrada
        mainChain.insert(insertPos, *lowestCostElementIt);
        // Elimina el elemento de pendElements
        pendElements.erase(lowestCostElementIt);
		// std::cout << "Main Chain "<< std::endl;
		// std::copy(mainChain.begin(), mainChain.end(), std::ostream_iterator<int>(std::cout, " "));
		// std::cout << std::endl;
		// std::cout << "Pend Chain "<< std::endl;
		// std::copy(pendElements.begin(), pendElements.end(), std::ostream_iterator<int>(std::cout, " "));
		// std::cout << std::endl;
    }

	// Paso 3: Reconstruir el arreglo ordenado
	container.clear();
	std::copy(mainChain.begin(), mainChain.end(), std::back_inserter(container));
}

std::list<int>::iterator PmergeMe::findInsertPosition(std::list<int>& mainChain, int value)
{
    std::list<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it < value)
        ++it;
    return it;
}

int PmergeMe::calculateInsertionCost(const std::list<int>& pendElements, int value)
{
    // Calcula el número de movimientos para llevar 'value' al inicio o al final de la cadena pendElements
    int movesToFront = 0;
    int movesToEnd = 0;
    for (std::list<int>::const_iterator it = pendElements.begin(); it != pendElements.end(); ++it) {
        if (*it == value) break;
        movesToFront++;
    }
    for (std::list<int>::const_reverse_iterator rit = pendElements.rbegin(); rit != pendElements.rend(); ++rit) {
        if (*rit == value) break;
        movesToEnd++;
    }
    // El coste de inserción es el menor número de movimientos necesario
    return std::min(movesToFront, movesToEnd);
}

void PmergeMe::resetJacobsthal()
{
	secondLastJacobsthal = 0;
	lastJacobsthal = 1;
}

int PmergeMe::calculateNextJacobsthal() {
    if (lastJacobsthal == 0 && secondLastJacobsthal == 0) {
        // Inicializar los dos primeros números de Jacobsthal
        secondLastJacobsthal = 0; // J(0)
        lastJacobsthal = 1;       // J(1)
        return 1;
    } else {
        // Calcular el próximo número de Jacobsthal
        int nextJacobsthal = lastJacobsthal + 2 * secondLastJacobsthal;
        secondLastJacobsthal = lastJacobsthal;
        lastJacobsthal = nextJacobsthal;
        return nextJacobsthal;
    }
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

