/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:25:30 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 16:17:53 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	char	*str = "0";
// 	char	*str1 = "1";
// 	char	*str2 = "2";

// 	lst = ft_lstnew(str);
// 	lst->next = ft_lstnew(str1);
// 	lst->next->next = ft_lstnew(str2);
// 	printf ("%s\n", (char *)ft_lstlast(lst)->content);
// 	return (0);
// }
