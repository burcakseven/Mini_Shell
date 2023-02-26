/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:32:26 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/23 14:44:42 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;
	int		check;

	check = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			ch = (char *)s;
			++check;
		}
		++s;
	}
	if (check > 0)
		return (ch);
	else if (c == '\0')
		return ((char *)s);
	return (0);
}
