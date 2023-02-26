/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:43:47 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/23 23:19:46 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long int	nbr;
	int			is_minus;

	nbr = 0;
	is_minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0') * is_minus;
		str++;
		if (nbr > 2147483647)
			return (-1);
		if (nbr < -2147483648)
			return (0);
	}
	return (nbr);
}
