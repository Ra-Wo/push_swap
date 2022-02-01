/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_and_check_params.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:07:40 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/13 17:06:06 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	isnotnum(char *str)
{	
	int	x;
	int	sign;

	x = 0;
	sign = 0;
	while (str[x])
	{
		if (str[x] == ' ')
			sign = 1;
		else if (!ft_isdigit(str[x]) && str[x] != '-' && str[x] != '+')
		{
			write(2, "Error\n", 6);
			exit(0);
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
		exit(1);
	while (nums[x] != NULL)
		free(nums[x++]);
	free(nums);
	return (x - 1);
}

void	get_length(t_var *vars, char **argv)
{
	int	x;

	x = 1;
	while (argv[x])
	{
		if (isnotnum(argv[x]))
			vars->size_a += calc(argv[x]);
			x++;
	}
}
