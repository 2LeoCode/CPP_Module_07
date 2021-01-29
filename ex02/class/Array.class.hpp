/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:04:16 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/29 20:37:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <typeinfo>

# define templated template <typename T>

templated class Array
{
	public:

	Array(uint32_t size = 0) : _content(new T[size]), _size(size) { }
	Array(const Array & src) : _content(new T[src._size]), _size(src._size)
	{
		for (uint32_t i = 0; i < _size; i++)
			_content[i] = src._content[i];
	}
	Array(const T * raw, uint32_t size) : _content(new T[size]), _size(size)
	{
		for (uint32_t i = 0; i < size; i++)
			_content[i] = raw[i];
	}
	~Array(void) { clear(); }

	bool operator==(const Array & src)
	{
		if (_size != src._size)
			return (false);
		for (uint32_t i = 0; i < _size; i++)
			if (_content[i] != src._content[i])
				return (false);
		return (true);
	}
	bool operator<=(const Array & src)
	{
		for (uint32_t i = 0; i < _size; i++)
			if ((i >= src._size) || (_content[i] > src._content[i]))
				return (false);
		return (true);
	}
	bool operator>=(const Array & src)
	{
		for (uint32_t i = 0; i < _size; i++)
			if (i >= src.size)
				break ;
			else if (_content[i] < src._content[i])
				return (false);
		return (true);
	}
	bool operator!=(const Array & src) { return (!((*this) == src)); }
	bool operator<(const Array & src) { return (!((*this) >= src)); }
	bool operator>(const Array & src) { return (!((*this) <= src)); }

	void operator=(const Array & arr) { set(arr); }
	void operator=(const T var) { set(var); }
	void operator+=(const Array & arr) { append(arr); }
	void operator+=(const T var) { append(var); }
	T & operator[](uint32_t const idx) const { return (at(idx)); }

	struct OutOfBoundsException : public std::exception
	{
		const char * what () const throw () { return ("Array::out_of_bounds"); }
	};

	void set(const Array & src)
	{
		clear();
		_size = src._size;
		_content = new T[_size];
		for (uint32_t i = 0; i < _size; i++)
			_content[i] = src._content[i];
	}
	void set(const T * raw, uint32_t size)
	{
		clear();
		_size = size;
		_content = new T[_size];
		for (uint32_t i = 0; i < _size; i++)
			_content[i] = raw[i];
	}
	void set(const T var)
	{
		clear();
		_size = 1;
		_content = new T[1];
		_content[0] = var;
	}
	void append(const T * raw, uint32_t size)
	{
		T * tmp = new T[_size + size];
	
		for (uint32_t i = 0; i < _size; i++)
			tmp[i] = _content[i];
		clear();
		for (uint32_t i = 0; i < size; i++)
			tmp[_size + i] = raw[i];
		_size += size;
		_content = tmp;
	}
	void append(const Array & src) { append(src._content, src._size); }
	void append(const T var) { append(&var, 1); }
	void insert(const T * raw, uint32_t size)
	{
		T * tmp = new T[_size + size];
	
		for (uint32_t i = 0; i < size; i++)
			tmp[i] = raw[i];
		for (uint32_t i = 0; i < _size; i++)
			tmp[size + i] = _content[i];
		clear();
		_size += size;
		_content = tmp;
	}
	void insert(const Array & src) { insert(src._content, src._size); }
	void insert(const T var) { insert(&var, 1); }
	void push_front(const T * raw, uint32_t size) { insert(raw, size); }
	void push_front(const Array & src) { insert(src); }
	void push_front(const T var) { insert(var); }
	void push_back(const T * raw, uint32_t size) { append(raw, size); }
	void push_back(const Array & src) { append(src); }
	void push_back(const T var) { append(var); }
	void pop_front(void)
	{
		T * tmp = new T[_size - 1];
	
		for (uint32_t i = 1; i < _size; i++)
			tmp[i - 1] = _content[i];
		clear();
		_size--;
		_content = tmp;
	}
	void pop_back(void)
	{
		T * tmp = new T[_size - 1];

		for (uint32_t i = 0; i < (_size - 1); i++)
			tmp[i] = _content[i];
		clear();
		_size--;
		_content = tmp;
	}
	void pop_at(uint32_t idx)
	{
		if (idx >= _size)
			throw (OutOfBoundsException());

		T * tmp = new T[_size - 1];

		for (uint32_t i = 0; i < idx; i++)
			tmp[i] = _content[i];
		for (uint32_t i = idx + 1; i < _size; i++)
			tmp[i - 1] = _content[i];
		clear();
		_size--;
		_content = tmp;
	}

	uint32_t size(void) const { return (_size); }
	T & at(uint32_t const idx) const
	{
		if (idx >= _size)
			throw (OutOfBoundsException());
		return (_content[idx]);
	}

	void clear(void) { if (_content) delete [] _content, _content = nullptr; }


	private:

	T * _content;
	uint32_t _size;
};

templated Array<T> operator+(const Array<T> & a, const Array<T> & b)
{
	Array<T> result(a);
	result += b;
	return (result);
}
templated Array<T> operator+(const Array<T> & a, const T b)
{
	Array<T> result(a);
	result += b;
	return (result);
}
templated std::ostream & operator<<(std::ostream & out, const Array<T> & arr)
{
	if (arr.size() == 0)
		out << "empty array";
	else if (std::string(typeid(arr[0]).name()) == "c")
	{
		for (uint32_t i = 0; i < arr.size(); i++)
			out << arr[i];
	}
	else
	{
		out << "{ ";
		for (uint32_t i = 0; i < arr.size(); i++)
		{
			out << arr[i];
			if (i != (arr.size() - 1))
				out << ", ";
		}
		out << " }";
	}
	return (out);
}

#endif
