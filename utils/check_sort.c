/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:08:28 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/10 18:26:16 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	check_valid(t_var *vars)
{
	if (check_a(vars))
		return (1);
	else
		return (0);
}
