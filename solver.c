#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "color.h"

#define MAP_X_BOUND 11
#define MAP_Y_BOUND 5
#define FULL_SYMBOL '@'
#define EMPTY_SYMBOL ' '

typedef struct
{
    char *color;
    bool status;
} Cell;

static Cell board[MAP_Y_BOUND][MAP_X_BOUND] = {0};

enum CellStatus
{
    EMPTY,
    FULL
};

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct
{
    Cell **shape;
    int direction;
    unsigned int x;
    unsigned int y;
    char *color;
} Piece;

Piece init_l_shape()
{
    Piece l_shape;

    l_shape.x = 2;
    l_shape.y = 3;

    l_shape.shape = (Cell **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (Cell *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j].status = FULL;
        }
    }
    l_shape.shape[0][0].status = EMPTY;
    l_shape.shape[1][0].status = EMPTY;

    l_shape.direction = UP;

    l_shape.color = COLOR_RED;

    return l_shape;
}

Piece init_plus_shape()
{
    Piece plus_shape;

    plus_shape.x = 3;
    plus_shape.y = 3;

    plus_shape.shape = (Cell **)malloc(plus_shape.x * plus_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < plus_shape.y; i++)
    {
        plus_shape.shape[i] = (Cell *)malloc(plus_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < plus_shape.y; i++)
    {
        for (size_t j = 0; j < plus_shape.x; j++)
        {
            plus_shape.shape[i][j].status = FULL;
        }
    }
    plus_shape.shape[0][0].status = EMPTY;
    plus_shape.shape[0][2].status = EMPTY;
    plus_shape.shape[2][0].status = EMPTY;
    plus_shape.shape[2][2].status = EMPTY;

    plus_shape.direction = UP;

    plus_shape.color = COLOR_PURPLE;

    return plus_shape;
}

void print_board()
{

    for (int y = 0; y < MAP_Y_BOUND; y++)
    {
        for (int i = 0; i < MAP_X_BOUND * 2 + 1; i++)
        {
            printf("-");
        }
        printf("\n");

        for (int x = 0; x < MAP_X_BOUND; x++)
        {
            printf("|"
                   "%s"
                   "%c" COLOR_RESET,
                   board[y][x].color, board[y][x].status == EMPTY ? ' ' : '@');
        }
        printf("|\n");
    }

    for (int i = 0; i < MAP_X_BOUND * 2 + 1; i++)
    {
        printf("-");
    }
    printf("\n");
}

void put_piece(Piece piece, int x, int y)
{
    int x_bound = x + piece.x;
    int y_bound = y + piece.y;

    for (int i = y; i < y_bound; i++)
    {
        for (int j = x; j < x_bound; j++)
        {
            board[i][j].status = piece.shape[i - y][j - x].status;
            board[i][j].color = piece.color;
        }
    }
}

void init_board()
{
    for (size_t i = 0; i < MAP_Y_BOUND; i++)
    {
        for (size_t j = 0; j < MAP_X_BOUND; j++)
        {
            board[i][j].status = EMPTY;
            board[i][j].color = COLOR_WHITE;
        }
    }
}

int main()
{
    init_board();

    Piece l_shape = init_l_shape();
    Piece plus_shape = init_plus_shape();

    put_piece(l_shape, 0, 0);
    put_piece(plus_shape, 3, 0);
    print_board();

    return 0;
}
