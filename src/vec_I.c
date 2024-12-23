/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:14:53 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/03 18:04:00 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	vec(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec_scale_m(t_vec3 v, double scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

t_vec3	vec_scale_d(t_vec3 v, double scalar)
{
	v.x /= scalar;
	v.y /= scalar;
	v.z /= scalar;
	return (v);
}

t_vec3	vec_add(t_vec3 v, t_vec3 u)
{
	t_vec3	result;

	result.x = v.x + u.x;
	result.y = v.y + u.y;
	result.z = v.z + u.z;
	return (result);
}

t_vec3	vec_sub(t_vec3 v, t_vec3 u)
{
	t_vec3	result;

	result.x = v.x - u.x;
	result.y = v.y - u.y;
	result.z = v.z - u.z;
	return (result);
}
