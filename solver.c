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
    FILL
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

Piece init_l_shape(int direction, unsigned int width, unsigned int height, char *color)
{
    Piece l_shape;

    l_shape.x = (direction == UP || direction == DOWN) ? width : height;
    l_shape.y = (direction == UP || direction == DOWN) ? height : width;

    l_shape.shape = (Cell **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (Cell *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j].status = FILL;
        }
    }
    if (direction == UP)
    {
        for (size_t i = 0; i < l_shape.y - 1; i++)
        {
            for (size_t j = 0; j < l_shape.x - 1; j++)
            {
                l_shape.shape[i][j].status = EMPTY;
            }
        }
    }
    else if (direction == DOWN)
    {
        for (size_t i = 1; i < l_shape.y; i++)
        {
            for (size_t j = 1; j < l_shape.x; j++)
            {
                l_shape.shape[i][j].status = EMPTY;
            }
        }
    }
    else if (direction == LEFT)
    {
        for (size_t i = 1; i < l_shape.y; i++)
        {
            for (size_t j = 0; j < l_shape.x - 1; j++)
            {
                l_shape.shape[i][j].status = EMPTY;
            }
        }
    }
    else if (direction == RIGHT)
    {
        for (size_t i = 0; i < l_shape.y - 1; i++)
        {
            for (size_t j = 1; j < l_shape.x; j++)
            {
                l_shape.shape[i][j].status = EMPTY;
            }
        }
    }
    else
    {
        fprintf(stderr, "Unknown direction: %d\n", direction);
        exit(1);
    }

    l_shape.direction = direction;

    l_shape.color = color;

    return l_shape;
}

Piece init_b_shape(int direction)
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
            l_shape.shape[i][j].status = FILL;
        }
    }
    if (direction == UP)
    {

        l_shape.shape[0][0].status = EMPTY;
    }
    else if (direction == DOWN)
    {
        l_shape.shape[2][2].status = EMPTY;
    }
    else if (direction == LEFT)
    {
        l_shape.shape[1][0].status = EMPTY;
    }
    else if (direction == RIGHT)
    {
        l_shape.shape[0][2].status = EMPTY;
    }
    else
    {
        fprintf(stderr, "Unknown direction: %d\n", direction);
        exit(1);
    }

    l_shape.direction = direction;

    l_shape.color = COLOR_BLUE;

    return l_shape;
}

Piece init___shape(int direction)
{
    Piece l_shape;

    l_shape.x = (direction == UP || direction == DOWN) ? 1 : 4;
    l_shape.y = (direction == UP || direction == DOWN) ? 4 : 1;

    l_shape.shape = (Cell **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (Cell *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j].status = FILL;
        }
    }

    l_shape.direction = direction;

    l_shape.color = COLOR_GREEN;

    return l_shape;
}

Piece init_t_shape(int direction)
{
    Piece l_shape;

    l_shape.x = (direction == UP || direction == DOWN) ? 2 : 4;
    l_shape.y = (direction == UP || direction == DOWN) ? 4 : 2;

    l_shape.shape = (Cell **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (Cell *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j].status = FILL;
        }
    }

    switch (direction)
    {
    case UP:
        l_shape.shape[0][0].status = EMPTY;
        l_shape.shape[1][0].status = EMPTY;
        l_shape.shape[3][0].status = EMPTY;
        break;
    case DOWN:
        l_shape.shape[0][1].status = EMPTY;
        l_shape.shape[2][1].status = EMPTY;
        l_shape.shape[3][1].status = EMPTY;
        break;
    case LEFT:
        l_shape.shape[1][0].status = EMPTY;
        l_shape.shape[1][1].status = EMPTY;
        l_shape.shape[1][3].status = EMPTY;
        break;
    case RIGHT:
        l_shape.shape[0][0].status = EMPTY;
        l_shape.shape[0][2].status = EMPTY;
        l_shape.shape[0][3].status = EMPTY;
        break;
    default:
        break;
    }

    l_shape.direction = direction;

    l_shape.color = COLOR_CYAN;

    return l_shape;
}

Piece init_rod_shape(int direction)
{
    Piece l_shape;

    l_shape.x = (direction == UP || direction == DOWN) ? 2 : 4;
    l_shape.y = (direction == UP || direction == DOWN) ? 4 : 2;

    l_shape.shape = (Cell **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (Cell *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j].status = FILL;
        }
    }

    switch (direction)
    {
    case UP:
        l_shape.shape[0][0].status = EMPTY;
        l_shape.shape[1][0].status = EMPTY;
        l_shape.shape[3][1].status = EMPTY;
        break;
    case DOWN:
        l_shape.shape[0][0].status = EMPTY;
        l_shape.shape[2][1].status = EMPTY;
        l_shape.shape[3][1].status = EMPTY;
        break;
    case LEFT:
        l_shape.shape[1][0].status = EMPTY;
        l_shape.shape[1][1].status = EMPTY;
        l_shape.shape[0][3].status = EMPTY;
        break;
    case RIGHT:
        l_shape.shape[1][0].status = EMPTY;
        l_shape.shape[0][2].status = EMPTY;
        l_shape.shape[0][3].status = EMPTY;
        break;
    default:
        break;
    }

    l_shape.direction = direction;

    l_shape.color = COLOR_WHITE;

    return l_shape;
}

