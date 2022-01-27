/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:30:36 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/27 12:41:14 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "buffer.h"
# include <stdarg.h>
# define CONVERT_SYMBOL '%'
# define CONVERSION "cspdiuxX%"

/*			CONVERTERS				*/

char	*pointer_to_hexa(unsigned long p, int upper_case);

/*			HANDLERS				*/

void	handle_char(int c, t_buffer *buf);
void	handle_string(const char *str, t_buffer *buf);
void	handle_pointer(unsigned long p, t_buffer *buf);
void	handle_decimal(int n, t_buffer *buf);
void	handle_unsigned(unsigned int n, t_buffer *buf);
void	handle_hexa(unsigned int n, int upper_case, t_buffer *buf);

/*			MAIN FUNCTIONS			*/

char	find_conversion(const char *str);
int		convert(const char *str, va_list args, t_buffer *buf);
void	str_transform(const char *str, va_list args, t_buffer *buf);
int		ft_printf(const char *str, ...);

#endif
