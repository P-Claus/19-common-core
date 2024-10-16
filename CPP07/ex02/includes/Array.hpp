#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
class Array
{
	private:
		int		_size;
		T* 		_array;
	public:
		//constructors
		Array(): _size(0)
		{
			std::cout << "The default constructor has been called" << std::endl;	
			_array = new T[_size];	
			std::cout << "size: " << _size << " | address of the array: " << &_array << std::endl;
		}

		Array(size_t size): _size(size)
		{
			std::cout << "Parameter constructor has been called" << std::endl;
			_array = new T[_size];
			std::cout << "size: " << _size << " | address of the array: " << &_array << std::endl;
		}

		Array(const Array& other)
		{
			std::cout << "The copy constructor has been called" << std::endl;
			_array = new T[other._size];
			_size = other._size;
			for (int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			std::cout << "size: " << _size << " | address of the array: " << &_array << std::endl;
		}

		Array operator=(const Array& rhs)
		{
			std::cout << "The overloaded assignment operator has been called" << std::endl;
			if (this != &rhs)
			{
				delete [] _array;
				this->_size = rhs._size;
				_array = new T[_size];
				for (int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}

		//destructor
		~Array()
		{
			std::cout << "The destructor has been called" << std::endl;
			delete _array;
		}

		//subscript overload
		T &operator[](int index)
		{
			if (index >= _size)
				throw Array::indexTooHighException();
			else if (index < 0)
				throw Array::indexTooLowException();
			return (_array[index]);
		}

		//getter
		T	const getData(int index) const
		{
			if (index >= _size)
				throw Array::indexTooHighException();
			else if (index < 0)
				throw Array::indexTooLowException();
			return (_array[index]);
		}
		
		//setter
		void	setData(T index, T data)
		{
			if (index >= _size)
				throw Array::indexTooHighException();
			else if (index < 0)
				throw Array::indexTooLowException();
			_array[index] = data;	
		}
		//misc.
		void	printContent(void)
		{
			for (int i = 0; i < this->_size; i++)
				std::cout << "#" << i << " -> " << this->_array[i] << std::endl;
		}

		int	size(void) const
		{
			return (_size);
		}

	//exceptions
	class indexTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class indexTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
