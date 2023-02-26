/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:57:06 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/23 23:26:18 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dst == NULL)
		return (0);
	if (dst)
		dst = ft_memcpy(dst, s1, ft_strlen(s1));
	dst[ft_strlen(s1)] = '\0';
	return (dst);
}
