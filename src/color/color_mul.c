/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:11:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/16 14:23:13 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color_mul(t_color c, double fpnd)
{
	c.r *= fpnd;
	c.g *= fpnd;
	c.b *= fpnd;
	return (c);
}
