/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_I.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:21:29 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/03 18:04:00 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	vec_cross(t_vec3 v, t_vec3 u)
{
	t_vec3	result;

	result.x = (v.y * u.z) - (v.z * u.y);
	result.y = (v.z * u.x) - (v.x * u.z);
	result.z = (v.x * u.y) - (v.y * u.x);
	return (result);
}

double	vec_dot(t_vec3 v, t_vec3 u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}

double	vec_len(t_vec3 v)
{
	return (sqrt(vec_lensquared(v)));
}

double	vec_lensquared(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3	vec_normalize(t_vec3 v)
{
	return (vec_scale_d(v, vec_len(v)));
}
