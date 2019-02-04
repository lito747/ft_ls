/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:23:51 by mpytienk          #+#    #+#             */
/*   Updated: 2017/10/31 11:26:26 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
}
