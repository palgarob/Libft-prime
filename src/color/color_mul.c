/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:11:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/01 12:36:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color_mul(t_color c, double fpnd)
{
	c.r = fmin(1, c.r * fpnd);
	c.g = fmin(1, c.g * fpnd);
	c.b = fmin(1, c.b * fpnd);
	return (c);
}
