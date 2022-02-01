/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:48 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/10 18:34:21 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	deal_with_three_nums(t_var *vars)
{
	while (!(vars->a[0] < vars->a[1] && vars->a[1] < vars->a[2]))
	{
		if (vars->a[0] > vars->a[1] && vars->a[0] < vars->a[2])
			sa(vars->a, vars->size_a);
		else if (vars->a[0] > vars->a[1] && vars->a[0] > vars->a[2])
			ra(vars);
		else if (vars->a[1] > vars->a[0] && vars->a[1] > vars->a[2])
			rra(vars);
	}
}
