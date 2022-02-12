/*
** EPITECH PROJECT, 2021
** set_rect
** File description:
** set rect
*/

#include "game.h"

sfIntRect change_rect(sfIntRect rect, int left, int left_max)
{
    if (rect.left >= left_max)
        rect.left = 0;
    else
        rect.left += left;
    return (rect);
}

sfIntRect create_rect(int width, int height)
{
    sfIntRect rect;

    rect.width = width;
    rect.height = height;
    rect.left = 0;
    rect.top = 0;
    return (rect);
}
