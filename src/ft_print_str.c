/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:11:41 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/28 00:18:22 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	n;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = ft_strlen(str);
	write(1, str, n);
	return (n);
}
