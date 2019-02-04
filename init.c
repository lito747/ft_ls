/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:06:59 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/11 14:07:04 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_mylist		*init_lst(char **tab, int ac)
{
	int			i;
	t_mylist	*file;

	i = 0;
	file = NULL;
	if (ac == 0)
		lst_add("", ".", &file);
	while (i < ac)
	{
		if (lst_add("", tab[i], &file) == -1)
			display_errno(tab[i]);
		i++;
	}
	return (file);
}
