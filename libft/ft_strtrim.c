/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:24:44 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/14 08:57:30 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skipset(const char *set, int c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen((char *)s1) - 1;
	k = 0;
	while (ft_skipset(set, s1[i]) == 1)
	{
		i++;
	}
	while (j > i && ft_skipset(set, s1[j]) == 1)
	{
		j--;
	}
	p = malloc(j - i + 2);
	if (p == NULL)
		return (NULL);
	while (i <= j)
	{
		p[k++] = s1[i++];
	}
	p[k] = '\0';
	return (p);
}

// int main(){
// 	char string1[] = "Hello World Hello";
// 	char string2[] = "Hello ";
// 	char *string3 = ft_strtrim(string1, string2);
// 	printf("%s", string3);
// 	return (0);
// }