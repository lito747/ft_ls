/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:28:01 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/15 12:28:06 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ascend_name(t_file *a, t_file *b)
{
	if (ft_strcmp(a->name, b->name) > 0)
		return (1);
	return (0);
}

int	descending_name(t_file *a, t_file *b)
{
	if (ft_strcmp(a->name, b->name) < 0)
		return (1);
	return (0);
}

int	ascend_time(t_file *a, t_file *b)
{
	int i;

	i = 0;
	if (a->time == b->time)
		i = ascend_name(a, b);
	if (a->time < b->time)
		return (1);
	return (i);
}

int	descending_time(t_file *a, t_file *b)
{
	int i;

	i = 0;
	if (a->time == b->time)
		i = descending_name(a, b);
	if (a->time > b->time)
		return (1);
	return (i);
}
