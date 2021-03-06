/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:52:25 by roudouch          #+#    #+#             */
/*   Updated: 2022/01/06 15:03:08 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sb(int *b, int num)
{
	int	backup;

	if (num < 2)
		return ;
	backup = b[0];
	b[0] = b[1];
	b[1] = backup;
}
