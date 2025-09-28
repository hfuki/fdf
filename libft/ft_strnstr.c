/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:16:17 by hfuki             #+#    #+#             */
/*   Updated: 2025/04/29 15:51:51 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const unsigned char	*ptrhay;
	const unsigned char	*ptrnee;
	size_t				i;
	size_t				j;

	ptrhay = (const unsigned char *)haystack;
	ptrnee = (const unsigned char *)needle;
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (ptrhay[i] && i < len)
	{
		j = 0;
		while (ptrhay[i + j] == ptrnee[j] && (i + j) < len)
		{
			if (!ptrnee[j + 1])
				return ((char *)(ptrhay + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
