/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:13:59 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:44:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
