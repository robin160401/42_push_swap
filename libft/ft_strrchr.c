/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:38:12 by rstumpf           #+#    #+#             */
/*   Updated: 2024/11/02 14:04:15 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	ft_countletters(const char *s, int c)
{
	int	i;
	int	count1;

	count1 = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			count1 ++;
		}
		i++;
	}
	return (count1);
}

char	*ft_strrchr(const char *s, int c)
{
	int	count1;
	int	count2;

	if ((char)c == '\0')
	{
		while (*s)
		{
			s++;
		}
		return ((char *)s);
	}
	count1 = ft_countletters(s, c);
	if (count1 == 0)
		return (NULL);
	count2 = 0;
	while (*s)
	{
		if (*s == (char)c)
			count2 ++;
		if (count2 == count1)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
int main() {
    const char *str = "Hello, World!";

    char *result = ft_strrchr(str, 'o');

    printf("%s",result);

    return 0;
}