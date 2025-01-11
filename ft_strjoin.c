/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalyon <fkalyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:22:26 by fkalyon           #+#    #+#             */
/*   Updated: 2025/01/10 21:08:00 by fkalyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*result;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		if (i < len1)
			result[i] = s1[i];
		else
			result[i] = s2[i - len1];
		i++;
	}
	result [total_len] = '\0';
	return (result);
}
