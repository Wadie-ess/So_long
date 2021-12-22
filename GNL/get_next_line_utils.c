/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:27:59 by oessendo          #+#    #+#             */
/*   Updated: 2021/11/28 17:28:38 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		start++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*newstr;

	i = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	i = ft_len(s, start, len);
	newstr = (char *)malloc((i + 1) * sizeof(char));
	if (!newstr)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_fill(char *str, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (0);
	newstr = ft_fill(newstr, s1, s2);
	return (newstr);
}

char	*ft_strdup(char *s)
{
	char	*newstr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	newstr = (char *)malloc(len + 1);
	if (newstr == NULL)
		return (NULL);
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}	
	newstr[i] = '\0';
	return (newstr);
}
