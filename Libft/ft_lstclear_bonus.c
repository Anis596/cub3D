/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:02:52 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/17 20:26:35 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

// void	*del(void *content)
// {
// 	free(content);
// 	return (NULL);
// }

// int	main(void)
// {
// 	t_list	*lst = NULL;
// 	t_list	*new;
// 	char	*str1 = strdup("1");
// 	char	*str2 = strdup("2");
// 	char	*str3 = strdup("3");
// 	char	*str4 = strdup("4");
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
// 	printf ("---\n");
// 	ft_lstclear(&lst, free);
// 	if (lst == NULL)
// 		printf ("lst is NULL\n");
// 	else
// 		printf ("lst is not NULL\n");
// 	return (0);
// }	
