/*
** EPITECH PROJECT, 2021
** analyse_events
** File description:
** analyse events and act in condition
*/

#include "game.h"

void game_events(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseMoved) {
        sprite->cursor_pos.x = window->event.mouseMove.x - 36;
        sprite->cursor_pos.y = window->event.mouseMove.y - 36;
        sfSprite_setPosition(sprite->cursor, sprite->cursor_pos);
    }
    if (window->event.type == sfEvtMouseButtonPressed) {
        window->count += 1;
        get_count(window->count_text, window->count);
        sfSound_play(sound->click0);
    }
}

void analyse_events(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event))
        game_events(window, sprite, clock, sound);
}
