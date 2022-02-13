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
        if (sprite->player_unzoom == 0) {
            sfClock_restart(clock->clock_player_unzoom);
            sprite->player_unzoom = 1;
        }
        if (sound->click_played == 0) {
            sfSound_play(sound->click);
            sound->click_played = 1;
            sfClock_restart(clock->clock_click_sound);
        }
        window->count += window->multiplier;
        get_count(window->count_text, window->count);
    }
}

void analyse_events(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event))
        game_events(window, sprite, clock, sound);
}
