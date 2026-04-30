/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:03:11 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/15 08:13:49 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		num;
	char	*str;

	num = count_num(n);
	str = (char *)malloc(sizeof(char) * (num + 1));
	if (!str)
		return (NULL);
	str[num] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		num--;
		if (n > 0)
			str[num] = (n % 10) + '0';
		else
			str[num] = -(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

// int main(void)
// {
// 	int n = -2147483648;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }
