/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:42:53 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/09 19:06:47 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	exit_print_error(int *params)
{
	write(2, "Error\n", 6);
	free(params);
	exit(1);
}

void	check_err(const char *str, int i, int *params)
{
	int	x;

	x = 0;
	if (str[i] == '-' || str[i] == '\0')
		exit_print_error(params);
	while (str[i + x] <= '9' && str[i + x] >= '0')
		x++;
	if (str[i + x] != '\0')
		exit_print_error(params);
}

int	ft_atoi(const char *str, int *params)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	check_err(str, i, params);
	while (str[i] <= '9' && str[i] >= '0')
		number = (number * 10) + (str[i++] - '0');
	if (number >= 2147483648 || number * sign <= -2147483649)
		exit_print_error(params);
	return (number * sign);
}
