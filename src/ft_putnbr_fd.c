/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:34:55 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/03 21:39:48 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (!(n < 10 && n >= 0))
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	fd;
	int	n = 9;

	fd = open("a1.txt", O_RDWR);
	if (fd == -1)
	{
		printf("OH FUCK\n");
		printf("%d", errno);
		return (-1);
	}
	ft_putnbr_fd(n, fd);
	close(fd);
	return (0);
}
*/
