#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int i;
    int n = 1;
    for(i = 0; i < n; i++) {
        printf(1, "Fizyczne: %d wirtualne: %d\n", usedpp(), usedvp());
        int* n = (int*)mmap(4096);
        printf(1, "mmap(4096).\nFizyczne: %d wirtualne: %d\n Teraz powinnismy dostac page faulta.", usedpp(), usedvp());
        printf(1, "n: %d\n", *n);
    }
    exit();
}