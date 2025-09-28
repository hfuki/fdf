/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:50:27 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/01 13:40:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;
	size_t	i;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	join = (char *) malloc ((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (i < len1)
		join[i++] = *s1++;
	while (i < len1 + len2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
