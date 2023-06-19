/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:24:24 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/19 14:07:04 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	//MutantStack
	MutantStack<int> mstack;
	std::cout << "Push 5" << std::endl;
	mstack.push(5);
	std::cout << "Push 17" << std::endl;
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Pop" << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Push 3" << std::endl;
	mstack.push(3);
	std::cout << "Push 5" << std::endl;
	mstack.push(5);
	std::cout << "Push 737" << std::endl;
	mstack.push(737);
	std::cout << "Push 0" << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "- MUTANT - " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Top copy stack: " << s.top() << std::endl;
	std::cout << "Size copy stack: " << s.size() << std::endl;

	 std::cout << std::endl;

    // List
    std::list<int> lst;
    std::cout << "Push 5" << std::endl;
    lst.push_back(5);
    std::cout << "Push 17" << std::endl;
    lst.push_back(17);
    std::cout << "Top: " << lst.front() << std::endl;
    std::cout << "Pop" << std::endl;
    lst.pop_back();
    std::cout << "Size: " << lst.size() << std::endl;
    std::cout << "Top: " << lst.front() << std::endl;
    std::cout << "Push 3" << std::endl;
    lst.push_back(3);
    std::cout << "Push 5" << std::endl;
    lst.push_back(5);
    std::cout << "Push 737" << std::endl;
    lst.push_back(737);
    std::cout << "Push 0" << std::endl;
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    std::cout << "- LIST - " << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
	return 0;
}
