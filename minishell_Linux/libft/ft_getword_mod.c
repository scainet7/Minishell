/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:05:33 by snino             #+#    #+#             */
/*   Updated: 2022/08/13 14:37:07 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getword_mod(const char *s, char delim)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[++i] != delim)
		;
	buff = (char *)malloc(i);
	i = -1;
	while (s[++j] != delim)
		buff[++i] = s[j];
	buff[++i] = '\0';
	return (buff);
}
