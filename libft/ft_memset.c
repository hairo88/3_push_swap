/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:56:58 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 18:48:30 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;

	i = 0;
	if (buf == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)buf)[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
