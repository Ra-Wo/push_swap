/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_and_check_params.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:58 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/14 10:33:15 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	isnotnum(char *str)
{	
	int	x;
	int	sign;

	x = 0;
	sign = 0;
	if (str[x] == '\0')
		return (-1);
	while (str[x])
	{
		if (str[x] == ' ')
			sign = 1;
		else if (!ft_isdigit(str[x]) && str[x] != '-' && str[x] != '+')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		x++;
	}
	return (sign);
}

static int	calc(char *str)
{
	char	**nums;
	int		x;

	x = 0;
	nums = ft_split(str, ' ');
	if (!nums)
		exit(0);
	while (nums[x] != NULL)
		free(nums[x++]);
	free(nums);
	return (x - 1);
}

void	get_length(t_var *vars, char **argv)
{
	int	x;
	int	sign;

	x = 1;
	while (argv[x])
	{
		sign = isnotnum(argv[x]);
		if (sign)
			vars->size_a += calc(argv[x]);
		else if (sign == -1)
			vars->size_a--;
		x++;
	}
}
