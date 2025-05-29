// the header goes here

#include "../cub.h"

int check_textures(char **content, int *i)
{
    int textures;

    textures = 0;
    while (*i < 4 && content[*i])
    {
        if (!ft_strncmp(content[*i], "SO ", 3)
            || !ft_strncmp(content[*i], "NO ", 3)
            || !ft_strncmp(content[*i], "WE ", 3)
            || !ft_strncmp(content[*i], "EA ", 3))
            textures++;
        (*i)++;
    }
    if (textures != 4)
    {
        if (*i != textures)
            return (ft_error("missing textures on line 1"), -1);
        return (ft_error("textures error"), -1);
    }
    if (*i == 0)
        return (ft_error("empty config file"), -1);
    return (0);
}

int check_colors(char **content, int *i)
{

}

void    skip_newlines(char **content, int *i)
{
    while (content[*i] && !ft_strcmp(content[*i], "\n"))
        (*i)++;
}

int check_config(char  **content)
{
    int i;

    i = 0;

}