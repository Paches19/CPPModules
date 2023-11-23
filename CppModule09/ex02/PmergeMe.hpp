/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:54 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/23 13:25:05 by adpachec         ###   ########.fr       */
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
# include "BinarySearchTree.hpp"

class PmergeMe
{
	private:
		std::deque<int> _numbersDeque;
		std::list<int> _numbersList;
		bool _success;

		int lastJacobsthal;
        int secondLastJacobsthal;

		static bool isNumber(const std::string& str);

		template<typename T>
		void merge(T& left, T& right);

		template<typename T>
		void mergeSort(T& container);

        template<typename T>
        void mergeInsertionSort(T& container);

		template<typename T>
		bool isSorted(const T& container);

		template<typename T>
        void printContainer(T& container, const std::string& name, bool init);

		std::list<int>::iterator findInsertPosition(std::list<int>& chain, int value);

		int calculateInsertionCost(const std::list<int>& pendElements, int value);

		int calculateNextJacobsthal();

		void resetJacobsthal();

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