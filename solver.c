#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAP_X_BOUND 11
#define MAP_Y_BOUND 5

static unsigned char board[MAP_Y_BOUND][MAP_X_BOUND] = {0};

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
    unsigned char **shape;
    int direction;
    unsigned int x;
    unsigned int y;
    char color[32];
} Piece;

Piece init_l_shape()
{
    Piece l_shape;

    l_shape.x = 2;
    l_shape.y = 3;

    l_shape.shape = (unsigned char **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (unsigned char *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j] = FULL;
        }
    }
    l_shape.shape[0][0] = EMPTY;
    l_shape.shape[1][0] = EMPTY;

    l_shape.direction = UP;

    return l_shape;
}

Piece init_plus_shape()
{
    Piece plus_shape;

    plus_shape.x = 3;
    plus_shape.y = 3;

    plus_shape.shape = (unsigned char **)malloc(plus_shape.x * plus_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < plus_shape.y; i++)
    {
        plus_shape.shape[i] = (unsigned char *)malloc(plus_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < plus_shape.y; i++)
    {
        for (size_t j = 0; j < plus_shape.x; j++)
        {
            plus_shape.shape[i][j] = FULL;
        }
    }
    plus_shape.shape[0][0] = EMPTY;
    plus_shape.shape[0][2] = EMPTY;
    plus_shape.shape[2][0] = EMPTY;
    plus_shape.shape[2][2] = EMPTY;

    plus_shape.direction = UP;

    return plus_shape;
}

void print_map()
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
            printf("|\e[0;31m%c\e[0m", board[y][x] == EMPTY ? ' ' : '@');
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
            board[i][j] = piece.shape[i - y][j - x];
        }
    }
}

int main()
{
    system("");

    memset(board, EMPTY, sizeof board);

    Piece l_shape = init_l_shape();
    Piece plus_shape = init_plus_shape();

    put_piece(l_shape, 0, 0);
    put_piece(plus_shape, 3, 0);
    print_map();

    return 0;
}
