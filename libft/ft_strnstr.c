/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:13:20 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/30 14:13:24 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haysteck, const char *needle, size_t len)
{
	size_t i;
	size_t k;
	size_t j;

	i = 0;
	k = ft_strlen(haysteck);
	if (ft_strlen(needle) == 0)
		return ((char*)haysteck);
	while (i < k)
	{
		j = 0;
		while (haysteck[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)(haysteck + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
