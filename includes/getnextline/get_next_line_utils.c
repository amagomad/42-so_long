/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:05:20 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/24 15:36:47 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s1, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s1)[i] = '\0';
		i++;
	}
}

char	*ft_strcpyv2(char *s1, char *s2, char *s3)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (s3[j])
	{
		s1[i] = s3[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	free (s2);
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!str)
		return (NULL);
	return (ft_strcpyv2(str, s1, s2));
}

char	*ft_strncpy(char *str, char *s2, char c)
{
	int	i;
	int	chr;

	i = 0;
	chr = 0;
	while (s2[chr] && s2[chr] != c)
		chr++;
	if (ft_strlenn(s2) == chr)
		return (NULL);
	chr++;
	while (s2[chr])
	{
		str[i] = s2[chr];
		chr++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_split(char *tab, char c)
{
	int		a;
	int		chr;
	char	*str;

	a = 0;
	chr = 0;
	if (ft_strchr(tab, c) == NULL)
		return (tab);
	while (tab[chr] != c)
		chr++;
	str = malloc(sizeof(char) * (chr + 2));
	while (a < chr)
	{
		str[a] = tab[a];
		a++;
	}
	str[a] = tab[a];
	a++;
	free (tab);
	str[a] = '\0';
	return (str);
}
