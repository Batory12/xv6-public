#include "types.h"
#include "user.h"
#include "mmu.h"
int main () {
    sbrk(5*PGSIZE);
    exit();
}