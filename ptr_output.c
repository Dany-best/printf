#include "ft_printf.h"

static void		print_width(int *length, int *width)
{
	while ((*width)-- > 0)
	{
		ft_putchar_fd(' ', 1);
		++(*length);
	}
}

void			ptr_output(unsigned long long arg, int *length)
{
	char	*str;
	int		num_len;
	int		width;
	int		diff;

	str = dec_to_ptr(arg, g_hex_base_lowercase);
	num_len = ft_strlen(str);
	diff = 0;
	width = (g_format_info->width) - (int)ft_strlen(str);
	if (g_format_info->minus == 1)
	{
		ft_putstr_fd(str, 1);
		print_width(length, &width);
	}
	else
	{
		print_width(length, &width);
		ft_putstr_fd(str, 1);
	}
	*length += num_len + diff;
	free(str);
}
