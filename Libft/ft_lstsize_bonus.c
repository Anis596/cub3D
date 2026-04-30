/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:15:44 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 14:25:02 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// int	main(void)
// {
// 	t_list	*lst = NULL;
// 	char	*str1 = "1";
// 	char	*str2 = "2";
// 	char	*str3 = "3";
// 	char	*str4 = "4";

// 	lst = ft_lstnew(str1);
// 	lst->next = ft_lstnew(str2);
// 	lst->next->next = ft_lstnew(str3);
// 	lst->next->next->next = ft_lstnew(str4);
// 	printf ("%d\n", ft_lstsize(lst));
// 	return (0);
// }
