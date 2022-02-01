/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:04:46 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/10 18:47:36 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct vars {
	char	**instruction;
	int		size_a;
	int		*a;
	int		size_b;
	int		*b;
}	t_var;

unsigned int	ft_string_len(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_string_join(char const *s1, char const *s2);
void			get_params(t_var *vars, char **argv);
int				ft_atoi(const char *str, int *params);
void			get_length(t_var *vars, char **argv);
int				ft_isdigit(int i);
char			*ft_str_dup(const char *s1);
int				ft_strcmp(char *s1, char *s2);
void			check_instruction(t_var *vars, int i);
unsigned int	ft_strlen(const char *str);
void			check_argv(char **argv);

// instruction 
void			sa(int *a, int num);
void			sb(int *a, int num);
void			ss(int *b, int *a, int size_a, int size_b);
void			pa(t_var *vars);
void			pb(t_var *vars);
void			ra(t_var *vars);
void			rb(t_var *vars);
void			rr(t_var *vars);
void			rra(t_var *vars);
void			rrb(t_var *vars);
void			rrr(t_var *vars);

#endif
