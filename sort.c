/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:27:42 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/15 12:27:45 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort(t_mylist *lst, int (*f)(t_file*, t_file*))
{
	t_file		*tmp_cont;
	t_mylist	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (f(lst->cont, lst->next->cont))
		{
			tmp_cont = lst->cont;
			lst->cont = lst->next->cont;
			lst->next->cont = tmp_cont;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
}

void			sort_mod(t_mylist *lst, int flags)
{
	if ((LS_R & flags) && (LS_T & flags))
		sort(lst, &descending_time);
	else if (LS_T & flags)
		sort(lst, &ascend_time);
	else if (LS_R & flags)
		sort(lst, &descending_name);
	else
		sort(lst, &ascend_name);
}
