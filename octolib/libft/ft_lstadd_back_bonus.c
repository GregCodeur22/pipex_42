/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garside <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:55:42 by garside           #+#    #+#             */
/*   Updated: 2024/10/24 18:09:14 by garside          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current -> next != NULL)
	{
		current = current -> next;
	}
	current -> next = new;
}
