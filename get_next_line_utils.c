/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:32:44 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/16 00:40:39 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_s2;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s1_s2 = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!s1_s2)
		return (NULL);
	*(s1_s2 + len1 + len2) = 0;
	ft_strlcpy(s1_s2, s1, len1 + 1);
	ft_strlcpy(s1_s2 + len1, s2, len2 + 1);
	free(s1);
	return (s1_s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	len = 0;
	while (*(src + len))
		len++;
	if (size == 0)
		return (len);
	index = 0;
	while (index < (size - 1) && *src)
	{
		*dst++ = *src++;
		index++;
	}
	*dst = 0;
	return (len);
}

char	*ft_strdup_mod(const char *s)
{
	char			*dup;
	unsigned int	index;

	dup = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == 0)
		return (NULL);
	index = 0;
	while (*s)
	{
		*(dup + index) = *s;
		s++;
		index++;
	}
	*(dup + index) = 0;
	return (dup);
}

size_t	ft_new_line_check(char *acc, ssize_t start, ssize_t read_rtrn)
{	
	while (start < start + read_rtrn)
	{
		if (*(acc + start) == '\n' || *(acc + start) == 0)
			return (1);
		start++;
	}
	return (0);
}
