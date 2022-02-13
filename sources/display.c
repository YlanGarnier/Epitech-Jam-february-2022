/*
** EPITECH PROJECT, 2021
** display
** File description:
** display
*/

#include <unistd.h>
#include "game.h"

void update_textures(window_td *window, sprite_td *sprite, sound_td *sound)
{
    sfTexture *texture;

    sprite->bg_path[9] = window->lvl + 48;
    texture = sfTexture_createFromFile(sprite->bg_path, NULL);
    sfSprite_setTexture(sprite->bg, texture, sfFalse);
    sprite->player_path[13] = window->lvl + 48;
    texture = sfTexture_createFromFile(sprite->player_path, NULL);
    sfSprite_setTexture(sprite->player, texture, sfFalse);
    sound->click_path[12] = window->lvl + 48;
    sfSoundBuffer_destroy(sound->click_buf);
    sound->click_buf = sfSoundBuffer_createFromFile(sound->click_path);
    sfSound_setBuffer(sound->click, sound->click_buf);
}

void display(window_td *window, sprite_td *sprite)
{
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, sprite->bg, NULL);
    sfRenderWindow_drawSprite(window->window, sprite->player, NULL);
    sfRenderWindow_drawText(window->window, window->count_text, NULL);
    if (window->lvl >= 5) {
        sfRenderWindow_drawText(window->window, window->quote_text, NULL);
        sfRenderWindow_drawSprite(window->window, sprite->gorilla, NULL);
    }
    sfRenderWindow_drawSprite(window->window, sprite->gorilla, NULL);
    sfRenderWindow_drawSprite(window->window, sprite->cursor, NULL);
}
