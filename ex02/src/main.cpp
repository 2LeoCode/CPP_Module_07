/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:02:57 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/29 20:38:18 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.class.hpp>
#include <string>

int main(void)
{
	std::cout << "Initialisation from size:" << std::endl << std::endl;
	{
		Array <int> a(5);
		std::cout << "<int>Size (5): " << a << std::endl;
		Array <float> b;
		std::cout << "<float>Size (0): " << b << std::endl << std::endl;
	}
	std::cout << "Initialisation from array:" << std::endl << std::endl;
	{
		int rawA[] = {1, 2, 3, 4, 5};
		Array <int> a(rawA, 5);
		std::cout << "<int> " << a << std::endl;
		std::string rawB("Hello World!");
		Array <char> b(rawB.c_str(), rawB.length());
		std::cout << "<char> " << b << std::endl << std::endl;
	}
	std::cout << "Array alteration:" << std::endl << std::endl;
	Array <char> a;

	std::cout << a << std::endl;
	a.append("World ", 6);
	std::cout << '\"' << a << '\"' << std::endl;
	a.insert("Hello ", 6);
	std::cout << '\"' << a << '\"' << std::endl;
	a.append('!');
	std::cout << '\"' << a << '\"' << std::endl;
	a.pop_back();
	a.pop_back();
	std::cout << '\"' << a << '\"' << std::endl;
	a.pop_front();
	std::cout << '\"' << a << '\"' << std::endl;
	a.pop_at(4);
	std::cout << '\"' << a << '\"' << std::endl << std::endl;

	std::cout << "operator+:" << std::endl << std::endl;

	std::cout << '\"' << Array<char>("Hello", 5) + Array<char>(" World !", 8) << '\"' << std::endl << std::endl;
	std::cout << "Error handling:" << std::endl << std::endl;

	try { a[20] = 'b'; std::cout << "Error not thrown" << std::endl; }
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { a.pop_at(20); std::cout << "Error not thrown" << std::endl; }
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	return (0);
}
