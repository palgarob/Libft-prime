/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:57:34 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/07 15:28:05 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number(char *s)
{
	int	n;

	n = 0;
	while (ft_isdigit(*s))
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

static int	get_number_of(char *s, int *n, int sign)
{
	int	over_flow;
	int	i;

	i = 0;
	over_flow = 1;
	*n = 0;
	while (ft_isdigit(s[i]))
	{
		*n = *n * 10 - (s[i] - '0');
		if (*n > 0 || (*n == INT_MIN && !sign) || i > 9)
			over_flow = 0;
		i++;
	}
	if (!i)
		over_flow = 0;
	if (!sign)
		*n *= -1;
	return (over_flow);
}

static int	count_spaces(char *s)
{
	int	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == '\n')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	str += count_spaces((char *)str);
	if (*str == '-')
		return (get_number((char *)str + 1) * -1);
	if (*str == '+')
		return (get_number((char *)str + 1));
	return (get_number((char *)str));
}

int	ft_atoi_of(const char *str, int *n)
{
	str += count_spaces((char *)str);
	if (*str == '-')
		return (get_number_of((char *)str + 1, n, 1));
	if (*str == '+')
		return (get_number_of((char *)str + 1, n, 0));
	return (get_number_of((char *)str, n, 0));
}

/* int	main(void)
{
	const char	*str = "0";
	int			n;

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
	printf("(%d) ", ft_atoi_of(str, &n));
	printf("%d\n", n);
	return (0);
} */
