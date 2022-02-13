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
    int lvl;
    int textures_updated;
    int multiplier;
    sfText *count_text;
    sfFont *count_font;
    char *count_buf;
    sfText *quote_text;
    sfFont *quote_font;
} window_td;

typedef struct sprite_s {
    sfSprite *cursor;
    sfVector2f cursor_pos;
    char *player_path;
    sfSprite *player;
    sfIntRect player_rect;
    int player_max;
    int player_unzoom;
    char *bg_path;
    sfSprite *bg;
    sfSprite *gorilla;
    sfIntRect gorilla_rect;
} sprite_td;

typedef struct clock_s {
    sfClock *clock_player_anim;
    sfTime time_player_anim;
    float player_anim;
    sfClock *clock_gorilla_anim;
    sfTime time_gorilla_anim;
    float gorilla_anim;
    sfClock *clock_player_unzoom;
    sfTime time_player_unzoom;
    float player_unzoom;
    sfClock *clock_click_sound;
    sfTime time_click_sound;
    float click_sound;
} clock_td;

typedef struct sound_s {
    sfMusic *music;
    char *click_path;
    sfSoundBuffer *click_buf;
    sfSound *click;
    sfSoundBuffer *yeah_buf;
    sfSound *yeah;
    sfSoundBuffer*gorilla_buf;
    sfSound *gorilla;
    int click_played;
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
void update_textures(window_td *window, sprite_td *sprite, sound_td *sound);
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
