/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:37:00 by mpytienk          #+#    #+#             */
/*   Updated: 2017/11/01 10:37:06 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isskip(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t			start;
	size_t			end;
	char			*ret;

	if (!s)
		return (0);
	start = 0;
	while (ft_isskip(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && ft_isskip(s[end]))
		end--;
	ret = ft_strsub(s, start, end - start + 1);
	return (ret);
}
