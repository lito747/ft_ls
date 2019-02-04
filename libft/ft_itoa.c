/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:19:01 by mpytienk          #+#    #+#             */
/*   Updated: 2017/11/01 15:19:06 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int nmb)
{
	size_t i;

	i = 0;
	if (nmb == 0)
		i++;
	while (nmb)
	{
		i++;
		nmb /= 10;
	}
	return (i);
}

char			*ft_itoa(int nmb)
{
	size_t	counter;
	int		flag;
	char	*str;

	counter = 0;
	flag = 0;
	if (nmb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nmb < 0)
	{
		nmb = -nmb;
		counter += 1;
		flag = 1;
	}
	counter += ft_len(nmb);
	if (!(str = ft_strnew(counter)))
		return (NULL);
	while (counter--)
	{
		str[counter] = nmb % 10 + 48;
		nmb /= 10;
	}
	if (flag)
		str[0] = '-';
	return (str);
}
