/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:45:26 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 14:45:52 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
}
