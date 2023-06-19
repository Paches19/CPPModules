/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:26:22 by adpachec          #+#    #+#             */
/*   Updated: 2023/06/19 12:28:56 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;

	public:
		Array(void) : _data(NULL), _size(0) {}
		Array(unsigned int n) : _data(n < 1 ? NULL : new T[n]()), _size(n < 1 ? 0 : n){}
		Array(const Array& other)
		{
			if (this != &other)
				*this = other;
		}
		~Array(void)
		{
			delete[] this->_data;
		}

		Array& operator=(const Array& other)
		{
			if (this == &other)
				return *this;

			if (_data != NULL)
				delete _data;

			if (other.getSize() < 1)
			{
				this->_data = NULL;
				this->_size = 0;
			}
			else
			{
				this->_data = new T[other.getSize()];
				for(unsigned int i = 0; i < other.getSize(); i++)
					this->_data[i] = other._data[i];
				this->_size = other.getSize();
			}
			return *this;
		}

		class OutOfRange: public std::exception
		{
            public:
                virtual const char* what() const throw()
                {
					return ("Element out of range\n");
				}
        };
		
		T& operator[](unsigned int index)
		{
			if (index >= this->_size)
			{
				throw OutOfRange();
			}
			return this->_data[index];
		}

		unsigned int getSize() const
		{
			return this->_size;
		}
};

#endif

