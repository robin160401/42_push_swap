/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:55 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/13 12:56:30 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copie(size_t dstsize, size_t dst_len, char *src, char *dst)
{
	size_t	i;
	size_t	remaining;

	i = 0;
	remaining = dstsize - dst_len - 1;
	while (i < remaining && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*rdst;
	char		*rsrc;
	size_t		dst_len;
	size_t		src_len;

	rdst = (char *)dst;
	rsrc = (char *)src;
	dst_len = ft_strlen(rdst);
	src_len = ft_strlen(rsrc);
	if (dstsize == 0)
		return (src_len);
	if (dst_len > dstsize - 1)
		return (dstsize + src_len);
	ft_copie(dstsize, dst_len, rsrc, rdst);
	return (dst_len + src_len);
}

// int main(){
//     char stringDst[] = "Hello";
//     char stringSrc[] = " World";

//     size_t len = ft_strlcat(stringDst, stringSrc, 0);
//     // size_t len = ft_strlcat(stringDst, stringSrc, 5);
//     // size_t len = ft_strlcat(stringDst, stringSrc, 0);
//     printf("%s\n", stringDst);
//     printf("%zu\n", len);
// }