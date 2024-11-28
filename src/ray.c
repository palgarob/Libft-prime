/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:23:02 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/28 18:23:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ray	ray(t_vec origin, t_vec orientation)
{
	t_ray	ray;

	ray.orientation = orientation;
	ray.origin = origin;
	return (ray);
}

t_vec	getpoint_ray(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_scale_m(ray.orientation, t)));
}
