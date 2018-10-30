/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:33:54 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/30 10:07:45 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		valid_spot(char **map, int i, int j, t_piece *piece)
{
	return (0);
}

int		place(char **map, int size, t_piece *piece)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (valid_spot(map, i , j, piece) == 1)
			{
				return (1);
			}
		}
	}
	return (0);
}

void	reset(t_fillit *fill)
{

}

char	**malloc_map(char **map, int size)
{
	char	**result;
	int		i;

	i = -1;
	result = (char **)malloc(sizeof(char *) * size);
	if (!result)
		return (NULL);
	while (++i < size)
	{
		if ((result[i] = ft_strdup(map[i]) == NULL)
			return (NULL);
	}
	return (result);
}

char	**update_map(char **map, t_piece *piece, int size, char **result)
{
	int		i;
	int		j;
	int		y;

	i = -1;
	result = malloc_map(map, size);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (valid_spot(map, i , j, piece) == 1)
			{
				y = -1;
				while (++y < piece->height)
				{
					ft_memmove(map[i] + j, piece[piece->y] + x, piece->width);
				}
			}
		}
	}
	return (result);
}

int		algo(t_fillit *fill, char **map, t_piece **list, int size, int num_placed)
{
	int		i;
	char	**temp;

	i = 0;
	while (num_placed != fill->count && i < fill->count)
	{
		if (list[i]->placed == 0)
		{
			if (place(map, size, list[i]) == 1)
			{
				list[i].placed = 1;
				temp = update_map(map, list[i], size, temp);
				if (algo(fill, temp, list, size, num_placed + 1) == 1)
				{
					return (1);
				}
				free_map(temp);
				list[i].placed = 0;
			}
		}
		i++;
	}
	if (num_placed == fill->count)
	{
		print_result(fill->result);
		return (1);
	}
	reset(fill);
	algo(fill, fill->list, fill->size, 0);
	return (-1);
}
