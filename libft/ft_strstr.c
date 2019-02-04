/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:40:03 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/30 13:41:18 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haysteck, const char *needle)
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
		while (haysteck[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)(haysteck + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
