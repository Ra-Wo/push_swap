/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:02:44 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:02:45 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rb(t_var *vars)
{
	int	*new;
	int	backup;
	int	x;
	int	i;

	new = malloc(sizeof(int) * vars->size_b);
	if (!new)
	{
		free(vars->a);
		free(vars->b);
		exit(0);
	}
	backup = vars->b[0];
	x = 0;
	i = 1;
	while (x < vars->size_b - 1)
	{
		new[x] = vars->b[i++];
		x++;
	}
	new[x] = backup;
	free(vars->b);
	vars->b = new;
}
