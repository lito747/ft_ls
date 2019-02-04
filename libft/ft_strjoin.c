/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:36:36 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/31 15:36:38 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ressize;
	size_t	i;
	size_t	k;
	char	*tmp;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ressize = ft_strlen(s1) + ft_strlen(s2);
	if (!(tmp = (char*)ft_memalloc(ressize + 1)))
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		tmp[i] = s2[k];
		k++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
