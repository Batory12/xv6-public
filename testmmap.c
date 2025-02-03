#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int i;
    int n = 1;
    for(i = 0; i < n; i++) {
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        printf(1, "przydzielamy 5 stron\n");
        char* n = (char*)mmap(5*4096);
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        printf(1, "Teraz probujemy czytac ze stron, ktore beda przydzielone na zadanie.\n");
        *n = 'A';
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        *(n+4096) = 'B';
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        *(n+8192) = 'C';
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        *(n+12288) = 'D';
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        *(n+16384) = 'E';
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        printf(1, "Teraz probujemy czytac ze stron, ktore nie naleza do procesu.\n");
        *(n+20480) = 'F';

    }
    exit();
}