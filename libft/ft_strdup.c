/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:05:42 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/25 08:27:36 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ans;
	int		size;
	int		index;

	index = 0;
	if (s1 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (ans == NULL)
		return (NULL);
	while (s1[index])
	{
		ans[index] = s1[index];
		index++;
	}
	ans[index] = 0;
	return (ans);
}
