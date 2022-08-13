/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:37:32 by snino             #+#    #+#             */
/*   Updated: 2022/08/10 17:37:46 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s, int c)
{
	char    *copy;
	size_t  i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (!(copy = malloc(sizeof(char) * i + 1)))
		return (NULL);
	copy[i] = '\0';
	while (i-- > 0)
		copy[i] = s[i];
	return (copy);
}
