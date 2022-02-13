/*
** EPITECH PROJECT, 2021
** pos
** File description:
** handle pos of sprites
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

sfVector2f get_offset(float x, float y)
{
    sfVector2f offset;

    offset.x = x;
    offset.y = y;
    return offset;
}

void set_pos(sfSprite *sprite, float x, float y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    sfSprite_setPosition(sprite, pos);
    return;
}
