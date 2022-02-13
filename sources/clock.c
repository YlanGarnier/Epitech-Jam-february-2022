/*
** EPITECH PROJECT, 2021
** clock
** File description:
** all functions about clock
*/

#include "game.h"

void analyse_clocks(window_td *window, sprite_td *sprite, clock_td *clock,
sound_td *sound)
{
    if (clock->player_anim <= 4) {
        sprite->player_rect = change_rect(sprite->player_rect, 0, 0);
        sfSprite_setTextureRect(sprite->player, sprite->player_rect);
    }
    if (clock->player_anim > 4) {
        sprite->player_rect = change_rect(sprite->player_rect, 150, 150);
        sfSprite_setTextureRect(sprite->player, sprite->player_rect);
    }
    if (clock->player_anim > 4.1)
        sfClock_restart(clock->clock_player_anim);
    return;
}

clock_td *set_time(clock_td *clock)
{
    clock->time_player_anim = sfClock_getElapsedTime(clock->clock_player_anim);
    clock->player_anim = clock->time_player_anim.microseconds / 1000000.0;
    return clock;
}

clock_td *all_clocks(void)
{
    clock_td *clock = malloc(sizeof(clock_td));

    clock->clock_player_anim = sfClock_create();
    return clock;
}
