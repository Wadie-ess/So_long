/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:15:26 by oessendo          #+#    #+#             */
/*   Updated: 2021/12/14 22:11:56 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

size_t	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_line(char **str)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	if (!(*str))
		return (NULL);
	while ((*str)[i] != '\n' && (*str)[i])
			i++;
	if (i < ft_strlen(*str))
	{
		temp = *str;
		line = ft_substr(*str, 0, ++i);
		*str = ft_substr(*str, i, ft_strlen(*str));
		free(temp);
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}

static char	*ft_save_buffer(char *str, char *buffer)
{
	char	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
	}	
	else
		str = ft_strdup(buffer);
	return (str);
}

static int	ft_is_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer ;
	static char	*str;
	int			readed_bytes;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed_bytes = read(fd, buffer, BUFFER_SIZE);
	while (readed_bytes > 0)
	{
		buffer[readed_bytes] = '\0';
		str = ft_save_buffer(str, buffer);
		if (ft_is_newline(str) == 1)
			break ;
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_line(&str));
}
// test
/*  #include <fcntl.h> 
int main()
{
	//int fd = open("test.txt", O_RDONLY);
	//get_next_line(fd); 
	printf("1 : %s\n",get_next_line(fd));
	printf("2 : %s\n",get_next_line(fd));
	printf("3 : %s\n",get_next_line(fd));
	printf("4 : %s\n",get_next_line(fd));
	printf("4 : %s\n",get_next_line(fd));


	return (0);
}
 */