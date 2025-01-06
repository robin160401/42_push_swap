/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:29:06 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/13 12:56:49 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char    to_upper(unsigned int i, char c)
// {
//     if (i % 2 == 0)
//         return (c - 32);
//     return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int main(void)
// {
//     char string[] = "Hello World";
// 	char *result = ft_strmapi(string, to_upper);
// 	printf("%s", result);
//     return 0;
// }