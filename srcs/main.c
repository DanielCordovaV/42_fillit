/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:23:28 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/30 20:01:41 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		init(t_fillit *fill)
{
	fill->list = (t_piece **)malloc(sizeof(t_piece *) * 27);
	if (!fill->list)
		return (-1);
	fill->count = 0;
	fill->result = NULL;
	fill->size = 0;
	return (1);
}

int		get_piece(t_fillit *fill, int fd, char *line, t_piece *piece)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		get_next_line(fd, &line);
		while (line[++j] != '\0')
		{
			if (j > 3 || (line[j] != '.' && line[j] != '#'))
				return (-1);
			count += line[j] == '#' ? 1 : 0;
		}
		if (j != 4)
			return (-1);
		piece->map[i] = line;
	}
	i = count != 4 ? -1 : 1;
	fill->list[fill->count] = piece;
	return (i);
}

int		check_piece(t_fillit *f, t_piece *piece)
{
	int i;
	int j;
	int valid;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (piece->map[i][j] == '#')
			{
				valid = 0;
				if ((i != 0 && piece->map[i - 1][j] == f->count + 'A') ||
					((i != 3) && piece->map[i + 1][j] == '#') ||
						((j != 0) && piece->map[i][j - 1] == f->count + 'A') ||
						((j != 3) && piece->map[i][j + 1] == '#'))
					valid++;
				if (valid == 0)
					return (-1);
				piece->map[i][j] = f->count + 'A';
			}
		}
	}
	return (1);
}

int		get_pieces(t_fillit *fill, int fd)
{
	char	*line;
	t_piece	*piece;

	while (fill->count == 0 || get_next_line(fd, &line) != 0)
	{
		if (fill->count != 0 && ft_strcmp(line, "") != 0)
			return (-1);
		piece = (t_piece *)malloc(sizeof(t_piece));
		if (!piece)
			return (-1);
		if ((piece->map = (char **)malloc(sizeof(char *) * 4)) == NULL)
			return (-1);
		piece->placed = 0;
		if (get_piece(fill, fd, line, piece) == -1)
			return (-1);
		if (check_piece(fill, fill->list[fill->count]) == -1)
			return (-1);
		fill->count++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fillit	fill;
	int			fd;

	if (argc != 2)
		return (printf("print usage\n"));
	fd = open(argv[1], O_RDONLY);
	if (init(&fill) == -1 || fd == -1)
		return (printf("error\n"));
	if (get_pieces(&fill, fd) == -1)
		return (printf("error\n"));
	close(fd);
	fill.result = new_map(3);
	fill.size = 3;
	piece_stats(&fill);
	while (algs(&fill, fill.result, fill.list, 0) != 1)
		reset(&fill);
	//free_all(&fill);
	return (1);
}
