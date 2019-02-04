/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:23:06 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/11 10:23:08 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_pos(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	set_options(const char *str, int *mod)
{
	int n;
	int i;

	i = 1;
	while (str[i])
	{
		if ((n = get_pos("aRlrtds1o", str[i])) == -1)
			display_usage(str[i]);
		if (str[i] == 'o')
		{
			*mod |= LS_O;
			*mod |= LS_L;
		}
		if (str[i] == '1')
		{
			if (*mod & LS_L)
				*mod ^= LS_L;
			*mod |= LS_1;
		}
		*mod |= (1 << n);
		i++;
	}
	return (1);
}

int			pars_mod(char **argv, int *mod)
{
	int i;

	*mod = 0;
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		set_options(argv[i], mod);
		i++;
	}
	return (i);
}
