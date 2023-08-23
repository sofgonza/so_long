/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:11:30 by sofgonza          #+#    #+#             */
/*   Updated: 2023/03/28 16:09:27 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *head = ft_lstnew((void *) 'a');
	t_list *n1= ft_lstnew((void *) 'b');
	t_list *n2 = ft_lstnew((void *) 'c');

	head->next = n1;
	n1->next = n2;

	printf("lstsize = %d\n", ft_lstsize(head));
	//system("leaks a.out");
}
*/