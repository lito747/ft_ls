/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:57:37 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/26 14:11:41 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	sors_l;
	size_t	i;
	char	*dup;

	i = 0;
	sors_l = ft_strlen(s1);
	dup = (char*)ft_memalloc(sors_l + 1);
	if (dup == NULL)
		return (NULL);
	while (i < sors_l)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
