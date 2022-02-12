/*
** EPITECH PROJECT, 2021
** display
** File description:
** display
*/

#include <unistd.h>
#include "game.h"

void display(window_td *window, sprite_td *sprite)
{
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, sprite->cursor, NULL);
}
