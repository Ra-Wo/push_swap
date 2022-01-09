/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:33:30 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/09 19:01:33 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	error_exit(t_var *vars)
{
	free(vars->a);
	free(vars->b);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_instruction(t_var *vars, int i)
{
	if (!ft_strcmp(vars->instruction[i], "sa"))
		sa(vars->a, vars->size_a);
	else if (!ft_strcmp(vars->instruction[i], "sb"))
		sb(vars->b, vars->size_b);
	else if (!ft_strcmp(vars->instruction[i], "pa"))
		pa(vars);
	else if (!ft_strcmp(vars->instruction[i], "pb"))
		pb(vars);
	else if (!ft_strcmp(vars->instruction[i], "ra"))
		ra(vars);
	else if (!ft_strcmp(vars->instruction[i], "rb"))
		rb(vars);
	else if (!ft_strcmp(vars->instruction[i], "rr"))
		rr(vars);
	else if (!ft_strcmp(vars->instruction[i], "rra"))
		rra(vars);
	else if (!ft_strcmp(vars->instruction[i], "rrb"))
		rrb(vars);
	else if (!ft_strcmp(vars->instruction[i], "rrr"))
		rrr(vars);
	else if (!ft_strcmp(vars->instruction[i], "ss"))
		ss(vars->b, vars->a, vars->size_a, vars->size_b);
	else
		error_exit(vars);
}

void	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) <= 0)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
