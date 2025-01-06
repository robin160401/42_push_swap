/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:27:22 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/15 18:23:51 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_handlenullcase(char *p)
{
	*p = '0';
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;
	long	longn;

	longn = n;
	len = ft_findlen(longn);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (longn < 0)
	{
		p[0] = '-';
		longn *= -1;
	}
	if (n == 0)
		return (ft_handlenullcase(p));
	while (longn > 0)
	{
		p[--len] = (longn % 10) + '0';
		longn /= 10;
	}
	return (p);
}

// int main() {
//     printf("%s\n", ft_itoa(0));
// }
