/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:35:03 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/24 01:35:16 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bas;
	size_t	son;

	if (!s1 || !set)
		return (NULL);
	bas = 0;
	while (ft_strchr(set, s1[bas]) && s1[bas] != '\0')
		bas++;
	son = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[son]) && son != 0)
		son--;
	if ((int)(son - bas + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, bas, (son - bas + 1)));
}
