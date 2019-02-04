/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:41:19 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/16 12:41:21 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display(t_mylist *lst, int flags)
{
	t_mylist *tmp;

	sort_mod(lst, flags);
	set_len(lst, flags);
	tmp = lst;
	if (flags & LS_L)
	{
		if (!(flags & LS_D))
			display_total(lst);
		while (lst)
		{
			long_form(tmp, lst, flags);
			lst = lst->next;
		}
	}
	else
		short_form(lst, flags);
}

static int	init_sdisplay(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;

	tmp = lst;
	i = 0;
	while (lst)
	{
		if (!S_ISDIR(lst->cont->mode))
		{
			ft_putendl(lst->cont->name);
			i += 1;
		}
		lst = lst->next;
	}
	return (i);
}

int			init_display(t_mylist *lst, int flags)
{
	t_mylist	*tmp;
	int			i;

	sort_mod(lst, flags);
	set_len(lst, flags);
	tmp = lst;
	i = 0;
	if (flags & LS_L)
	{
		while (lst)
		{
			if (!S_ISDIR(lst->cont->mode))
			{
				long_form(tmp, lst, flags);
				i += 1;
			}
			lst = lst->next;
		}
	}
	i += init_sdisplay(lst);
	return (i);
}