Piece init_u_shape(int direction)
{
    Piece l_shape;

    l_shape.x = (direction == UP || direction == DOWN) ? 3 : 2;
    l_shape.y = (direction == UP || direction == DOWN) ? 2 : 3;

    l_shape.shape = (Cell **)malloc(l_shape.x * l_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < l_shape.y; i++)
    {
        l_shape.shape[i] = (Cell *)malloc(l_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < l_shape.y; i++)
    {
        for (size_t j = 0; j < l_shape.x; j++)
        {
            l_shape.shape[i][j].status = FILL;
        }
    }

    switch (direction)
    {
    case UP:
        l_shape.shape[0][1].status = EMPTY;
        break;
    case DOWN:
        l_shape.shape[1][1].status = EMPTY;
        break;
    case LEFT:
        l_shape.shape[1][0].status = EMPTY;
        break;
    case RIGHT:
        l_shape.shape[1][1].status = EMPTY;
        break;
    default:
        break;
    }

    l_shape.direction = direction;

    l_shape.color = COLOR_GRAY;

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
            plus_shape.shape[i][j].status = FILL;
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

Piece init_square_shape()
{
    Piece plus_shape;

    plus_shape.x = 2;
    plus_shape.y = 2;

    plus_shape.shape = (Cell **)malloc(plus_shape.x * plus_shape.y * sizeof((Piece){}.shape[0]));
    for (size_t i = 0; i < plus_shape.y; i++)
    {
        plus_shape.shape[i] = (Cell *)malloc(plus_shape.x * sizeof((Piece){}.shape[0][0]));
    }

    for (size_t i = 0; i < plus_shape.y; i++)
    {
        for (size_t j = 0; j < plus_shape.x; j++)
        {
            plus_shape.shape[i][j].status = FILL;
        }
    }

    plus_shape.direction = UP;

    plus_shape.color = COLOR_LIGHT_GREEN;

    return plus_shape;
}

void print_board()
{

    for (int y = 0; y < BOARD_Y_BOUND; y++)
    {
        for (int i = 0; i < BOARD_X_BOUND * 4 + 1; i++)
        {
            printf("-");
        }
        printf("\n");

        for (int x = 0; x < BOARD_X_BOUND; x++)
        {
            printf("| "
                   "%s"
                   "%c " COLOR_RESET,
                   board[y][x].color, board[y][x].status == EMPTY ? ' ' : '@');
        }
        printf("|\n");
    }

    for (int i = 0; i < BOARD_X_BOUND * 4 + 1; i++)
    {
        printf("-");
    }
    printf("\n");
}

void print_piece(Piece piece)
{

    for (unsigned int y = 0; y < piece.y; y++)
    {
        for (unsigned int i = 0; i < piece.x * 4 + 1; i++)
        {
            printf("-");
        }
        printf("\n");

        for (unsigned int x = 0; x < piece.x; x++)
        {
            printf("| "
                   "%s"
                   "%c " COLOR_RESET,
                   piece.color, piece.shape[y][x].status == EMPTY ? ' ' : '@');
        }
        printf("|\n");
    }

    for (unsigned int i = 0; i < piece.x * 4 + 1; i++)
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
            if (board[i][j].status == FILL && piece.shape[i - y][j - x].status == FILL)
            {
                fprintf(stderr, "Can't place piece on piece.\n");
                exit(1);
            }
            else if (board[i][j].status == FILL && piece.shape[i - y][j - x].status == EMPTY)
            {
                continue;
            }

            else
            {
                board[i][j].status = piece.shape[i - y][j - x].status;
                board[i][j].color = piece.color;
            }
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

    Piece l2_shape = init_l_shape(RIGHT, 2, 2, COLOR_MELLOW_PINK);
    Piece l3_shape = init_l_shape(RIGHT, 2, 3, COLOR_PINK);
    Piece l4_shape = init_l_shape(UP, 2, 4, COLOR_YELLOW);
    Piece L_shape = init_l_shape(LEFT, 3, 3, COLOR_ORANGE);
    Piece plus_shape = init_plus_shape();
    Piece __shape = init___shape(RIGHT);
    Piece b_shape = init_b_shape(RIGHT);
    Piece square_shape = init_square_shape();
    Piece u_shape = init_u_shape(LEFT);
    Piece t_shape = init_t_shape(LEFT);
    Piece rod_shape = init_rod_shape(RIGHT);

    put_piece(l2_shape, 6, 3);
    put_piece(l3_shape, 0, 1);
    put_piece(l4_shape, 4, 1);
    put_piece(L_shape, 2, 0);
    put_piece(plus_shape, 2, 2);
    put_piece(__shape, 5, 0);
    put_piece(b_shape, 0, 3);
    put_piece(square_shape, 9, 3);
    put_piece(u_shape, 9, 0);
    put_piece(t_shape, 6, 1);
    put_piece(rod_shape, 0, 0);

    print_board();

    printf("\n");
    print_piece(plus_shape);
    printf("\n");
    print_piece(l3_shape);
    printf("\n");
    print_piece(__shape);
    printf("\n");
    print_piece(l4_shape);
    printf("\n");
    print_piece(l2_shape);
    printf("\n");
    print_piece(L_shape);
    printf("\n");
    print_piece(b_shape);
    printf("\n");
    print_piece(square_shape);
    printf("\n");
    print_piece(u_shape);
    printf("\n");
    print_piece(t_shape);
    printf("\n");
    print_piece(rod_shape);

    return 0;
}
