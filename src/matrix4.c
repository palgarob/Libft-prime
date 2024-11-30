/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:09:13 by muribe-l          #+#    #+#             */
/*   Updated: 2024/11/26 18:03:51 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/
lookat-function/framing-lookat-function.html
 */
t_matrix camera_to_world_matrix(t_vec from, t_vec to)
{
	t_matrix m;
	t_vec w;
	t_vec right;
	t_vec up;

	w = vec_normalize(vec_sub(from, to));
	right = vec_normalize(vec_cross(vec(0, 1, 0), w));
	up = vec_cross(w, right);
	m.m[0][0] = right.x;
	m.m[0][1] = right.y;
	m.m[0][2] = right.z;
	m.m[0][3] = 0.0;
	m.m[1][0] = up.x;
	m.m[1][1] = up.y;
	m.m[1][2] = up.z;
	m.m[1][3] = 0.0;
	m.m[2][0] = w.x;
	m.m[2][1] = w.y;
	m.m[2][2] = w.z;
	m.m[2][3] = 0.0;
	m.m[3][0] = from.x;
	m.m[3][1] = from.y;
	m.m[3][2] = from.z;
	m.m[3][3] = 1.0;
	return (m);
}

t_vec mat_vec_mult(t_matrix mat, t_vec vec)
{
	t_vec result;

	double w;

	result.x = (mat.m[0][0] * vec.x) + (mat.m[0][1] * vec.y) + (mat.m[0][2]
		* vec.z) + mat.m[0][3];
	result.y = (mat.m[1][0] * vec.x) + (mat.m[1][1] * vec.y) + (mat.m[1][2]
		* vec.z) + mat.m[1][3];
	result.z = (mat.m[2][0] * vec.x) + (mat.m[2][1] * vec.y) + (mat.m[2][2]
		* vec.z) + mat.m[2][3];
	w = (mat.m[3][0] * vec.x) + (mat.m[3][1] * vec.y) + (mat.m[3][2]
		* vec.z) + mat.m[3][3];
	if (w != 1.0 && w != 0.0)
	{
		result.x /= w;
		result.y /= w;
		result.z /= w;
	}
	return (result);
}
