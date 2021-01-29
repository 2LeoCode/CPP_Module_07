/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:15:18 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/28 21:26:23 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define templated template <typename T>

templated void iter(T * arr, unsigned int n, void (*func)(T &))
{
	for (unsigned int i = 0; i < n; i++)
		(*func)(arr[i]);
}

#endif
