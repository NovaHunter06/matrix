#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // ANSI Escape Code for Green text: \033[1;32m
    printf("\033[1;32m");

    while (1) {
        // Generate a random character between ASCII 33 ('!') and 126 ('~')
        char c = (rand() % 94) + 33;

        // Randomly decide to print a space or a character to create "columns"
        if (rand() % 10 > 7) {
            printf("%c  ", c);
        } else {
            printf("   ");
        }

        // Occasionally reset the line or add extra spacing
        if (rand() % 50 == 0) {
            printf("\n");
        }

        fflush(stdout);
        SLEEP_MS(10); // Adjust this to change the "speed" of the fall
    }

    return 0;
}
