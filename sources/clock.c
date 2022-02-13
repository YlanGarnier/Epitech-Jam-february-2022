/*
** EPITECH PROJECT, 2021
** clock
** File description:
** all functions about clock
*/

#include "game.h"

void check_player_unzoom(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    if (sprite->player_unzoom == 1 && clock->player_unzoom <= 0.01)
        sfSprite_move(sprite->player, get_offset(0, -2));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.01 && clock->player_unzoom <= 0.02)
        sfSprite_move(sprite->player, get_offset(0, -1.8));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.02 && clock->player_unzoom <= 0.03)
        sfSprite_move(sprite->player, get_offset(0, -1.6));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.03 && clock->player_unzoom <= 0.04)
        sfSprite_move(sprite->player, get_offset(0, -1.4));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.04 && clock->player_unzoom <= 0.05)
        sfSprite_move(sprite->player, get_offset(0, 1.4));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.05 && clock->player_unzoom <= 0.06)
        sfSprite_move(sprite->player, get_offset(0, 1.6));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.06 && clock->player_unzoom <= 0.07)
        sfSprite_move(sprite->player, get_offset(0, 1.8));
    if (sprite->player_unzoom == 1 && clock->player_unzoom > 0.07) {
        sprite->player_unzoom = 0;
        set_pos(sprite->player, 550, 550);
    }
}

void anim_stage_0(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    if (window->lvl == 0 && clock->player_anim <= 4) {
	sprite->player_rect = change_rect(sprite->player_rect, 0, 0);
        sfSprite_setTextureRect(sprite->player, sprite->player_rect);
    }
    if (window->lvl == 0 && clock->player_anim > 4) {
        sprite->player_rect = change_rect(sprite->player_rect, 150, 150);
        sfSprite_setTextureRect(sprite->player, sprite->player_rect);
    }
    if (window->lvl == 0 && clock->player_anim > 4.2)
        sfClock_restart(clock->clock_player_anim);
    if (window->lvl >= 5 && clock->gorilla_anim >= 0.2) {
        sprite->gorilla_rect = change_rect(sprite->gorilla_rect, 125, 125);
        sfSprite_setTextureRect(sprite->gorilla, sprite->gorilla_rect);
        sfClock_restart(clock->clock_gorilla_anim);
    }
}

void analyse_clocks(window_td *window, sprite_td *sprite, clock_td *clock,
sound_td *sound)
{
    check_player_unzoom(window, sprite, clock, sound);
    anim_stage_0(window, sprite, clock, sound);
    if (window->lvl != 0 && clock->player_anim >= 0.5) {
        sprite->player_rect = change_rect(sprite->player_rect, 150, sprite->player_max);
        sfSprite_setTextureRect(sprite->player, sprite->player_rect);
        sfClock_restart(clock->clock_player_anim);
    }
    if (sound->click_played == 1 && clock->click_sound >= 0.1) {
        sound->click_played = 0;
        sfClock_restart(clock->clock_click_sound);
    }
    return;
}

clock_td *set_time(clock_td *clock)
{
    clock->time_player_anim = sfClock_getElapsedTime(clock->clock_player_anim);
    clock->player_anim = clock->time_player_anim.microseconds / 1000000.0;
    clock->time_gorilla_anim = sfClock_getElapsedTime(clock->clock_gorilla_anim);
    clock->gorilla_anim = clock->time_gorilla_anim.microseconds / 1000000.0;
    clock->time_player_unzoom = sfClock_getElapsedTime(clock->clock_player_unzoom);
    clock->player_unzoom = clock->time_player_unzoom.microseconds / 1000000.0;
    clock->time_click_sound = sfClock_getElapsedTime(clock->clock_click_sound);
    clock->click_sound = clock->time_click_sound.microseconds / 1000000.0;
    return clock;
}

clock_td *all_clocks(void)
{
    clock_td *clock = malloc(sizeof(clock_td));

    clock->clock_player_anim = sfClock_create();
    clock->clock_gorilla_anim = sfClock_create();
    clock->clock_player_unzoom = sfClock_create();
    clock->clock_click_sound = sfClock_create();
    return clock;
}
