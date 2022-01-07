/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:14:59 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/07 10:54:29 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	copy_arr(t_var *vars, int *new)
{
	int	x;

	x = 0;
	while (x < vars->size_a)
	{
		new[x] = vars->a[x];
		x++;
	}
}

static void	sort(int *new, t_var *vars)
{
	int	i;
	int	backup;

	i = 0;
	while (i < vars->size_a - 1)
	{
		if (new[i] > new[i + 1])
		{
			backup = new[i];
			new[i] = new[i + 1];
			new[i + 1] = backup;
			i -= 2;
			if (i < 0)
				i = 0;
		}
		i++;
	}
	if (new[0] > new[1])
		sort(new, vars);
}

int	*sorting(t_var *vars)
{
	int	*new;

	new = malloc(sizeof(int) * vars->size_a);
	if (!new)
	{
		free(vars->a);
		exit(0);
	}
	copy_arr(vars, new);
	sort(new, vars);
	return (new);
}
