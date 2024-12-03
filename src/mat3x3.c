/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3x3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:02:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/03 18:19:06 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	mat3x3xvec3(t_mat3x3 mat, t_vec3 vec)
{
	t_vec3	output;

	output = vec_add(
			vec_scale_m(mat.i, vec.x),
			vec_add(
				vec_scale_m(mat.j, vec.y),
				vec_scale_m(mat.k, vec.z)
			)
	);
}
