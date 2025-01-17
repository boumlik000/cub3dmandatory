/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:17:19 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 23:11:09 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_lstdelone_collec(t_colec *lst)
{
	if (!lst)
		return ;
	free(lst->ptr);
	lst->ptr = NULL;
	free(lst);
	lst = NULL;
}

void	ft_lstclear_collec(t_colec **lst)
{
	t_colec	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_collec(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_colec	*ft_lstlast_collec(t_colec *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_collec(t_colec **lst, t_colec *new)
{
	t_colec	*ptr_node;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		ptr_node = ft_lstlast_collec(*lst);
		ptr_node->next = new;
	}
	else
		*lst = new;
}

void	ft_collectore(t_colec **list_head, void *ptr, char *str)
{
	t_colec	*node;
	t_colec	*head;

	(void)str;
	if (ptr == NULL)
	{
		write(2, "Error In Game\n", 15);
		ft_lstclear_collec(list_head);
	}
	head = malloc(sizeof(t_colec));
	if (!head)
	{
		write(2, "Error In Game\n", 15);
		ft_lstclear_collec(list_head);
		exit(1);
	}
	head->ptr = ptr;
	head->next = NULL;
	node = head;
	ft_lstadd_back_collec(list_head, node);
}
