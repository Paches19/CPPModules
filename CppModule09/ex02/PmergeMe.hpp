/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:48:54 by adpachec          #+#    #+#             */
/*   Updated: 2023/07/10 13:17:42 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <string>
# include <iostream>
# include <cstdlib>
# include <cctype>
# include <list>
# include <ctime>
# include <iterator>

class PmergeMe
{
	private:
		std::deque<int> _numbersDeque;
		std::list<int> _numbersList;
		bool _success;

		static bool isNumber(const std::string& str);

        template<typename T>
        void merge(T& left, T& right);

        template<typename T>
        void mergeInsertSort(T& container);

		template<typename T>
        void printContainer(T& container, const std::string& name, bool init);

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