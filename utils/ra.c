/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:13:08 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:13:14 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_var *vars)
{
	int	*new;
	int	backup;
	int	x;
	int	i;

	new = malloc(sizeof(int) * vars->size_a);
	if (!new)
	{
		free(vars->a);
		free(vars->b);
		exit(0);
	}
	backup = vars->a[0];
	x = 0;
	i = 1;
	while (x < vars->size_a - 1)
	{
		new[x] = vars->a[i++];
		x++;
	}
	new[x] = backup;
	free(vars->a);
	vars->a = new;
	write(1, "ra\n", 3);
}
