/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 22:08:35 by amagomad          #+#    #+#             */
/*   Updated: 2024/05/17 17:59:29 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;

	addr = (unsigned long long)ptr;
	count = 0;
	if (!ptr)
	{
		count += ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count += ft_putstr_fd("0x", fd);
	count += ft_puthex_fd(addr, fd, 0);
	return (count);
}
