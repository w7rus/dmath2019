// functions.cpp
//

#include <iostream>
#include "functions.hpp"
#ifdef _WIN32
    #include <stdint.h>
    #include <stdlib.h>
#endif
int gen_int(int min, int max)
    {
        return min + rand() % (max + 1 - min);
    }

void swap_int(int* a, int* b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

bool gen_arraySet(int* array, int arraySize)
    {
        int j = arraySize - 2;

        for (;j != -1 && array[j] >= array[j + 1];)
            j--;

        if (j == -1)
            return false;

        int k = arraySize - 1;

        for (;array[j] >= array[k];)
            k--;

        swap_int(&array[j], &array[k]);

        int l = j + 1;
        int r = arraySize - 1;
        for (;l < r;)
            swap_int(&array[l++], &array[r--]);

        return true;
    }

#ifdef _WIN32
    #include <Windows.h>
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
#elif __linux
    #include <sys/ioctl.h>
    #include <termios.h>
    #include <unistd.h>
#endif
void term_getDim(uint8_t* width, uint8_t* height)
    {
        #ifdef _WIN32
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
            *width = csbi.dwSize.X;
            *height = csbi.dwSize.Y;
        #elif __linux
            struct winsize size;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
            *width = size.ws_col - 1;
            *height = size.ws_row - 1;
        #endif
    }
void term_clear()
    {
        #ifdef _WIN32
            HANDLE                     hStdOut;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            DWORD                      count;
            DWORD                      cellCount;
            COORD                      homeCoords = { 0, 0 };

            hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hStdOut == INVALID_HANDLE_VALUE) return;

            /* Get the number of cells in the current buffer */
            if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
            cellCount = csbi.dwSize.X *csbi.dwSize.Y;

            /* Fill the entire buffer with spaces */
            if (!FillConsoleOutputCharacter(
                hStdOut,
                (TCHAR) ' ',
                cellCount,
                homeCoords,
                &count
            )) return;

            /* Fill the entire buffer with the current colors and attributes */
            if (!FillConsoleOutputAttribute(
                hStdOut,
                csbi.wAttributes,
                cellCount,
                homeCoords,
                &count
            )) return;

            /* Move the cursor home */
            SetConsoleCursorPosition(hStdOut, homeCoords);
        #elif __linux
            std::cout<<"\033[2J";
        #endif
    }