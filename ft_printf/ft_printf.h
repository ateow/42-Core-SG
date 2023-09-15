/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:16:05 by ateow             #+#    #+#             */
/*   Updated: 2023/09/14 09:16:07 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_printf(const char *input, ...);
int			ft_pchar(char c);
int			ft_pstring(char *s);
char		*ft_uitoa(int n);
int			ft_phexanbr(unsigned int nbr, char c);
int			ft_ppointer(unsigned long nbr);
int			ft_phexapointer(unsigned long nbr);
int			ft_definetype(char c, va_list args);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
int			ft_definetype(char c, va_list args);

#endif
