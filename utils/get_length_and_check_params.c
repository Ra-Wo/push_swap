/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_and_check_params.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:09:58 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:10:11 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		else if (ft_isalpha(str[x]))
		{
			write(2, "Error", 5);
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
	while (nums[x] != NULL)
		free(nums[x++]);
	free(nums);
	return (x - 1);
}

void	get_length(t_var *vars, char **argv)
{
	int	x;

	x = 0;
	while (argv[++x])
		if (isnotnum(argv[x]))
			vars->size_a += calc(argv[x]);
}
