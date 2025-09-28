/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:50:31 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/01 17:39:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*atrim;
	size_t	start;
	size_t	end;
	size_t	i;

	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[end])
		end++;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	atrim = (char *) malloc ((end - start + 1) * sizeof(char));
	if (!atrim)
		return (NULL);
	i = 0;
	while (start < end)
		atrim[i++] = s1[start++];
	atrim[i] = '\0';
	return (atrim);
}
