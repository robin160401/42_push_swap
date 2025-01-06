/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:30:27 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/15 15:02:05 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	unsigned int	malloc_len;

	malloc_len = 0;
	slen = (unsigned int)ft_strlen(s);
	if (start >= slen)
		malloc_len = 0;
	else if (len < slen - start)
		malloc_len = len;
	else
		malloc_len = slen - start;
	return (malloc_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*p;
	size_t			strlen;

	i = 0;
	j = 0;
	strlen = getlen(s, start, len);
	p = (char *)malloc((strlen + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i] && i < start)
		i++;
	while (len > 0 && s[i] != '\0')
	{
		p[j] = s[i];
		i++;
		j++;
		len--;
	}
	p[j] = '\0';
	return (p);
}
// int main(){
// 	char string[] = "Hello World";
// 	printf("%s", ft_substr(string, 90, 1));
// 	return (0);
// }
