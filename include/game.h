/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** call all functions needed by game
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Cursor.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>

#ifndef GAME_H_
    #define GAME_H_

typedef struct window_s {
    int state;
    sfEvent event;
    sfRenderWindow *window;
    int count;
    sfText *count_text;
    sfFont *count_font;
    char *count_buf;
} window_td;

typedef struct sprite_s {
    sfSprite *cursor;
    sfVector2f cursor_pos;
    sfSprite *player;
    sfSprite *bg0;
} sprite_td;

typedef struct clock_s {
} clock_td;

typedef struct sound_s {
    sfMusic *music1;
    sfSound *click0;
    sfSoundBuffer *click0_buf;
} sound_td;

sfIntRect change_rect(sfIntRect rect, int left, int left_max);
sfIntRect create_rect(int width, int height);
sfSprite *set_pos(sfSprite *sprite, float x, float y);
void is_jump(window_td *window, clock_td *clock, sprite_td *sprite,
sound_td *sound);
void is_crouch(window_td *window, sprite_td *sprite, clock_td *clock, char c);
int got_hit(window_td *window, sprite_td *sprite);
void parallaxe(sprite_td *sprite);
void analyse_events(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound);
void analyse_clocks(window_td *window, sprite_td *sprite, clock_td *clock,
sound_td *sound);
void display(window_td *window, sprite_td *sprite);
void destroy_sounds(sound_td *sound);
void play_sounds(sound_td *sound);
sound_td *all_sounds(void);
clock_td *set_time(clock_td *clock);
clock_td *all_clocks(void);
sfVector2f get_offset(float x, float y);
void move_background(sprite_td *sprite);
sfSprite *create_sprite(char *path_texture);
sprite_td *all_sprites(void);
void get_count(sfText *text, int count);
sfRenderWindow *create_window(char *title, sfEvent event);
window_td *set_window(void);
int usage(void);

#endif
