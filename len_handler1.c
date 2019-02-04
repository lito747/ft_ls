/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_handler1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:56:30 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/17 10:57:10 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	nmbr_len(long long int i)
{
	int k;

	k = 1;
	while (i / 10)
	{
		i /= 10;
		k++;
	}
	return (k);
}

int	get_link_len(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;
	int			k;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = nmbr_len(tmp->cont->nbr_link);
		if (k > i)
			i = k;
		tmp = tmp->next;
	}
	return (i);
}

int	get_lgname_len(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;
	int			k;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = ft_strlen(getgrgid(tmp->cont->group_id)->gr_name);
		if (k > i)
			i = k;
		tmp = tmp->next;
	}
	return (i);
}

int	get_luname_len(t_mylist *lst)
{
	t_mylist	*tmp;
	int			i;
	int			k;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = ft_strlen(getpwuid(tmp->cont->user_id)->pw_name);
		if (k > i)
			i = k;
		tmp = tmp->next;
	}
	return (i);
}
