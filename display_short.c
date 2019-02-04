/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:32:40 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/18 11:32:43 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_data(t_file *data, t_mylist *lst)
{
	if (data->lblocks)
		put_indent_number(data->lblocks, lst->cont->blocks);
	ft_putstr(lst->cont->name);
	if (lst->next != NULL)
	{
		ft_putchar(' ');
	}
}

static void		display_short_form(t_mylist *lst, int col, int row)
{
	t_mylist	*tmpl;
	t_file		*data;
	int			tmpcol;
	int			tmprow;
	int			countrow;

	countrow = row;
	data = lst->cont;
	while (lst && countrow--)
	{
		tmpcol = col;
		tmpl = lst->next;
		while (lst && tmpcol--)
		{
			print_data(data, lst);
			if (tmpcol)
				putnchr(data->lname - ft_strlen(lst->cont->name), ' ');
			tmprow = row;
			while (lst && tmprow--)
				lst = lst->next;
		}
		ft_putchar('\n');
		lst = tmpl;
	}
}

static void		nntemp(int *a, int ln, int lbl)
{
	int	tmp;

	tmp = ln + lbl + 1;
	while (*a < tmp)
		*a += 8;
}

void			short_form(t_mylist *lst, int flags)
{
	t_tsize	tty;
	int		tmp;
	int		col;
	int		row;
	int		step;

	if (flags & LS_S)
		display_total(lst);
	ioctl(0, TIOCGWINSZ, &tty);
	row = lst->cont->llen;
	tmp = 0;
	if (flags & LS_1)
		col = 1;
	else
	{
		step = 8;
		nntemp(&step, lst->cont->lname, lst->cont->lblocks);
		col = tty.ts_cols / step;
		if (row % col)
			tmp = 1;
		row = tmp + (row / col);
	}
	display_short_form(lst, col, row);
}
