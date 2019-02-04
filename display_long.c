/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:06:14 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/16 14:06:17 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_file_type(int mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static char		get_file_acl(char *path)
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

static void		display_chmod(int mode, char *path)
{
	char chmod[12];

	chmod[0] = get_file_type(mode);
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[10] = get_file_acl(path);
	chmod[11] = '\0';
	strspc(chmod, 1);
}

void			long_form(t_mylist *tmp, t_mylist *lst, int flag)
{
	if (flag & LS_S)
		put_indent_number(tmp->cont->lblocks, lst->cont->blocks);
	display_chmod(lst->cont->mode, lst->cont->full_path);
	put_indent_number(tmp->cont->llink, lst->cont->nbr_link);
	put_indent_str(getpwuid(lst->cont->user_id)->pw_name, tmp->cont->luname);
	if (!(flag & LS_O))
		put_indent_str(getgrgid(lst->cont->group_id)->gr_name,
			tmp->cont->lgname);
	put_indent_number(tmp->cont->lsize, lst->cont->size);
	display_time(lst->cont->time);
	ft_putstr(lst->cont->name);
	if (S_ISLNK(lst->cont->mode))
		read_link(lst->cont);
	ft_putchar('\n');
}
