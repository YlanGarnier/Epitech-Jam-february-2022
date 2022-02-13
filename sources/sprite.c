/*
** EPITECH PROJECT, 2021
** sprite
** File description:
** return a sprite linked to texture given in parameter
*/

#include <string.h>
#include "game.h"

sfSprite *create_sprite(char *path_texture)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path_texture, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

sprite_td *all_sprites(void)
{
    sprite_td *sprite = malloc(sizeof(sprite_td));

    sprite->cursor = create_sprite("assets/cursor.png");
    sprite->bg_path = strdup("assets/bg0.png");
    sprite->bg = create_sprite(sprite->bg_path);
    sfSprite_scale(sprite->cursor, get_offset(0.8, 0.8));
    sprite->player_max = 450;
    sprite->player_unzoom = 0;
    sprite->player_path = strdup("assets/player0.png");
    sprite->player = create_sprite(sprite->player_path);
    sprite->player_rect = create_rect(150, 150);
    sfSprite_setTextureRect(sprite->player, sprite->player_rect);
    sfSprite_scale(sprite->player, get_offset(3, 3));
    set_pos(sprite->player, 550, 550);
    sprite->gorilla = create_sprite("assets/gorilla.png");
    sprite->gorilla_rect = create_rect(125, 75);
    sfSprite_scale(sprite->gorilla, get_offset(8, 8));
    sfSprite_setTextureRect(sprite->gorilla, sprite->gorilla_rect);
    set_pos(sprite->gorilla, 800, 325);
    return sprite;
}
