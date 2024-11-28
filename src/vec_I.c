/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_I.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:21:29 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/28 18:21:56 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	vec_cross(t_vec v, t_vec u)
{
	t_vec	result;

	result.x = (v.y * u.z) - (v.z * u.y);
	result.y = (v.z * u.x) - (v.x * u.z);
	result.z = (v.x * u.y) - (v.y * u.x);
	return (result);
}

double	vec_dot(t_vec v, t_vec u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}

double	vec_len(t_vec v)
{
	return (sqrt(vec_lensquared(v)));
}

double	vec_lensquared(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec	vec_normalize(t_vec v)
{
	return (vec_scale_d(v, vec_len(v)));
}
