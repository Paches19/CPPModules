/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:07:12 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/19 13:40:14 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span(unsigned int size);
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& other);

		class FullSpanException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class EmptySpanExcepction: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		void addNumber(int number);
		void addRange(const std::vector<int>& numbers);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		void printSpan(void) const; 
};

#endif
