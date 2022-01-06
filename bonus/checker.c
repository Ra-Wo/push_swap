/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:05:15 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 16:37:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./GetNextLine/get_next_line.h"
#include "checker.h"

void	get_instruction(t_var *vars)
{
	char	*line;
	char	*all_lines;

	line = get_next_line(0);
	all_lines = ft_str_dup("");
	while (line != NULL)
	{
		all_lines = ft_string_join(all_lines, line);
		free(line);
		line = get_next_line(0);
	}
	vars->instruction = ft_split(all_lines, '\n');
}

void	sort(t_var *vars, int i)
{
	while (vars->instruction[++i])
	{
		check_instruction(vars, i);
	}
}

int	check_a(t_var *vars)
{
	int	x;

	x = 0;
	while (x + 1 < vars->size_a)
	{
		if (vars->a[x] > vars->a[x + 1])
			return (1);
		x++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;
	int		i;

	i = -1;
	vars.size_a = argc - 1;
	vars.size_b = 0;
	get_instruction(&vars);
	get_params(&vars, argv);
	vars.b = malloc(sizeof(char) * vars.size_a);
	if (!vars.b)
	{
		free(vars.a);
		return (0);
	}
	sort(&vars, i);
	if (check_a(&vars))
		write(1, "KO", 2);
	else
		write(1, "OK", 2);
	return (0);
}
