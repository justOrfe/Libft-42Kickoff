/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalyon <fkalyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:09:50 by fkalyon           #+#    #+#             */
/*   Updated: 2025/01/11 01:12:56 by fkalyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static char	*ft_allocate_word(const char *str, char c, int *index)
{
	int		word_len;
	char	*word;

	word_len = 0;
	while (str[*index] == c)
		(*index)++;
	while (str[*index + word_len] != c && str[*index + word_len])
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &str[*index], word_len + 1);
	*index += word_len;
	return (word);
}

static void	ft_freeup(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}

char	**ft_split(const char *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		word_count;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str, c);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		strs[j] = ft_allocate_word(str, c, &i);
		if (!strs[j])
		{
			ft_freeup(strs, j - 1);
			return (NULL);
		}
		j++;
	}
	strs[j] = NULL;
	return (strs);
}
