#include "Canvas.h"
#include <stdio.h>     
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>

Canvas::Canvas(int lines, int columns) : lines(lines), columns(columns) {
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x < 0 || x >= lines || y < 0 || y >= columns) {
        printf("Eroare, ati depasit valoarea!!");
            return;
        }
     else if ((x >= 0) && (x < lines) && (y >= 0) && (y < columns)) {
        canvas[x][y] = value;
    }
}

void Canvas::set_pixels(int count, ...) {
    if ( canvas != nullptr) {
        va_list vl;
        va_start(vl, count); //vl variabila si dupa nr de elemente
        for (int i = 0; i < count; ++i) {
            int x = va_arg(vl, int); int y = va_arg(vl, int);
            char value = static_cast<char>(va_arg(vl, int));
            set_pixel(x, y, value);
        }

        va_end(vl);
    }
}

void Canvas::clear() {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::print() const {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}
