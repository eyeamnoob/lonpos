#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "color.h"

#define BOARD_X_BOUND 11
#define BOARD_Y_BOUND 5
#define FULL_SYMBOL '@'
#define EMPTY_SYMBOL ' '

typedef struct
{
    char *color;
    bool status;
} Cell;

static Cell board[BOARD_Y_BOUND][BOARD_X_BOUND] = {0};

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

Piece init_l_shape(int direction)
{
    Piece l_shape;

    l_shape.x = (direction == UP || direction == DOWN) ? 2 : 3;
    l_shape.y = (direction == UP || direction == DOWN) ? 3 : 2;

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
    if (direction == UP)
    {
        l_shape.shape[0][0].status = EMPTY;
        l_shape.shape[1][0].status = EMPTY;
    }
    else if (direction == DOWN)
    {
        l_shape.shape[1][1].status = EMPTY;
        l_shape.shape[2][1].status = EMPTY;
    }
    else if (direction == LEFT)
    {
        l_shape.shape[1][0].status = EMPTY;
        l_shape.shape[1][1].status = EMPTY;
    }
    else if (direction == RIGHT)
    {
        l_shape.shape[0][1].status = EMPTY;
        l_shape.shape[0][2].status = EMPTY;
    }
    else
    {
        fprintf(stderr, "Unknown direction: %d\n", direction);
        exit(1);
    }

    l_shape.direction = direction;

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

    for (int y = 0; y < BOARD_Y_BOUND; y++)
    {
        for (int i = 0; i < BOARD_X_BOUND * 2 + 1; i++)
        {
            printf("-");
        }
        printf("\n");

        for (int x = 0; x < BOARD_X_BOUND; x++)
        {
            printf("|"
                   "%s"
                   "%c" COLOR_RESET,
                   board[y][x].color, board[y][x].status == EMPTY ? ' ' : '@');
        }
        printf("|\n");
    }

    for (int i = 0; i < BOARD_X_BOUND * 2 + 1; i++)
    {
        printf("-");
    }
    printf("\n");
}

void print_piece(Piece piece)
{

    for (unsigned int y = 0; y < piece.y; y++)
    {
        for (unsigned int i = 0; i < piece.x * 2 + 1; i++)
        {
            printf("-");
        }
        printf("\n");

        for (unsigned int x = 0; x < piece.x; x++)
        {
            printf("|"
                   "%s"
                   "%c" COLOR_RESET,
                   piece.color, piece.shape[y][x].status == EMPTY ? ' ' : '@');
        }
        printf("|\n");
    }

    for (unsigned int i = 0; i < piece.x * 2 + 1; i++)
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
    for (size_t i = 0; i < BOARD_Y_BOUND; i++)
    {
        for (size_t j = 0; j < BOARD_X_BOUND; j++)
        {
            board[i][j].status = EMPTY;
            board[i][j].color = COLOR_WHITE;
        }
    }
}

void rotate_piece(Piece input, Piece output)
{
    unsigned int y = input.y;
    unsigned int x = input.x;

    for (unsigned int i = 0; i < y; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            output.shape[j][y - 1 - i] = input.shape[i][j];
        }
    }
}

int main()
{
    init_board();

    Piece l_shape = init_l_shape(RIGHT);
    Piece plus_shape = init_plus_shape();

    Piece rotated_l_shape = init_l_shape(DOWN);

    put_piece(l_shape, 0, 0);
    put_piece(plus_shape, 3, 0);
    put_piece(rotated_l_shape, 0, 2);
    print_board();

    printf("\n");
    print_piece(plus_shape);
    printf("\n");
    print_piece(l_shape);
    printf("\n");
    print_piece(rotated_l_shape);

    return 0;
}
