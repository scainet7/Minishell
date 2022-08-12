/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:51:55 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 20:54:45 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getword(const char *s, char delim)
{
	int		word_length;
	char	*str;

	word_length = 0;
	while (s[word_length] != '\0' && s[word_length] != delim)
	{
		word_length++;
	}
	str = ft_substr(s, 0, word_length);
	if (str)
	{
		return (str);
	}
	return (NULL);
}
