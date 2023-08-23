/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:21:22 by sofgonza          #+#    #+#             */
/*   Updated: 2023/03/28 16:08:12 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
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

	printf("last = %p\nlstlast = %p", n2, ft_lstlast(head));
	//system("leaks a.out");
}*/