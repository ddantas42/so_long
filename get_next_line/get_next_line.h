/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:22:19 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/28 11:45:26 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 1

// Main Functions
char	*get_next_line(int fd);

// helper Functions
size_t	ft_strlen_2(char *s);
void	clean_before_n(char *temp);
char	*ft_strjoin_2(char *line, char *temp);
int		check_line(char *str);
#endif
