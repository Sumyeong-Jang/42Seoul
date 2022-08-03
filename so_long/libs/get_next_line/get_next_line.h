/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:21:09 by sumjang           #+#    #+#             */
/*   Updated: 2022/04/14 22:19:59 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

char	*get_next_line(int fd);
char	*read_input(char **backup, int fd);
char	*split_line(char const *backup);
size_t	save_remains(char **backup, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
char	*new_ft_strjoin(char const *backup, char const *buf);

#endif
