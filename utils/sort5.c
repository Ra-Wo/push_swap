/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:52 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:14:53 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	deal_with_five_nums(t_var *vars)
{
	while (vars->size_a > 3)
	{
		if (check_less_num(vars->a, vars->a[0], vars->size_a))
			pb(vars);
		else if (index_less_num(vars) >= (vars->size_a / 2))
			rra(vars);
		else if (index_less_num(vars) < (vars->size_a / 2))
			ra(vars);
	}
	deal_with_tree_nums(vars);
	while (vars->size_b > 0)
		pa(vars);
}
