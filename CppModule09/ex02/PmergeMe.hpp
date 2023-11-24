/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:54 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/24 12:23:56 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <string>
# include <iostream>
# include <cstdlib>
# include <list>
# include <limits.h>
# include <cmath>
# include <iterator>

struct Pair
{
    long a; // El elemento 'a' del par, que será el menor de los dos
    long b; // El elemento 'b' del par, que será el mayor de los dos
	Pair(long a, long b) : a(a), b(b) {};
};

class PmergeMe
{
	private:
		std::deque<int> _numbersDeque;
		std::list<int> _numbersList;
		bool _success;

		static bool isNumber(const std::string& str);
		
		void formPairs(std::list<int>& container, std::list<Pair>& pairs, std::list<long>& singleElements);
		void merge(std::list<Pair>& left, std::list<Pair>& right, std::list<Pair>& result);
		void mergeSort(std::list<Pair>& container);
		void insertInMainChain(std::list<int>& mainChain, std::list<int>& pendElements);
		void mergeInsertionSort(std::list<int>& container);

		void formPairs(std::deque<int>& container, std::deque<Pair>& pairs, std::deque<long>& singleElements);
		void merge(std::deque<Pair>& left, std::deque<Pair>& right, std::deque<Pair>& result);
		void mergeSort(std::deque<Pair>& container);
		void insertInMainChain(std::deque<int>& mainChain, std::deque<int>& pendElements);
		void mergeInsertionSort(std::deque<int>& container);

		template<typename T>
		T generateJacobsthalSequence(size_t size);

		template<typename T>
		bool isSorted(const T& container);

		template<typename T>
        void printContainer(T& container, const std::string& name, bool init);

		std::list<int>::iterator findInsertPosition(std::list<int>& chain, int value);
		int findInsertPosition(std::deque<int>& mainChain, int value);

	public:
		PmergeMe(int argc, char* argv[]);
		PmergeMe(std::deque<int> source);
		PmergeMe(std::list<int> source);
		PmergeMe(const PmergeMe& other);
		~PmergeMe(void);

		PmergeMe& operator=(const PmergeMe& other);

    	void sortAndPrint(void);
};

#endif