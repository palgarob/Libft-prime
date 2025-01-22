/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:08:35 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/16 14:23:10 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color_add(t_color a, t_color b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	if (a.r > 1)
		a.r = 1;
	if (a.g > 1)
		a.g = 1;
	if (a.b > 1)
		a.b = 1;
	return (a);
}
