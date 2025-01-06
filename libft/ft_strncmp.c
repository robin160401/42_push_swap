/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:38:03 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/13 16:50:15 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*us1;
	unsigned char		*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] && us2[i] && i < n)
	{
		if (us1[i] != s2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (us1[i] - us2[i]);
}

// int main() {
//     const char *str1 = "Test\200";
//     const char *str2 = "Test\0";

//     int result = ft_strncmp(str1, str2,6);

//     printf("%d", result);

//     return 0;
// }