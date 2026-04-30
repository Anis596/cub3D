/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:02:53 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 16:25:25 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// void	*f(void *content)
// {
// 	printf("%s\n", (char *)content);
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
// 	ft_lstiter(lst, f);
// 	return (0);
// }