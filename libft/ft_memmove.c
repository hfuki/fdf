/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:52:29 by hfuki             #+#    #+#             */
/*   Updated: 2025/04/28 19:21:49 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (s == d || len == 0)
		return (dst);
	if (s > d)
	{
		while (len--)
			*d++ = *s++;
		return (dst);
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
		return (dst);
	}
}
