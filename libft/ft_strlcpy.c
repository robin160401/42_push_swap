/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:57 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/13 12:56:41 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char				*rsrc;
	size_t				src_len;
	size_t				i;

	rsrc = (char *)src;
	src_len = ft_strlen(rsrc);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int main(){
//     char stringDst[] = "";
//     char stringSrc[] = "Hello World";

//     size_t len = ft_strlcpy(stringDst, stringSrc, 12);
//     // size_t len = ft_strlcat(stringDst, stringSrc, 5);
//     // size_t len = ft_strlcat(stringDst, stringSrc, 0);
//     printf("%s\n", stringDst);
//     printf("%zu\n", len);
// }