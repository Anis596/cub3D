/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:12 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 15:02:33 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	*del(void *content)
// {
// 	free(content);
// 	return (NULL);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	char	*str1 = "1";
// 	char	*str2 = "2";
// 	char	*str3 = "3";
// 	lst = ft_lstnew(str1);
// 	lst->next = ft_lstnew(str2);
// 	lst->next->next = ft_lstnew(str3);
// 	t_list	*tmp = lst;
// 	while (tmp)
// 	{
// 		printf ("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf ("---\n");
// 	ft_lstdelone(lst->next, free);
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf ("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
