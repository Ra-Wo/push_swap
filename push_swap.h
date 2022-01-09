/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:52:12 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/09 16:18:02 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct vars{
	int	*a;
	int	size_a;
	int	*b;
	int	size_b;
}	t_var;

typedef struct v {
	int	*sorted_array;
	int	size_sorted_array;
	int	part;
	int	chu;
	int	c;
	int	x;
}	t_var1;

void	get_params(t_var *vars, char **argv);
int		ft_atoi(const char *str, int *params);
char	**ft_split(char const *s, char c);
int		ft_isalpha(int character);
void	get_length(t_var *vars, char **argv);
void	sa(int *a, int num);
void	sb(int *a, int num);
void	pa(t_var *vars);
void	pb(t_var *vars);
void	ra(t_var *vars);
void	rb(t_var *vars);
void	rr(t_var *vars);
void	rra(t_var *vars);
void	rrb(t_var *vars);
void	rrr(t_var *vars);
int		check_valid(t_var *vars);
int		*sorting(t_var *vars);
void	to_top_from_top(t_var *vars, int loop);
void	to_top_from_buttom(t_var *vars, int loop);
int		less_from_top(t_var *vars, t_var1 *v);
int		less_from_buttom(t_var *vars, t_var1 *v);
void	first_sort(t_var *vars, t_var1 *v);
void	second_sort(t_var *vars);
int		check_big_num(int *nums, int num, int total);
int		big_num_in_b(t_var *vars);
void	deal_with_tree_nums(t_var *vars);
void	deal_with_five_nums(t_var *vars);
int		check_less_num(int *nums, int num, int total);
int		index_less_num(t_var *vars);

void	rotate_to_top(t_var *vars, int loob);
void	rotate_to_top_from_buttom(t_var *vars, int loop);

#endif