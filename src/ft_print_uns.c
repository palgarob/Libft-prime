/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:20:05 by pedropalomare     #+#    #+#             */
/*   Updated: 2024/04/28 00:18:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_dec(unsigned int n)
{
	if (n >= 10)
		write_dec(n / 10);
	write(1, &DECIMAL[n % 10], 1);
}

int	ft_print_uns(unsigned int n)
{
	int	i;

	write_dec(n);
	i = 0;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}
