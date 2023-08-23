/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:01:07 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/07 12:13:35 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nl;

	nl = ft_calloc (1, sizeof(*nl));
	if (!nl)
		return (NULL);
	nl->content = content;
	nl->next = NULL;
	return (nl);
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

	printf("head = %c\nn1 = %c\nn2 = %c\n", (char)head->content,
		(char)n1->content, (char)n2->content);
	//system("leaks a.out");
}*/
