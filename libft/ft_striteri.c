/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:03:42 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/12 12:13:44 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	while (*s)
	{
		f(i, *&s);
		s++;
		i++;
	}
}

// int main(void)
// {
//     char string[] = "Hello World";
// 	ft_striteri(string, to_uppercase);
// 	printf("%s", string);
//     return 0;
// }
