/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:49:03 by feralves          #+#    #+#             */
/*   Updated: 2023/03/01 12:55:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
*@brief reads the given fd according to the size of BUFFER
*@param fd: The file descriptor to read from
*@return the line read
*/
char	*ft_read(int fd)
{
	char	*the_reader;
	char	*line_read;
	char	*temp;
	ssize_t	buffer;

	the_reader = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!the_reader)
		return (NULL);
	buffer = read(fd, the_reader, BUFFER_SIZE);
	if (buffer == -1)
		return (free(the_reader), NULL);
	line_read = ft_strdup_mod("");
	while (buffer > 0)
	{
		the_reader[buffer] = '\0';
		temp = ft_strjoin(line_read, the_reader);
		free(line_read);
		line_read = temp;
		if (ft_strchr(line_read, '\n'))
			break ;
		buffer = read(fd, the_reader, BUFFER_SIZE);
	}
	return (free(the_reader), line_read);
}

/**
*@brief splits the line given when encounters an ending (\n or \0)
*@param aux_temp a temporary line read that will be splited
*@param overrrun a line of static size that stores the rest of the line splitted
*@return the splitted line
*/
char	*ft_split_line(char *aux_temp, char **overrun)
{
	char	*dest;
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen_mod(aux_temp, '\n', index);
	dest = malloc((len + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy_mod(dest, aux_temp, '\n', index);
	index = len;
	if (aux_temp[index] != '\0')
	{
		len = ft_strlen_mod(aux_temp, '\0', index);
		*overrun = malloc((len + 1) * sizeof(char));
		if (!*overrun)
			return (NULL);
		ft_strlcpy_mod(*overrun, aux_temp, '\0', index + 1);
		overrun[0][len] = '\0';
	}
	dest[index] = '\n';
	index++;
	dest[index] = '\0';
	return (dest);
}

/**
*@brief the main function that the gnl function calls to
*@param fd: The file descriptor to read from
*@return Read line: correct behavior; NULL: there is nothing else to read, or
*an error occurred
*/
char	*ft_return_line(int fd)
{
	char		*line_read;
	char		*aux_temp;
	char		*dest;
	static char	*overrun[1024];

	if (!overrun[fd])
		overrun[fd] = ft_strdup_mod("");
	line_read = ft_read(fd);
	aux_temp = ft_strjoin((char *)overrun[fd], line_read);
	free(line_read);
	line_read = NULL;
	free(overrun[fd]);
	overrun[fd] = NULL;
	if (ft_strchr(aux_temp, '\n'))
		dest = ft_split_line(aux_temp, &overrun[fd]);
	else if (*aux_temp)
		return (aux_temp);
	else
		return (free(aux_temp), NULL);
	return (free(aux_temp), dest);
}

/**
*@brief function that returns a line read from a file descriptor
*@param fd: The file descriptor to read from
*@return Read line: correct behavior; NULL: there is nothing else to read, or
*an error occurred
*/
char	*get_next_line(int fd)
{
	char	*dest;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 999)
		return (NULL);
	dest = ft_return_line(fd);
	return (dest);
}
