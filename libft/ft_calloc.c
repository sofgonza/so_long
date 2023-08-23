/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:16:53 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/28 15:51:58 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;

	mem = malloc (count * size);
	if (mem != NULL)
	{
		ft_bzero(mem, (size * count));
		return (mem);
	}
	return (NULL);
}
/*
int	main(void)
{
	size_t	count;
	size_t	size;

	count = 20;
	size = sizeof(char *);
	ft_calloc(count, size);
}
*/
