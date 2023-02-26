/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:40:12 by seryilma          #+#    #+#             */
/*   Updated: 2022/02/23 18:40:21 by seryilma         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strs;
	size_t	strlen;

	if (len <= 0)
		return(" ");
	if (s == NULL)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		strs = (char *)malloc((len + 1) * sizeof(char));
	else
		strs = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (strs == NULL)
		return (NULL);
	ft_strlcpy(strs, (s + start), (len + 1));
	return (strs);
}
//  int main()
//  {
//      char halil[] = "halil deneme kopyala";
//      printf("%s", ft_substr(halil, 6,11));
//  }
