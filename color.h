#ifndef MY_COLOR_H
#define MY_COLOR_H

#define COLOR_RGB(r, g, b) "\e[38;2;" #r ";" #g ";" #b "m"

#define COLOR_RED COLOR_RGB(255, 0, 0)
#define COLOR_GREEN COLOR_RGB(0, 255, 0)
#define COLOR_LIGHT_GREEN COLOR_RGB(100, 255, 100)
#define COLOR_YELLOW COLOR_RGB(255, 255, 0)
#define COLOR_ORANGE COLOR_RGB(255, 100, 0)
#define COLOR_BLUE COLOR_RGB(0, 0, 255)
#define COLOR_PURPLE "\e[0;35m"
#define COLOR_CYAN "\e[0;36m"
#define COLOR_PINK COLOR_RGB(255, 0, 255)
#define COLOR_MELLOW_PINK COLOR_RGB(255, 100, 255)

#define COLOR_WHITE "\e[0;37m"
#define COLOR_BLACK "\e[0;30m"

#define COLOR_RESET "\e[0m"

#endif