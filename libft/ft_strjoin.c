/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:15:12 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/25 08:29:59 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcat(char *dest, char const *src)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (dest[sum])
		sum++;
	while (src[i])
	{
		dest[sum + i] = src[i];
		i++;
	}
	dest[sum + i] = 0;
	return (dest);
}

static	size_t	ft_total_str(char const*str1, char const *str2)
{
	int		sum;

	sum = 0;
	sum += ft_strlen(str1) + ft_strlen(str2);
	return (sum);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	ans = ft_calloc(sizeof(char), (ft_total_str(str1, str2) + 1));
	if (!ans)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		ans[i] = str1[i];
		i++;
	}
	ft_strcat(ans, str2);
	return (ans);
}
