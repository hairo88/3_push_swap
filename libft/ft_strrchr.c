/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:07:26 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 18:51:38 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (s[n] == c)
		return ((char *)&s[n]);
	while (n > 0)
	{
		n--;
		if (s[n] == (char)c)
			return ((char *)&s[n]);
	}
	return (NULL);
}
