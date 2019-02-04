/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:40:26 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/11 10:40:31 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_path(char *path, int *ac, int n)
{
	if (n != 0 && n != 1)
	{
		if (*ac >= 2)
		{
			ft_putstr(path);
			ft_putchar(':');
			ft_putchar('\n');
			*ac = 1;
		}
		else
		{
			ft_putchar('\n');
			ft_putstr(path);
			ft_putchar(':');
			ft_putchar('\n');
		}
	}
}

static int	cp_lst(t_mylist *start, int flags)
{
	t_mylist	*lst;
	t_mylist	*tmp;
	int			i;

	tmp = start;
	i = 0;
	lst = NULL;
	while (tmp)
	{
		if (!S_ISDIR(tmp->cont->mode)
			|| ((flags & LS_L) && S_ISLNK(tmp->cont->mode)))
			lst_add("", tmp->cont->name, &lst);
		tmp = tmp->next;
	}
	if (lst)
	{
		display(lst, flags);
		i = list_len(lst);
		lst_del(lst);
	}
	return (i);
}

static void	ls_init(t_mylist *start, int flags, int argc)
{
	int i;

	i = 0;
	if (flags & LS_D)
		display(start, flags);
	else
	{
		i = cp_lst(start, flags);
		set_len(start, flags);
		if (i < start->cont->llen && i != 0)
			ft_putchar('\n');
		bypass(start, flags, 2, argc);
	}
}

int			main(int argc, char **argv)
{
	int			key_mod;
	t_mylist	*ll;
	int			i;

	key_mod = 0;
	ll = NULL;
	i = pars_mod(argv, &key_mod);
	argc -= i;
	argv += i;
	ll = init_lst(argv, argc);
	if (ll)
	{
		sort_mod(ll, key_mod);
		ls_init(ll, key_mod, argc);
	}
	lst_del(ll);
	return (0);
}
