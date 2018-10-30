/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:43:46 by dcordova          #+#    #+#             */
/*   Updated: 2018/10/29 22:38:30 by dcordova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_getwidth(t_piece *piece)
{
	int	y;
	int	x;

	x = -1;
	while (++x < 4)
	{
		y = 0;
		while (y < 4 && piece->map[y][x] == '.')
			y++;
		if (y < 4)
		{
			piece->x = x;
			break ;
		}
	}
	x = 4;
	while (--x >= piece->x)
	{
		y = 0;
		while (y < 4 && piece->map[y][x] == '.')
			y++;
		if (y < 4)
		{
			piece->width = x - piece->x + 1;
			break ;
		}
	}
}

static void	ft_getheight(t_piece *piece)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 4)
	{
		x = 0;
		while (x < 4 && piece->map[y][x] == '.')
			x++;
		if (x < 4)
		{
			piece->y = y;
			break ;
		}
	}
	y = 4;
	while (--y >= piece->y)
	{
		x = 0;
		while (x < 4 && piece->map[y][x] == '.')
			x++;
		if (x < 4)
		{
			piece->height = y - piece->y + 1;
			break ;
		}
	}
}

int			piece_stats(t_fillit *fill)
{
	int i;

	i = -1;
	while (++i < fill->count)
	{
		ft_getwidth(fill->list[i]);
		ft_getheight(fill->list[i]);
	}
	return (0);
}
	
