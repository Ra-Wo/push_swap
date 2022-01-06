/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:31:22 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:29:56 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_var *vars, t_var1 *v, int argc, char *argv[])
{
	vars->size_a = argc - 1;
	vars->size_b = 0;
	v->x = 0;
	v->c = 0;
	v->size_sorted_array = vars->size_a;
	get_params(vars, argv);
	v->sorted_array = sorting(vars);
	vars->b = malloc(sizeof(int) * vars->size_b);
	if (!vars->b)
	{
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

static int	check_length_number(t_var1 *v, t_var *vars)
{
	if (v->size_sorted_array == 3)
		return (deal_with_tree_nums(vars), 0);
	else if (v->size_sorted_array == 2)
	{
		if (vars->a[0] > vars->a[1])
			sa(vars->a, vars->size_a);
		return (0);
	}
	else if (v->size_sorted_array == 5)
		return (deal_with_five_nums(vars), 0);
	else if (v->size_sorted_array == 4)
		return (deal_with_five_nums(vars), 0);
	if (v->size_sorted_array <= 250)
		v->part = (v->size_sorted_array / 6);
	else if (v->size_sorted_array > 250)
		v->part = (v->size_sorted_array / 12);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_var	vars;
	t_var1	v;

	if (argc <= 2)
		return (0);
	init(&vars, &v, argc, argv);
	if (!check_valid(&vars))
		return (free(vars.a), free(vars.b), 0);
	if (check_length_number(&v, &vars) == 0)
		return (0);
	v.chu = v.part;
	first_sort(&vars, &v);
	second_sort(&vars);
	return (0);
}
