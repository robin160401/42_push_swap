/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:15 by rstumpf           #+#    #+#             */
/*   Updated: 2025/01/30 12:05:49 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9') || c == '-')
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