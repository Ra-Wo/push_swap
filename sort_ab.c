/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:43 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/11 17:05:11 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	the_else(t_var1 *v)
{
	v->part += v->chu;
	if (v->part > v->size_sorted_array)
		v->part = v->size_sorted_array - 1;
}

void	first_sort(t_var *vars, t_var1 *v)
{
	while (vars->size_a > 2)
	{
		if (less_from_top(vars, v) != -1 || less_from_buttom(vars, v) != -1)
		{
			if ((less_from_top(vars, v)
					<= ((vars->size_a - 1) - less_from_buttom(vars, v)))
				&& less_from_top(vars, v) != -1)
			{
				to_top_from_top(vars, less_from_top(vars, v));
				pb(vars);
			}
			else if (less_from_buttom(vars, v) != -1)
			{
				to_top_from_buttom(vars,
					((vars->size_a - 1) - less_from_buttom(vars, v) + 1));
				pb(vars);
			}
		}
		else
			the_else(v);
	}
	pb(vars);
	pb(vars);
}

void	second_sort(t_var *vars)
{
	while (vars->size_b != 0)
	{
		if (check_big_num(vars->b, vars->b[0], vars->size_b))
			pa(vars);
		else if (big_num_in_b(vars) >= (vars->size_b / 2))
			rrb(vars);
		else if (big_num_in_b(vars) < (vars->size_b / 2))
			rb(vars);
	}
}
