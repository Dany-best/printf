#include "ft_printf.h"

void	width_output(int *length, int current_width)
{
	if (current_width > 0)
	{
		if (g_format_info->zero == 1 && g_format_info->minus == 0)
			while (current_width-- > 0)
			{
				ft_putchar_fd('0', 1);
				++(*length);
			}
		if (g_format_info->minus == 0)
			while (current_width-- > 0)
			{
				ft_putchar_fd(' ', 1);
				++(*length);
			}
	}
}

void	check_precision(char **str, int *diff, int *num_len, int *flag)
{
	if (g_format_info->precision >= 0)
	{
		*str = create_zero_str(diff, str, *num_len, g_format_info->precision);
		*flag = 1;
	}
	if (**str == '0' && g_format_info->precision == 0)
	{
		**str = '\0';
		*num_len = 0;
		*diff = 0;
	}
}

char	*create_zero_str(int *diff, char **str, int num_len, int struct_num)
{
	char	*zero_str;
	char	*ptr;
	int		i;

	if (struct_num > num_len)
	{
		*diff = struct_num - num_len;
		if (!(zero_str = (char*)malloc(sizeof(char) * (*diff) + 1)))
			return (0);
		i = 0;
		while (i < *diff)
		{
			zero_str[i] = '0';
			i++;
		}
		zero_str[i] = '\0';
		ptr = *str;
		*str = ft_strjoin(zero_str, *str);
		free(ptr);
		free(zero_str);
	}
	return (*str);
}
