/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:33:54 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/30 16:07:30 by dcordova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		valid_spot(char **map, int i, int j, t_piece *piece)
{
	int		n;
	int		m;
	int		size;

	size = ft_strlen(*map);
	if (j + piece->width >= size || i + piece->height >= size)
		return (0);
	n = -1;
	while (++n < piece->height)
	{
		m = -1;
		while (++m < piece->width)
		{
			if (map[i + n][j + m] != '.' && 
					piece->map[piece->y + n][piece->x + m] != '.')
				return(0);
		}
	}
	return (1);
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
		if ((result[i] = ft_strdup(map[i])) == NULL)
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
					ft_memmove(map[i] + j, piece->map[piece->y] + piece->x
							, piece->width);
				}
			}
		}
	}
	return (result);
}

int		algo(t_fillit *fill, char **map, t_piece **list, int num_placed)
{
	int		i;
	char	**temp;

	i = 0;
	//printf("called algo: size: %d count: %d\n", fill->size, fill->count);
	while (num_placed != fill->count && i < fill->count)
	{
		if (list[i]->placed == 0)
		{
			if (place(map, fill->size, list[i]) == 1)
			{
				list[i]->placed = 1;
				temp = update_map(map, list[i], fill->size, temp);
				if (algo(fill, temp, list, num_placed + 1) == 1)
				{
					return (1);
				}
				free_map(temp);
				list[i]->placed = 0;
			}
		}
		i++;
	}
	if (num_placed == fill->count)
	{
		print_map(map);
		ft_putchar('\n');
		return (1);
	}
	reset(fill);
	algo(fill, fill->result, fill->list, 0);
	return (-1);
}
