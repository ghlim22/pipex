/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:35:18 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 17:52:51 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_word(char **arr, char const *s, char c, int word_cnt);
static void	free_arr(char **arr, int height);
static char	*get_word(char const *s, char c, int *word_len);
static int	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		word_cnt;
	char	**arr;

	if (!s)
		return (NULL);
	word_cnt = count_words(s, c);
	arr = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (split_word(arr, s, c, word_cnt));
}

static char	**split_word(char **arr, char const *s, char c, int word_cnt)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	while (*s && i < word_cnt)
	{
		word = get_word(s, c, &len);
		if (!word)
			break ;
		arr[i] = malloc((len + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		ft_strlcpy(arr[i], word, len + 1);
		i++;
		s = word + len;
	}
	arr[i] = 0;
	return (arr);
}

static void	free_arr(char **arr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*get_word(char const *s, char c, int *word_len)
{
	char	*word;

	*word_len = 0;
	word = NULL;
	while (*s == c)
		s++;
	if (*s)
	{
		word = (char *)s;
		while (*s && *s != c)
		{
			++s;
			++*word_len;
		}
	}
	return (word);
}

static int	count_words(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}
