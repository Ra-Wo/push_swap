/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:12:54 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/11 09:43:06 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	to_top_from_top(t_var *vars, int loop)
{
	int	x;

	x = 0;
	while (x++ < loop)
	{
		ra(vars);
	}
}

void	to_top_from_buttom(t_var *vars, int loop)
{
	int	x;

	x = 0;
	while (x++ < loop)
	{
		rra(vars);
	}
}
