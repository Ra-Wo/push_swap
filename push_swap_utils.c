/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:16:35 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:25:54 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_big_num(int *nums, int num, int total)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (x < total)
	{
		if (num < nums[x])
			sign = 0;
		x++;
	}
	return (sign);
}

int	big_num_in_b(t_var *vars)
{
	int	bigger;
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (++i < vars->size_b)
	{
		if (i == 0)
		{
			bigger = vars->b[i];
			index = i;
		}
		if (bigger < vars->b[i])
		{
			bigger = vars->b[i];
			index = i;
		}
	}
	return (index);
}

int	less_from_top(t_var *vars, t_var1 *v)
{
	int	x;

	x = 0;
	while (x < (vars->size_a / 2))
	{
		if (vars->a[x] < v->sorted_array[v->part])
			return (x);
		x++;
	}
	return (-1);
}

int	less_from_buttom(t_var *vars, t_var1 *v)
{
	int	x;

	x = vars->size_a - 1;
	while (x > (vars->size_a / 2))
	{
		if (vars->a[x] < v->sorted_array[v->part])
			return (x);
		x--;
	}
	return (-1);
}
