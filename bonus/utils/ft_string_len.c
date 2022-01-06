/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:08:40 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/01 15:08:43 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

unsigned int	ft_string_len(const char *str)
{
	unsigned int	num;

	num = 0;
	while (str[num] != '\0')
		num++;
	return (num);
}
