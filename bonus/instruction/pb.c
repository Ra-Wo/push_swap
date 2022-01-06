/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:02:50 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:02:51 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	free_exit(t_var *vars)
{
	free(vars->a);
	free(vars->b);
	exit(0);
}

static void	delete_num_from_a(t_var *vars, int index_of_num)
{
	int	*new;
	int	x;
	int	i;

	new = malloc(sizeof(int) * (vars->size_a - 1));
	if (!new)
		free_exit(vars);
	x = 0;
	i = 0;
	while (x < vars->size_a)
	{
		if (x == index_of_num)
		{
			x++;
			continue ;
		}
		new[i++] = vars->a[x];
		x++;
	}
	free(vars->a);
	vars->a = new;
	vars->size_a--;
}

void	pb(t_var *vars)
{
	int	*new;
	int	x;
	int	i;

	if (!vars->b || vars->size_a <= 0)
		return ;
	new = malloc(sizeof(int) * (vars->size_b + 1));
	if (!new)
	{
		free(vars->a);
		free(vars->b);
		exit(0);
	}
	x = 0;
	i = 1;
	new[0] = vars->a[0];
	while (x < (vars->size_b))
	{
		new[i++] = vars->b[x++];
	}
	free(vars->b);
	vars->b = new;
	delete_num_from_a(vars, 0);
	vars->size_b++;
}
