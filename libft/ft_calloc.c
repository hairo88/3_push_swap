/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:27 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 18:52:59 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	else if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ans = (void *)malloc(count * size);
	if (ans == NULL)
		return (NULL);
	ft_bzero(ans, count * size);
	return (ans);
}
