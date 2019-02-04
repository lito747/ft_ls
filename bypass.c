/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bypass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:58:51 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/15 09:58:58 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_mylist	*read_folder(char *path, char *name, int options)
{
	t_mylist		*begin;
	DIR				*folder;
	t_dirent		*entry;

	begin = NULL;
	if (!(folder = opendir(path)))
		display_errno((const char *)name);
	else
	{
		while ((entry = readdir(folder)))
		{
			if (entry->d_name[0] != '.' || (options & LS_A))
				lst_add(path, entry->d_name, &begin);
		}
	}
	if (folder)
		closedir(folder);
	return (begin);
}

static void	b_link(t_mylist *lst, int flags, int *fin, int ac)
{
	t_mylist *ini_list;

	display_path(lst->cont->full_path, fin, ac);
	ini_list = read_folder(lst->cont->full_path, lst->cont->name, flags);
	if (ini_list)
	{
		display(ini_list, flags);
		bypass(ini_list, flags, 0, -1);
		lst_del(ini_list);
	}
}

int			bypass(t_mylist *ini_list, int flags, int fin, int ac)
{
	t_mylist			*lst;

	lst = ini_list;
	if (!(flags & LS_RA) && !fin)
		return (1);
	while (lst)
	{
		if (S_ISDIR(lst->cont->mode) && (fin || (ft_strcmp(lst->cont->name, ".")
		&& ft_strcmp(lst->cont->name, ".."))))
		{
			display_path(lst->cont->full_path, &fin, ac);
			ini_list = read_folder(lst->cont->full_path,
									lst->cont->name, flags);
			if (ini_list)
			{
				display(ini_list, flags);
				bypass(ini_list, flags, 0, -1);
				lst_del(ini_list);
			}
		}
		else if (S_ISLNK(lst->cont->mode) && !(LS_L & flags))
			b_link(lst, flags, &fin, ac);
		lst = lst->next;
	}
	return (1);
}
