/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:58:20 by hfuki             #+#    #+#             */
/*   Updated: 2025/09/27 23:30:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_rem_clear(char **prem, char *buf)
{
	char	*line;

	free(buf);
	line = *prem;
	*prem = NULL;
	return (line);
}

char	*check_rem(char **orem, char *nl, char *buf)
{
	char	*tmp;
	size_t	len;
	char	*nrem;

	free(buf);
	len = nl - *orem + 1;
	tmp = ft_strndup(*orem, len);
	nrem = ft_strdup(nl + 1);
	free(*orem);
	*orem = nrem;
	return (tmp);
}

char	*fin_gnl(char **rem, char *buf)
{
	free(buf);
	if (*rem)
		free(*rem);
	*rem = NULL;
	return (NULL);
}

char	*read_manage_rem(char **rem, char *buf, int fd)
{
	char	*nl;
	char	*tmp;
	ssize_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(*rem, buf);
		free(*rem);
		*rem = tmp;
		nl = ft_strchr(*rem, '\n');
		if (nl)
			return (check_rem(rem, nl, buf));
		n = read(fd, buf, BUFFER_SIZE);
	}
	if (n < 0)
		return (fin_gnl(rem, buf));
	if (n == 0 && (*rem)[0] != '\0')
		return (return_rem_clear(rem, buf));
	return (fin_gnl(rem, buf));
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buf;
	char		*line;
	char		*nl;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!rem)
	{
		rem = ft_strdup("");
		if (rem == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	nl = ft_strchr(rem, '\n');
	if (nl)
		return (check_rem(&rem, nl, buf));
	line = read_manage_rem(&rem, buf, fd);
	return (line);
}
