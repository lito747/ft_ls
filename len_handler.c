/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:13:29 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/17 10:13:33 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_blocks_len(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;
	int			k;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = nmbr_len(tmp->cont->blocks);
		if (k > i)
			i = k;
		tmp = tmp->next;
	}
	return (i);
}

static int		get_size_len(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;
	int			k;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = nmbr_len(tmp->cont->size);
		if (k > i)
			i = k;
		tmp = tmp->next;
	}
	return (i);
}

static int		get_name_len(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;
	int			k;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = ft_strlen(tmp->cont->name);
		if (k > i)
			i = k;
		tmp = tmp->next;
	}
	return (i);
}

long long int	list_len(t_mylist *lst)
{
	long long int	i;
	t_mylist		*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i += 1;
		tmp = tmp->next;
	}
	return (i);
}

void			set_len(t_mylist *lst, int flags)
{
	if (flags & LS_S)
		lst->cont->lblocks = get_blocks_len(lst);
	else
		lst->cont->lblocks = 0;
	if (flags & LS_L)
	{
		lst->cont->lsize = get_size_len(lst);
		lst->cont->llink = get_link_len(lst);
		lst->cont->luname = get_luname_len(lst);
		lst->cont->lgname = get_lgname_len(lst);
	}
	else
	{
		lst->cont->lsize = 0;
		lst->cont->llink = 0;
	}
	lst->cont->lname = get_name_len(lst);
	lst->cont->llen = list_len(lst);
}
