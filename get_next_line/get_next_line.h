/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musisman <<musisman@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:54:34 by musisman          #+#    #+#             */
/*   Updated: 2025/03/20 09:38:52 by musisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin_diff(char *s, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_line_s(char *s);
char	*ft_new_line_s(char *s);
char	*get_next_line(int fd, int free_static);

#endif
