/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:30:36 by bzalugas          #+#    #+#             */
/*   Updated: 2022/01/19 20:19:16 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "buffer.h"
# include <stdarg.h>
# define CONVERT_SYMBOL '%'
# define CONVERSION "cspdiuxX%"
# define FLAGS "-0.# +"
# define MAX_FLAGS 5

char	*pointer_to_hexa(void *p);

char	*find_conversion_directive(const char *str);
int		convert(const char *str, va_list args, t_buffer *buf);
int		str_transform(const char *str, va_list args, t_buffer *buf);
int		ft_printf(const char *str, ...);

#endif
