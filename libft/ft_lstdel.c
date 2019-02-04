/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:17:54 by mpytienk          #+#    #+#             */
/*   Updated: 2017/11/02 11:17:59 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*atmp;
	t_list	*tmp;

	atmp = *alst;
	tmp = (*alst)->next;
	while (tmp != NULL)
	{
		ft_lstdelone(&atmp, del);
		atmp = tmp;
		tmp = tmp->next;
	}
	ft_lstdelone(&atmp, del);
	*alst = NULL;
}
