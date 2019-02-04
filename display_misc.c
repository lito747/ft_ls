/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:51:45 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/16 12:51:54 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	strspc(char *str, int len)
{
	char	c;
	int		i;

	c = ' ';
	i = 0;
	write(1, str, ft_strlen(str));
	while (i < len)
	{
		write(1, &c, 1);
		i++;
	}
}

void	putnchr(int len, char c)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
		i++;
	}
}

void	display_total(t_mylist *lst)
{
	long long int	i;
	t_mylist		*tmp;

	i = 0;
	tmp = lst;
	strspc("total", 1);
	while (tmp)
	{
		i += tmp->cont->blocks;
		tmp = tmp->next;
	}
	ft_putnbr(i);
	ft_putchar('\n');
}

void	put_indent_number(int len, long long int value)
{
	int vallen;

	vallen = nmbr_len(value);
	putnchr((len - vallen), ' ');
	ft_putnbr(value);
	ft_putchar(' ');
}
