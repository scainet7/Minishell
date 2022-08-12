/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:02:49 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 21:03:00 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *str, char delim)
{
	int in_word;
	int num_words;
	int i;

	in_word = 0;
	num_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			i++;
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
				num_words++;
			}
			i++;
		}
	}
	return (num_words);
}
