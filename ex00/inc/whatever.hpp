/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:12:50 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/28 21:02:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define templated template <typename T>

templated void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
templated inline T min(T a, T b) { return ((a < b) ? a : b); }
templated inline T max(T a, T b) { return ((a > b) ? a : b); }

#endif
