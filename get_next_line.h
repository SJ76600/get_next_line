/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:42:44 by sjupille          #+#    #+#             */
/*   Updated: 2024/11/12 13:41:02 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
char	*ft_next_line(char *line);
char	*ft_extract_line(char *line);
char	*ft_read_line(int fd, char *line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
//char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup(const char *s);

#endif