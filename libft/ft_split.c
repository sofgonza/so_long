/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:00:31 by sofgonza          #+#    #+#             */
/*   Updated: 2023/08/04 15:33:49 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	w_count(char const *s, char c)
{
	unsigned int	wc;
	unsigned int	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (i == 0 && s[i] != c))
			++wc;
		++i;
	}
	return (wc);
}

static int	w_len(char const *s, char c, unsigned int i)
{
	unsigned int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		++len;
		++i;
	}
	return (len);
}

static void	str_free(char **str)
{
	unsigned int	j;

	j = 0;
	while (str[j])
	{
		free (str[j]);
		++j;
	}
	free (str);
}

static char	**ft_place(char const *s, char c, char **str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, (w_len(s, c, i)));
			if (str[j] == NULL)
			{
				str_free(str);
				return (NULL);
			}
			j++;
			i = i + (w_len(s, c, i));
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**str;

	if (!s || !ft_isascii(c))
		return (NULL);
	str = ft_calloc (w_count(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	return (ft_place(s, c, str));
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "lorem isus. Suspendisse";
	char c = ' ';
	int	i = 0;
	char **s = ft_split(str, c);
	while (s[i])
	{
		printf("str[%d]=%s\n", i, s[i]);
		i++;
	}
	printf("str[%d]=%s\n", i, s[i]);
	return (0);
}*/
