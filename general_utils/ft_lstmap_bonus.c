/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:37 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/20 16:35:26 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*current;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	current = lst;
	new_lst = NULL;
	while (current)
	{
		new_content = f(current->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			if (!del)
				return (NULL);
			ft_lstclear(&new_lst, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		current = current->next;
	}
	return (new_lst);
}
