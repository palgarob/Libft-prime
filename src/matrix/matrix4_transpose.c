/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_transpose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:59:54 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/03 07:08:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix4_transpose(double mat[4][4])
{
	double	cpy[4][4];
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			mat[i][j] = cpy[j][i];
			i++;
		}
		j++;
	}
	matrix_cpy(cpy, mat);
}
