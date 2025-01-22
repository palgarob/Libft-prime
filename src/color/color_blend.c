/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:14:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:45:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color_blend(t_color a, t_color b)
{
	a.r *= b.r;
	a.g *= b.g;
	a.b *= b.b;
	if (a.r > 1)
		a.r = 1;
	if (a.g > 1)
		a.g = 1;
	if (a.b > 1)
		a.b = 1;
	return (a);
}
