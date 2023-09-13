/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:11 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/25 08:27:02 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//単語数を取得する(大きい箱の数)
static	size_t	ft_count_words(char const *s, char c)
{
	size_t	count_words;
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 0;
	count_words = 0;
	while (s[i])
	{
		if (!flag && s[i] != c)
		{
			count_words++;
			flag = 1;
		}
		if (flag && s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count_words);
}

//単語をそれぞれ独立した文字列にする
static	char	*ft_create_str(char const *s, char c)
{
	size_t	i;
	char	*ans;
	size_t	count;
	size_t	flag;

	i = 0;
	flag = 0;
	count = 0;
	while (s[count] && s[count] != c)
		count++;
	ans = ft_calloc(sizeof(char), count + 1);
	if (ans == NULL)
		return (NULL);
	ft_memcpy(ans, s, count);
	return (ans);
}

static	void	ft_check(char	**ans, size_t	now_count_words)
{
	size_t	i;

	i = 0;
	while (i < now_count_words)
	{
		free(ans[i]);
		i++;
	}
	free(ans);
}

//大きな箱に小さな箱を格納する
static	void	ft_insert(char const *s, char c,
size_t count_words, char **ans)
{
	size_t	i;
	size_t	now_count_words;
	size_t	flag;

	i = 0;
	flag = 0;
	now_count_words = 0;
	while (s[i] && now_count_words < count_words)
	{
		if (!flag && s[i] != c)
		{
			ans[now_count_words] = ft_create_str((char *)&s[i], c);
			if (ans[now_count_words] == NULL)
				ft_check(ans, now_count_words);
			now_count_words++;
			flag = 1;
		}
		if (flag && s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	count_words;

	count_words = ft_count_words(s, c);
	ans = ft_calloc(sizeof(char *), count_words + 1);
	if (ans == NULL)
		return (NULL);
	ft_insert(s, c, count_words, ans);
	return (ans);
}
