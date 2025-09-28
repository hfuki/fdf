/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:19:11 by hfuki             #+#    #+#             */
/*   Updated: 2025/04/30 22:24:18 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lsame;

	lsame = NULL;
	while (*s)
	{
		if (*s == (char)c)
			lsame = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)lsame);
}
