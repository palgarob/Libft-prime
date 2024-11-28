/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:14:53 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/28 18:19:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	vec_scale_m(t_vec v, double scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

t_vec	vec_scale_d(t_vec v, double scalar)
{
	v.x /= scalar;
	v.y /= scalar;
	v.z /= scalar;
	return (v);
}

t_vec	vec_add(t_vec v, t_vec u)
{
	t_vec	result;

	result.x = v.x + u.x;
	result.y = v.y + u.y;
	result.z = v.z + u.z;
	return (result);
}

t_vec	vec_sub(t_vec v, t_vec u)
{
	t_vec	result;

	result.x = v.x - u.x;
	result.y = v.y - u.y;
	result.z = v.z - u.z;
	return (result);
}
