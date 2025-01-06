/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:37:12 by rstumpf           #+#    #+#             */
/*   Updated: 2024/10/23 20:48:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	char	*allocate_memory;

	total_size = count * size;
	allocate_memory = (char *)malloc(total_size);
	if (allocate_memory == NULL)
	{
		return (NULL);
	}
	ft_memset(allocate_memory, 0, total_size);
	return (allocate_memory);
}

// int main() {
//     int *arr = (int *)ft_calloc(5, sizeof(int));
//     char *arr2 = (char *)ft_calloc(5, sizeof(char));
//     int i = 0;
//     while(i < 5){
//         printf("arr1: ");
//         printf("%d\n", arr[i]);
//         printf("arr2: ");
//         printf("%d\n", arr2[i]);
//         i++;
//     }
//     free(arr);
//     free(arr2);

//     return (0);
// }