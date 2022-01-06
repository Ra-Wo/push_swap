/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:11 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:14:18 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_var *vars)
{
	int	*new;
	int	x;
	int	i;

	new = malloc(sizeof(int) * vars->size_b);
	if (!new)
	{
		free(vars->a);
		free(vars->b);
		exit(0);
	}
	x = 1;
	i = 0;
	new[0] = vars->b[vars->size_b - 1];
	while (x < vars->size_b)
	{
		new[x] = vars->b[i++];
		x++;
	}
	free(vars->b);
	vars->b = new;
	write(1, "rrb\n", 4);
}
