/*
** EPITECH PROJECT, 2019
** tree
** File description:
** displays a christmas tree
*/

#include <stdio.h>

void calc_last_line(int height, int delta_size, int size);
void load_tree(int top_size, int max_bot_size, int delta_size, int size);
void log_tree(int size, int max_bot_size);
void disp_tree(int spaces, int top_size);
char my_putchar(char c);

void tree(int size)
{
    int height = 4;
    int top_size = 1;
    int bot_size = 7;
    int delta_size = 0;
    
    calc_last_line(height, delta_size, size);
}

void calc_last_line(int height, int delta_size, int size)
{
    int top_size;
    int max_bot_size = 7;
    
    for (int i = 1; i < size; i++){
        if (i % 2 == 1)
            delta_size += 2;
        top_size = max_bot_size - delta_size;
        max_bot_size = top_size + (height * 2);
        height++;
    }
    load_tree(top_size, max_bot_size, delta_size, size);
    log_tree(size, max_bot_size);
}

void load_tree(int top_size, int max_bot_size, int delta_size, int size)
{
    int spaces = (max_bot_size - 1) / 2;
    int height = 4;
    int delta_spaces = 0;

    delta_size = 0;
    top_size = 1;
    for (int h = 0; h < size; h++){
        for (int i = 0; i < height; i++){
            disp_tree(spaces, top_size);
            spaces--;
            top_size += 2;
        }
        top_size -= 4;
        if (h % 2 == 0 && h != 0){
            delta_spaces++;
            delta_size += 2;
        }
        spaces = spaces + 2 + delta_spaces;
        height++;
        top_size = top_size - delta_size;
    }
}

void disp_tree(int spaces, int top_size)
{
    for (int j = 0; j < spaces; j++){
        my_putchar(' ');
    }
    for (int k = 0; k < top_size; k++){
        my_putchar('*');
    }
    my_putchar('\n');
}

void log_tree(int size, int max_bot_size)
{
    int log_width;
    int log_height = size;
    int spaces;

    if (size % 2 == 1){
        log_width = size;
    } else if (size % 2 == 0){
        log_width = size + 1;
    }
    spaces = ((max_bot_size - 1) / 2) - ((log_width - 1) / 2);
    for (int i = 0; i < log_height; i++){
        for (int j = 0; j < spaces; j++){
            my_putchar(' ');
        }
        for (int k = 0; k < log_width; k++){
            my_putchar('|');
        }
        my_putchar('\n');
    }
}
