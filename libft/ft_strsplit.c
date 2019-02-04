/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:13:24 by mpytienk          #+#    #+#             */
/*   Updated: 2017/11/01 15:13:26 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wcount(char const *s, char c)
{
	size_t	qword;
	int		flag;

	qword = 0;
	flag = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			qword++;
		}
		s++;
	}
	return (qword);
}

static size_t	ft_subl(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int		ft_resfree(char **res, size_t i)
{
	size_t k;

	k = 0;
	if (res[i] == NULL)
	{
		while (k < i)
		{
			free(res[k]);
			res[k] = NULL;
			k++;
		}
		ft_strdel(res);
		return (1);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	qword;
	char	**res;

	if (s == NULL)
		return (NULL);
	i = 0;
	qword = ft_wcount(s, c);
	res = (char**)malloc(sizeof(char*) * (qword + 1));
	if (res == NULL)
		return (NULL);
	while (qword)
	{
		while (*s != '\0' && *s == c)
			s++;
		res[i] = ft_strsub(s, 0, ft_subl(s, c));
		if (ft_resfree(res, i))
			return (NULL);
		s += ft_subl(s, c);
		i++;
		qword--;
	}
	res[i] = NULL;
	return (res);
}
