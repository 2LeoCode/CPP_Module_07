/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:15:08 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/28 21:41:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iter.hpp>
# include <string>
# include <iostream>

void inc(int &i) { i++; }
void setHelloWorld(std::string & s)  { s = "Hello World!"; }
int main(void)
{
	int * intArr = new int[10];

	for (int i = 0; i < 10; i++)
		intArr[i] = i, std::cout << intArr[i] << ' ';
	std::cout << std::endl;
	::iter(intArr, 10, &::inc);
	
	for (int i = 0; i < 10; i++)
		std::cout << intArr[i] << ' ';
	std::cout << std::endl;
	delete [] intArr;

	std::string stringArr[5] = { "Hello", "Everyone", "But", "Not", "World" };
	for (int i = 0; i < 5; i++)
		std::cout << stringArr[i] << std::endl;
	std::cout << std::endl;
	::iter(stringArr, 5, &::setHelloWorld);
	for (int i = 0; i < 5; i++)
		std::cout << stringArr[i] << std::endl;
	return (0);
}
