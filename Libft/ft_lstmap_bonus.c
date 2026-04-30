/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:05:26 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/18 22:12:41 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*elem;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_lstclear(&newlist, del), free(content), NULL);
		elem = ft_lstnew(content);
		if (!elem)
			return (ft_lstclear(&newlist, del), free(content), NULL);
		ft_lstadd_back(&newlist, elem);
		lst = lst->next;
	}
	return (newlist);
}

// void	*f(void *content)
// {
// 	char	*str;	
// 	int		i;

// 	str = (char *)content;
// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = str[i] - 32;
// 		i++;
// 	}
// 	return (str);
// }

// void	*del(void *content)
// {
// 	free(content);
// 	return (NULL);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	char	*str1 = strdup("qqq");
// 	char	*str2 = strdup("www");
// 	char	*str3 = strdup("eee");
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
// 	t_list	*new_lst = ft_lstmap(lst, f, (void *)del);
// 	tmp = new_lst;
// 	while (tmp)
// 	{
// 		printf ("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&lst, free);
// 	ft_lstclear(&new_lst, free);
// 	return (0);
// }