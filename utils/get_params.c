/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:45:49 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/14 10:33:30 by roudouch         ###   ########.fr       */
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
	if (!lines)
	{
		free(params);
		exit(1);
	}
	x = 0;
	while (lines[x])
	{
		params[i++] = ft_atoi(lines[x], params);
		free(lines[x++]);
	}
	free(lines);
	return (i);
}

static void	check_dup(int *params, int num, int in, t_var *vars)
{
	int	x;

	x = 0;
	while (x++ < vars->size_a - 1)
	{
		if (x == in)
			continue ;
		if (num == params[x])
		{
			free(params);
			write(2, "Error\n", 6);
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
		else if (argv[x][0] != '\0')
			params[i++] = ft_atoi(argv[x], params);
		x++;
	}
	i = 0;
	while (i < vars->size_a)
	{
		check_dup(params, params[i], i, vars);
		i++;
	}
	vars->a = params;
}
