/*
** EPITECH PROJECT, 2020
** pyramid
** File description:
** find the shortest way to leave the pyramid
*/

int min(int a, int b)
{
    return (a > b ? b : a);
}

int get_path(int size, const int **map, int floor, int room)
{
    if (floor == size)
        return 0;
    return (min(get_path(size, map, floor + 1, room),
        get_path(size, map, floor + 1, room + 1))+ map[floor][room]);
}

int pyramid_path(int size , const int **map)
{
    return (get_path(size, map, 0, 0));
}