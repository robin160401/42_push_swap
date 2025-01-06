/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:24 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/11 12:49:55 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main() {
//     char test1 = 'A';
//     char test2 = 'z';
//     char test3 = '1';

//     printf("%d\n", ft_isdigit(test1));
//     printf("%d\n", ft_isdigit(test2));
//     printf("%d\n", ft_isdigit(test3));

//     return (0);
// }