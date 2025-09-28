/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:50:08 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/02 11:13:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	num_cou(long n)
{
	size_t	od;

	od = 0;
	if (n < 0)
	{
		n *= -1;
		od++;
	}
	if (n == 0)
		od = 1;
	while (n > 0)
	{
		n /= 10;
		od++;
	}
	return (od);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	od;
	long	ln;

	ln = (long)n;
	od = num_cou(ln);
	num = (char *) malloc ((od + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[od] = '\0';
	if (ln < 0)
	{
		num[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
		num[0] = '0';
	while (ln > 0)
	{
		num[--od] = ln % 10 + '0';
		ln /= 10;
	}
	return (num);
}
