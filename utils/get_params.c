/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:45:49 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:10:22 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	isnotnum(char *str)
{	
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == ' ')
			return (1);
		x++;
	}
	return (0);
}

static int	deal_with_string(char *str, int *params, int i)
{
	char	**lines;
	int		x;

	lines = ft_split(str, ' ');
	x = 0;
	while (lines[x])
	{
		params[i++] = ft_atoi(lines[x]);
		free(lines[x++]);
	}
	free(lines);
	return (i);
}

void	check_dup(int *nums, int num, int in, int total)
{
	int	x;

	x = 0;
	while (x++ < total - 1)
	{
		if (x == in)
			continue ;
		if (num == nums[x])
		{
			free(nums);
			write(2, "Error", 5);
			exit(1);
		}
	}
}

void	get_params(t_var *vars, char **argv)
{
	int	x;
	int	i;
	int	*params;

	get_length(vars, argv);
	params = malloc(sizeof(int) * vars->size_a);
	if (!params)
		exit(1);
	x = 1;
	i = 0;
	while (argv[x])
	{
		if (isnotnum(argv[x]))
			i = deal_with_string(argv[x], params, i);
		else
			params[i++] = ft_atoi(argv[x]);
		x++;
	}
	i = 0;
	while (i < vars->size_a)
	{
		check_dup(params, params[i], i, vars->size_a);
		i++;
	}
	vars->a = params;
}
