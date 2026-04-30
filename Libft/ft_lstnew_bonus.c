/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:37:30 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/16 12:48:32 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*jcrochet;

	jcrochet = (t_list *)malloc(sizeof(t_list));
	if (!jcrochet)
		return (NULL);
	jcrochet->content = content;
	jcrochet->next = NULL;
	return (jcrochet);
}

// int	main(void)
// {
// 	t_list	*new;
// 	char	*str = "tu crois t un lion";
// 	new = ft_lstnew(str);
// 	printf ("%s\n", (char *)new->content);
// 	return (0);
// }