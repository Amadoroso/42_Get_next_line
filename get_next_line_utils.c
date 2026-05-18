/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:32:44 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/18 20:24:23 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1_s2;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
	{
		return (NULL);
		free(s1);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s1_s2 = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (s1_s2 == 0)
		return (NULL);
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

size_t	ft_new_line_check(char *acc, ssize_t BUF_SIZE, ssize_t cycle)
{
	ssize_t	start;
	ssize_t	end;
	
	end = BUF_SIZE * cycle;
	start = BUF_SIZE * (cycle - 1);
	while (start < end && start >= 0)
	{
		if (*(acc + start) == '\n' || *(acc + start) == 0)
			return (1);
		start++;
	}
	return (start);
}

char	*ft_strtrim_mod(char *s1)
{
	size_t	end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[end] != '\n' || s1[end] != 0)
		end--;
	if (end < 0)
		return (NULL);
	result = malloc((end + 1) * sizeof(char));
	if (result == 0)
		return (NULL);
	free(s1);
	ft_strlcpy(result, s1, end);
	return (result);
}
