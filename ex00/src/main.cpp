/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:25:35 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/28 21:06:53 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <whatever.hpp>
#include <iostream>

int main(void)
{
	int a = 5, b = 0;
	float c = 2.5f, d = 3.5f;
	char e = 'E', f = 'F';

	std::cout << a << ' ' << b << std::endl;
	::swap (a, b);
	std::cout << a << ' ' << b << std::endl << std::endl;
	std::cout << c << ' ' << d << std::endl;
	::swap (c, d);
	std::cout << c << ' ' << d << std::endl << std::endl;
	std::cout << e << ' ' << f << std::endl;
	::swap (e, f);
	std::cout << e << ' ' << f << std::endl << std::endl;
	std::cout << "MINIMUM <" << a << "> <" << b << "> " << ::min (a, b) << std::endl;
	std::cout << "MAXIMUM <" << a << "> <" << b << "> " << ::max (a, b) << std::endl;
	std::cout << "MINIMUM <" << c << "> <" << d << "> " << ::min (c, d) << std::endl;
	std::cout << "MAXIMUM <" << c << "> <" << d << "> " << ::max (c, d) << std::endl;
	std::cout << "MINIMUM <" << e << "> <" << f << "> " << ::min (e, f) << std::endl;
	std::cout << "MAXIMUM <" << e << "> <" << f << "> " << ::max (e, f) << std::endl;
	return (0);
}
