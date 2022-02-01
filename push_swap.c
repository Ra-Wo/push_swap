/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:31:22 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/14 10:38:13 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_var *vars, t_var1 *v, int argc, char *argv[])
{
	vars->size_a = argc - 1;
	vars->size_b = 0;
	get_params(vars, argv);
	v->size_sorted_array = vars->size_a;
	if (vars->size_a > 1)
		v->sorted_array = sorting(vars, v);
	vars->b = malloc(sizeof(int) * vars->size_b);
	if (!vars->b)
	{
		if (vars->size_a > 1)
			free(v->sorted_array);
		free(vars->a);
		exit(1);
	}
}

int	check_less_num(int *nums, int num, int total)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (x < total)
	{
		if (num > nums[x])
			sign = 0;
		x++;
	}
	return (sign);
}

int	index_less_num(t_var *vars)
{
	int	x;
	int	index;

	x = 0;
	index = 0;
	while (x < vars->size_a)
	{
		if (vars->a[index] > vars->a[x])
		{
			index = x;
			x = 0;
		}
		x++;
	}
	return (index);
}

static void	solve(t_var1 *v, t_var *vars)
{
	if (v->size_sorted_array == 3 || v->size_sorted_array == 1)
		deal_with_three_nums(vars);
	else if (v->size_sorted_array == 2)
	{
		if (vars->a[0] > vars->a[1])
			sa(vars->a, vars->size_a);
	}
	else if (v->size_sorted_array == 5 || v->size_sorted_array == 4)
		deal_with_five_nums(vars);
	else
	{
		if (v->size_sorted_array <= 250)
			v->part = (v->size_sorted_array / 6);
		else
			v->part = (v->size_sorted_array / 12);
		v->chu = v->part;
		first_sort(vars, v);
		second_sort(vars);
	}
}

int	main(int argc, char *argv[])
{
	t_var	vars;
	t_var1	v;

	init(&vars, &v, argc, argv);
	if (!check_valid(&vars))
	{
		free(vars.a);
		free(vars.b);
		if (vars.size_a > 1)
			free(v.sorted_array);
		return (0);
	}
	solve(&v, &vars);
	free(vars.a);
	free(vars.b);
	free(v.sorted_array);
	return (0);
}
