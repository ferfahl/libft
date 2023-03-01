/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:33:14 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 20:12:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
*@brief returns a pointer to a new string which is a duplicate of the string src
*this string is counted until the \0
*Memory for the new string is obtained with malloc, and can be freed with free
*@param s String to be duplicated
*@return Pointer to the duplicated string, or NULL if insufficient memory was
*available
*/
char	*ft_strdup_mod(const char *src)
{
	char	*duplicate;
	int		count;

	count = 0;
	duplicate = malloc(ft_strlen_mod(src, '\0', 0) * sizeof(*duplicate) + 1);
	if (!duplicate)
		return (NULL);
	while (*src)
		duplicate[count++] = *src++;
	duplicate[count] = '\0';
	return (duplicate);
}

/**
*@brief fills the first 'n' bytes of the memory area ponted to by 's' with the
*constant byte 'c' until the end or the \0
*@param s String to be traversed.
*@return Number of bytes in the string pointed to by 's'.
*/
size_t	ft_strlen_mod(const char *src, char a, size_t count)
{
	size_t	size;

	size = 0;
	while (src && src[count] != a && src[count] != '\0')
	{
		count++;
		size++;
	}
	return (size);
}

/**
*@brief Copy strings and is designed to be safer, more consistent, and less
*error prone replacement for strncpy(). Unlike strncpy(), strlcpy() take the
*full size of the buffer (not just the length) and guarantee to NUL-terminate
*the result (as long as size is larger than 0). Note that a byte for the NUL
*should be included in 'size'. Also note that strlcpy() only operate on true “C”
*strings. This means that 'src' must be NUL-terminated.
*the modified version checks for different types of char on the string
*@param dest Pointer to the destination string.
*@param src Pointer to the source string.
*@param a The char to be compared with
*@param index location of the string to be copied
*@return Total length of the created string.
*/
void	ft_strlcpy_mod(char *dest, const char *src, char a, size_t index)
{
	size_t	count;

	count = 0;
	while (src && src[index] != a && src[index] != '\0')
	{
		dest[count] = src[index];
		count++;
		index++;
	}
	dest[count] = 0;
}

/**
*@brief returns a new string, which is the result of the concatenation of ’s1’
*and ’s2’.
*@param s1: The prefix string
*@param s2: The suffix string.
*@return the new string, NULL if the allocation fails
*/
char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*new_str;
	ssize_t	len_total;
	ssize_t	len_s1;
	ssize_t	len_s2;

	len_s1 = -1;
	len_s2 = 0;
	if (!s1)
	{
		new_str = malloc(ft_strlen_mod(s2, '\0', 0) + 1);
		if (!new_str)
			return (NULL);
		ft_strlcpy_mod(new_str, s2, '\0', len_s2);
		return (new_str);
	}
	len_total = (ft_strlen_mod(s1, '\0', 0) + ft_strlen_mod(s2, '\0', 0)) + 1;
	new_str = malloc (len_total);
	if (!new_str)
		return (NULL);
	while (s1 && s1[++len_s1])
		new_str[len_s1] = s1[len_s1];
	while (s2 && s2[len_s2])
		new_str[len_s1++] = s2[len_s2++];
	new_str[len_s1] = '\0';
	return (new_str);
}
