/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:46:55 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 16:02:19 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_of_nb(int nb)
{
	int		count;

	count = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		count = 2;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
