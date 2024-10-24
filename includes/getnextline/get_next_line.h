/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:11:37 by amagomad          #+#    #+#             */
/*   Updated: 2024/10/24 15:36:26 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlenn(char *str);
void	ft_bzero(void *s1, size_t n);
char	*ft_strncpy(char *str, char *s2, char c);
char	*ft_split(char *tab, char c);
char	*ft_strdupp(char *s);
int		ft_freee(char *s);
char	*ft_strcpyv2(char *s1, char *s2, char *s3);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

#endif
