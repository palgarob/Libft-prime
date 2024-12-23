/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:23:02 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/20 20:28:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ray	ray_new(t_vec3 origin, t_vec3 orientation)
{
	t_ray	ray;

	ray.direction = orientation;
	ray.origin = origin;
	return (ray);
}

t_vec3	get_intersection_point(t_ray *ray, double t)
{
	return (vec_add(ray->origin, vec_scale_m(ray->direction, t)));
}
