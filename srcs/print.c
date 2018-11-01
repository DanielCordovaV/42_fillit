/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:00:42 by dcordova          #+#    #+#             */
/*   Updated: 2018/10/30 19:43:28 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		print_map(char **map)
{
	int size;
	int	i;

	i = -1;
	size = ft_strlen(*map);
	while (++i < size)
		ft_putendl(map[i]);
	return (1);
}