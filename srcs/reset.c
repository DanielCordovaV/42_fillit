/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:33:08 by dcordova          #+#    #+#             */
/*   Updated: 2018/10/30 15:16:22 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	free_map(char **map)
{
	int	size;

	size = ft_strlen(*map);
	while (--size >= 0)
	{
		ft_strclr(map[size]);
		free(map[size]);
	}
	free(map);
	map = NULL;
}

char	**new_map(int size)
{
	int		i;
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
	}
	return (map);
}

int		reset(t_fillit *f)
{
	int	i;

	i = -1;
	while (++i < f->count)
	{
		f->list[i]->placed = 0;
	}
	free_map(f->result);
	f->size += 1;
	if (!(f->result = new_map(f->size)))
		return (-1);
	else
		return (1);
}
