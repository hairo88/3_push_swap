/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:34:06 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/25 08:21:55 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static	size_t	ft_get_digit_count(int n)
{
	int		ans;
	long	new_n;

	ans = 0;
	new_n = (long)n;
	if (n < 0)
	{
		ans++;
		new_n *= -1;
	}
	if (n == 0)
		ans++;
	while (new_n > 0)
	{
		new_n /= 10;
		ans++;
	}
	return (ans);
}

static	void	ft_create_char_number(char *ans, int n, size_t str_len)
{
	size_t	i;
	int		sign;
	long	new_n;

	i = 0;
	sign = 0;
	new_n = (long)n;
	if (n < 0)
	{
		sign = 1;
		new_n *= -1;
	}
	while (i < str_len - sign)
	{
		ans[str_len - i - 1] = new_n % 10 + '0';
		new_n /= 10;
		i++;
	}
	if (sign)
		ans[0] = '-';
	ans[i + sign] = 0;
}

char	*ft_itoa(int n)
{
	char	*ans;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_get_digit_count(n);
	ans = malloc(sizeof(char) * (str_len + 1));
	if (ans == NULL)
		return (NULL);
	ft_create_char_number(ans, n, str_len);
	return (ans);
}
