/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalyon <fkalyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:23:32 by fkalyon           #+#    #+#             */
/*   Updated: 2024/12/13 17:42:13 by fkalyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z' ) || (a >= 'a' && a <= 'z'))
	{
		return (1);
	}
	return (0);
}
