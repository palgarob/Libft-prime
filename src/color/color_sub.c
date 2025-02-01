/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:10:21 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/01 12:37:44 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color_sub(t_color a, t_color b)
{
	a.r = fmax(0, a.r - b.r);
	a.g = fmax(0, a.g - b.g);
	a.b = fmax(0, a.b - b.b);
	return (a);
}
