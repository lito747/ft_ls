/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:42:13 by mpytienk          #+#    #+#             */
/*   Updated: 2017/11/01 16:42:41 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int d)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2", d);
		ft_putnbr_fd(147483648, d);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', d);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, d);
		ft_putnbr_fd(n % 10, d);
	}
	else
		ft_putchar_fd(n + '0', d);
}
