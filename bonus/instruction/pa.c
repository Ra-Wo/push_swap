/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:45:58 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 14:46:01 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	free_exit(t_var *vars)
{
	free(vars->a);
	free(vars->b);
	exit(0);
}

static void	delete_num_from_b(t_var *vars, int index_of_num)
{
	int	*new;
	int	x;
	int	i;

	new = malloc(sizeof(int) * (vars->size_b - 1));
	if (!new)
		free_exit(vars);
	x = 0;
	i = 0;
	while (x < vars->size_b)
	{
		if (x == index_of_num)
		{
			x++;
			continue ;
		}
		new[i++] = vars->b[x];
		x++;
	}
	free(vars->b);
	vars->size_b--;
	vars->b = new;
}

void	pa(t_var *vars)
{
	int	*new;
	int	x;
	int	i;

	if (!vars->b || vars->size_b <= 0)
		return ;
	new = malloc(sizeof(int) * (++vars->size_a));
	if (!new)
	{
		free(vars->a);
		free(vars->b);
		exit(0);
	}
	x = 0;
	i = 1;
	new[0] = vars->b[0];
	while (i < vars->size_a)
	{
		new[i++] = vars->a[x++];
	}
	free(vars->a);
	vars->a = new;
	delete_num_from_b(vars, 0);
}
