#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <stdio.h>

typedef struct		s_truct_list
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
}					t_format_info;

extern t_format_info	*g_format_info;
extern va_list		g_opa;
extern char			*g_hex_base_lowercase;
extern char			*g_hex_base_uppercase;
extern char			*g_dec;

int					ft_printf(const char *format, ...);
void				string_output(char *s, int *length);
void				char_output(char c, int *length);
int					read_precision(const char **format);
int					read_width(const char **format);
int					read_flags(const char **format);
void				width_output(int *length, int current_width);
void				decimal_output(int arg, int *length);
int					ft_nbr_len(unsigned long long num, int base);
char				*ft_utoa(unsigned long long num, const char *base);
void				ptr_output(unsigned long long arg, int *length);
char				*dec_to_ptr(unsigned long long num, char *base);
void				x_output(unsigned int arg, int *length, const char *base);
void				u_output(unsigned int arg, int *length, const char *base);
char				*create_zero_str(int *diff, char **str, int num_len,
		int struct_num);
void				check_precision(char **str, int *diff, int *num_len,
		int *flag);

#endif
