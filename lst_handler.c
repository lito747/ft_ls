/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:00:09 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/11 12:00:11 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			path_create(char *fpath, char *name, char *path)
{
	int i;

	i = 0;
	while (path[i])
	{
		fpath[i] = path[i];
		i++;
	}
	if (i > 0 && name[0] != '\0')
		fpath[i++] = '/';
	while (*name)
	{
		fpath[i] = *name;
		i++;
		name++;
	}
	if (i < PATH_MAX)
		return (1);
	errno = ENAMETOOLONG;
	return (0);
}

static	void		new_struct(t_file *new, char *path,
								char *name, t_stat *stat)
{
	if (!(new->name = ft_strdup(name)))
		exit(EXIT_FAILURE);
	new->blocks = stat->st_blocks;
	new->mode = stat->st_mode;
	new->nbr_link = stat->st_nlink;
	new->user_id = stat->st_uid;
	new->group_id = stat->st_gid;
	new->size = stat->st_size;
	new->st_rdev = stat->st_rdev;
	new->time = stat->st_mtime;
	new->full_path = path;
}

void				lst_del(t_mylist *lst)
{
	t_mylist *tmp;

	while (lst)
	{
		free(lst->cont->name);
		lst->cont->name = NULL;
		free(lst->cont->full_path);
		lst->cont->full_path = NULL;
		free(lst->cont);
		lst->cont = NULL;
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

static	t_mylist	*new_nod(char *path, char *name, t_stat *stat)
{
	t_mylist	*l_new;
	t_file		*nod;

	if ((nod = (t_file*)ft_memalloc(sizeof(t_file))) == NULL)
		exit(EXIT_FAILURE);
	if ((l_new = (t_mylist *)ft_memalloc(sizeof(t_mylist *))) == NULL)
		exit(EXIT_FAILURE);
	new_struct(nod, path, name, stat);
	l_new->cont = nod;
	l_new->next = NULL;
	return (l_new);
}

int					lst_add(char *path, char *name, t_mylist **lst)
{
	t_stat	stat;
	char	*fpath;

	if ((fpath = ft_strnew(PATH_MAX)) == NULL)
		exit(EXIT_FAILURE);
	if (!path_create(fpath, name, path))
	{
		display_errno(name);
		return (-1);
	}
	if (lstat(fpath, &stat) == -1)
		return (-1);
	if (!*lst)
		*lst = new_nod(fpath, name, &stat);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = new_nod(fpath, name, &stat);
	}
	return (1);
}
