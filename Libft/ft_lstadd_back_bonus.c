/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:32:33 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 14:53:42 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

// int	main(void)
// {
// 	t_list	*lst = NULL;
// 	t_list	*new;
// 	char	*str1 = "1";
// 	char	*str2 = "2";
// 	char	*str3 = "3";
// 	char	*str4 = "4";
// 	lst = ft_lstnew(str1);
// 	new = ft_lstnew(str2);
// 	ft_lstadd_back(&lst, new);
// 	new = ft_lstnew(str3);
// 	ft_lstadd_back(&lst, new);
// 	new = ft_lstnew(str4);
// 	ft_lstadd_back(&lst, new);
// 	t_list	*tmp = lst;
// 	while (tmp)
// 	{
// 		printf ("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
