/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:01 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:14:01 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_var *vars)
{
	int	*new;
	int	x;

	new = malloc(sizeof(int) * vars->size_a);
	if (!new)
	{
		free(vars->a);
		free(vars->b);
		exit(0);
	}
	x = 0;
	new[0] = vars->a[vars->size_a - 1];
	while (x < vars->size_a - 1)
	{
		new[x + 1] = vars->a[x];
		x++;
	}
	free(vars->a);
	vars->a = new;
	write(1, "rra\n", 4);
}
