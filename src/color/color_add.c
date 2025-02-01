/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:08:35 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/30 12:11:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	color_add(t_color a, t_color b)
{
	a.r = fmin(1, a.r + b.r);
	a.g = fmin(1, a.g + b.g);
	a.b = fmin(1, a.b + b.b);
	return (a);
}
