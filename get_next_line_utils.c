/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:01:06 by sjupille          #+#    #+#             */
/*   Updated: 2024/11/12 13:51:35 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!c)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	size_t			i;

	i = 0;
	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	if (nsrc == NULL && ndest == NULL)
		return (NULL);
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}

/*char	*ft_strjoin(char *s1, char *s2)
{
	char	*strj;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strj = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (strj == NULL)
		return (NULL);
	if (s1)
		ft_memcpy(strj, s1, len1);
	ft_memcpy((strj + len1), s2, (len2 + 1));
	strj[len1 + len2] = '\0';
	free(s1);
	return (strj);
}*/

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*strj;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	strj = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!strj)
		return (NULL);
	if (s1)
		while (s1[++i])
			strj[i] = s1[i];
	while (s2[j])
		strj[i++] = s2[j++];
	strj[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (strj);
}
