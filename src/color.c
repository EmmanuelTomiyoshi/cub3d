/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:09:50 by mtomomit          #+#    #+#             */
/*   Updated: 2023/02/22 13:24:13 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_color(char **rgb)
{
	size_t	i;

	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb[i]);
	free(rgb);
}

int	get_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	if (r == 0, b == 0, g == 0)
		r = 1;
	if ((r > 255 || r < 0) || (b > 255 || b < 0) || (g > 255 || g < 0))
		return (0);
	rgb += (r & 0xFF) << 16;
	rgb += (g & 0xFF) << 8;
	rgb += (b & 0xFF);
	return (rgb);
}

int	get_color(t_file_data *file_data, char **splited_line, char *line)
{
	char	**rgb;
	char	*color;

	if (!ft_strcmp("F\0", splited_line[0]) && file_data->f_color == 0)
	{
		color = ft_strtrim(splited_line[1], "\n");
		rgb = ft_split(color, ',');
		return (1);
	}
	if (!ft_strcmp("C\0", splited_line[0]) && file_data->c_color == 0)
	{
		file_data->we_path = ft_strtrim(splited_line[1], "\n");
		return (1);
	}
}
