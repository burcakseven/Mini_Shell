/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:02:28 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/23 16:44:20 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if ((!dst && !src) || !len)
		return (dst);
	ptr_dest = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (len--)
		*ptr_dest++ = *ptr_src++;
	return (dst);
}
