/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:27 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/11 12:49:58 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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