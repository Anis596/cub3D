/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:57:27 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 14:14:37 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new;
// 	char	*str1 = "1";
// 	char	*str2 = "2";
// 	lst = ft_lstnew(str1);
// 	new = ft_lstnew(str2);
// 	ft_lstadd_front(&lst, new);
// 	printf ("%s\n", (char *)lst->content);
// 	printf ("%s\n", (char *)lst->next->content);
// 	return (0);
// }
