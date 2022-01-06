/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:15:21 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/01 11:15:36 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isalpha(int character)
{
	if (character >= 'A' && character <= 'Z')
	{
		return (1);
	}
	else if ((character >= 'a') && (character <= 'z'))
	{
		return (2);
	}
	else
	{
		return (0);
	}
}
