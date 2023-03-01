/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:06:07 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 15:29:21 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief fills the first 'n' bytes of the memory area ponted to by 's' with the
*char 'a'
*@param s String to be traversed.
*@param a character to be compared
*@return Number of bytes in the string pointed to by 's'.
*/
size_t	ft_strlen_char(const char *str, char a)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != a)
	{
		count++;
	}
	return (count);
}
