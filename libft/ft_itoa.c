/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:53:25 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/23 16:53:33 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	else if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*dizi;
	int		i;

	nb = n;
	i = len(nb);
	dizi = (char *)malloc(sizeof(char) * (len(nb) + 1));
	if (!dizi)
		return (NULL);
	dizi[i--] = '\0';
	if (nb == 0)
		dizi[0] = '0';
	if (nb < 0)
	{
		dizi[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		dizi[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (dizi);
}
