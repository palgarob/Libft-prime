/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2double.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:06:12 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 20:09:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	a2double(double *dst, char *src)
{
	if (!is_double(src))
		return (1);
	*dst = to_double(src);
	return (0)
}
