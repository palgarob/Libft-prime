/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:20:21 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/05 10:06:06 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

// Get the red channel.
int get_r(int rgb)
{
	// Move 3 bytes to the right and mask out the first byte.
	return ((rgb >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgb)
{
	// Move 2 bytes to the right and mask out the first byte.
	return ((rgb >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgb)
{
	// Move 1 byte to the right and mask out the first byte.
	return ((rgb >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
	// Move 0 bytes to the right and mask out the first byte.
	return (rgba & 0xFF);
}

int get_color(double r, double g, double b)
{
	int	rint;
	int	gint;
	int	bint;

	rint = nearbyint(r * 255);
	gint = nearbyint(g * 255);
	bint = nearbyint(b * 255);
	return (rint << 24 | gint << 16 | bint << 8 | 255);
}
