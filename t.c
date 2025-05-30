int parse_map(char **content, int start_index)
{
    int i;
    int player_count;

    i = start_index;
    player_count = 0;
    while (content[i])
    {
        if (ft_strchr(content[i], '\t'))
            return (ft_error("Map contains a tab character"), -1);
        player_count += count_players(content[i]);
        if (player_count > 1)
            return (ft_error("Map contains multiple player positions"), -1);
        i++;
    }
    if (player_count == 0)
        return (ft_error("Map does not contain a player position"), -1);
    if (!is_map_closed(content, start_index, i))
        return (ft_error("Map is not properly closed"), -1);
    return (0);
}

int count_players(char *line)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (line[i])
    {
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
            count++;
        i++;
    }
    return (count);
}

int is_map_closed(char **content, int start, int end)
{
    int i;
    int j;

    // Check the first and last rows
    for (j = 0; content[start][j]; j++)
        if (content[start][j] != '1' && content[start][j] != ' ')
            return (0);
    for (j = 0; content[end - 1][j]; j++)
        if (content[end - 1][j] != '1' && content[end - 1][j] != ' ')
            return (0);

    // Check the left and right borders of the map
    for (i = start; i < end; i++)
    {
        if (content[i][0] != '1' && content[i][0] != ' ')
            return (0);
        j = ft_strlen(content[i]) - 1;
        if (content[i][j] != '1' && content[i][j] != ' ')
            return (0);
    }
    return (1);
}

int	check_map(char **content, int start)
{
    int	i;
    int	count;

    i = start;
    count = 0;
    while (content[i])
    {
        if (ft_strchr(content[i], '\t'))
            return (ft_error("Map error: found tab"), -1);
        if (!is_valid_map_line(content[i]))
            return (ft_error("Map error: invalid elements found"), -1);
        count += count_player(content[i]);
        i++;
    }
    if (count == 0)
        return (ft_error("Map error: no player found"), -1);
    if (count > 1)
        return (ft_error("Map error: multiple players found"), -1);
    return (0);
}

int	is_valid_map_line(char *line)
{
    int	j;

    j = 0;
    while (line[j])
    {
        if (line[j] != '0' && line[j] != '1' && line[j] != ' ' &&
            line[j] != 'N' && line[j] != 'S' && line[j] != 'E' && line[j] != 'W')
            return (0);
        j++;
    }
    return (1);
}

int	count_player(char *line)
{
    int	count;
    int	j;

    count = 0;
    j = 0;
    while (line[j])
    {
        if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E' || line[j] == 'W')
            count++;
        j++;
    }
    return (count);
}