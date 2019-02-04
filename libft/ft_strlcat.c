/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:13:53 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/30 12:24:39 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t srsize;
	size_t dssize;

	i = 0;
	srsize = ft_strlen(src);
	dssize = ft_strlen(dst);
	if (size <= dssize)
		return (srsize + size);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (i < (size - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dssize + srsize);
}
