/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:32:44 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/25 18:10:19 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1_s2;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1, 0);
	len2 = ft_strlen(s2, 0);
	s1_s2 = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (s1_s2 == 0)
		return (NULL);
	ft_strlcpy(s1_s2, s1, len1 + 1);
	ft_strlcpy(s1_s2 + len1, s2, len2 + 1);
	free (s1);
	return (s1_s2);
}

size_t	ft_strlen(const char *s, char end)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*(s + len) != 0 && *(s + len) != end)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(src, 0);
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

	if (!acc)
		return (0);
	end = BUF_SIZE * cycle;
	start = BUF_SIZE * (cycle - 1);
	while (start < end && start >= 0)
	{
		if (*(acc + start) == '\n' || *(acc + start) == 0)
			return (1);
		start++;
	}
	return (0);
}

char	*ft_split_mini(char **acc_ptr)
{
	int		size_res;
	int		size_acc;
	char	*result;
	char	*new_acc;

	if (!*acc_ptr)
		return (NULL);
	size_res = ft_strlen(*acc_ptr, '\n');
	if (*(*acc_ptr + size_res) == 0)
		new_acc = NULL;
	else
	{
		size_acc = ft_strlen(*acc_ptr + size_res + 1, 0);
		new_acc = (char *) malloc((size_acc + 1) * sizeof(char));
		ft_strlcpy(new_acc, *acc_ptr + size_res + 1, size_acc + 1);
		size_res++;
	}
	result = (char *) malloc((size_res + 1) * sizeof(char));
	ft_strlcpy(result, *acc_ptr, size_res + 1);
	free(*acc_ptr);
	*acc_ptr = new_acc;
	return (result);
}
