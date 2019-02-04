/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:39:48 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/31 10:55:54 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dest;
	size_t	i;

	i = 0;
	src2 = (char *)src;
	dest = (char *)dst;
	if (src2 < dest)
	{
		while (len--)
			*(dest + len) = *(src2 + len);
	}
	else
	{
		ft_memcpy(dest, src2, len);
	}
	return (dest);
}
