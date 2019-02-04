/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_misc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:12:42 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/17 11:12:44 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		read_link(t_file *nod)
{
	char	*buf;
	ssize_t	nbytes;
	ssize_t	bufsiz;

	bufsiz = nod->size;
	if (nod->size == 0)
		bufsiz = PATH_MAX;
	buf = (char *)ft_strnew(bufsiz);
	if (buf == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nbytes = readlink(nod->full_path, buf, bufsiz);
	ft_putstr(" -> ");
	ft_putstr(buf);
	ft_strdel(&buf);
}

void		put_indent_str(char *str, int len)
{
	int vallen;

	vallen = ft_strlen(str) - 1;
	ft_putstr(str);
	putnchr((len - vallen), ' ');
}

static void	display_year(char *str)
{
	char	*tmp;

	tmp = ft_strsub(str, 4, 7);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	ft_putchar(' ');
	tmp = ft_strsub(str, 20, 4);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	ft_putchar(' ');
}

void		display_time(time_t date)
{
	char	*str1;
	time_t	current_time;

	current_time = time(NULL);
	str1 = ctime(&date);
	if ((current_time - SIX_M) > date)
		display_year(str1);
	else
	{
		str1 = ft_strsub(str1, 4, 12);
		str1[12] = '\0';
		ft_putstr(str1);
		ft_putchar(' ');
		free(str1);
	}
}
