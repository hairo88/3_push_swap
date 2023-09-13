/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:14:30 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/25 08:20:29 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strcmp(const char *p1, char *p2)
{
	int		i;

	i = 0;
	if (p1 == NULL && p2 == NULL)
		return (0);
	else if (p1 == NULL)
		return (1);
	else if (p2 == NULL)
		return (-1);
	while (p1[i] == p2[i])
	{
		if (p1[i] == 0 && p2[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (p1[i] - p2[i]);
}

static	int	ft_create_number(const char *str, int sign)
{
	size_t	i;
	long	num;

	i = 0;
	num = 0;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if (sign == 1 && str[i + 1])
		{
			if ((num == LONG_MAX / 10 && str[i + 1] - '0'
					> LONG_MAX % 10) || (num > LONG_MAX / 10 && str[i + 1]))
				return ((int)LONG_MAX);
		}
		else if (str[i + 1])
		{
			if ((num == LONG_MAX / 10 && str[i + 1] - '0' > LONG_MAX % 10 + 1)
				|| (num > LONG_MAX / 10 && str[i + 1]))
				return ((int)LONG_MIN);
		}
		i++;
	}
	return (sign * (int)num);
}

int	ft_atoi(const char *str)
{
	int		ans;
	size_t	i;
	int		sign;

	i = 0;
	ans = 0;
	sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	ans = ft_create_number(&str[i], sign);
	return (ans);
}
