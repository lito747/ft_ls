/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:46:05 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/30 15:47:24 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_finddigit(const char *str, int *i, int *neg)
{
	while ((str[*i] == '\n') || (str[*i] == '\t') || (str[*i] == '\v') ||
		(str[*i] == ' ') || (str[*i] == '\f') || (str[*i] == '\r'))
		*i += 1;
	if (str[*i] == '-')
		*neg = -1;
	if (str[*i] == '-' || str[*i] == '+')
		*i += 1;
}

int			ft_atoi(const char *str)
{
	int					i;
	int					is_negative;
	unsigned long long	result;

	i = 0;
	result = 0;
	is_negative = 1;
	ft_finddigit(str, &i, &is_negative);
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if (result > 9223372036854775807)
	{
		if (is_negative == 1)
			return (-1);
		return (0);
	}
	return ((int)result * is_negative);
}
