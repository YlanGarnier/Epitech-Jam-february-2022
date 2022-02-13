/*
** EPITECH PROJECT, 2021
** sprite
** File description:
** return a sprite linked to texture given in parameter
*/

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
    sfSprite_scale(sprite->cursor, get_offset(0.8, 0.8));
    sprite->player = create_sprite("assets/homeless.png");
    sprite->player_rect = create_rect(150, 150);
    sfSprite_setTextureRect(sprite->player, sprite->player_rect);
    sfSprite_scale(sprite->player, get_offset(3, 3));
    set_pos(sprite->player, 550, 550);
    sprite->bg0 = create_sprite("assets/bg0.png");
    return sprite;
}
