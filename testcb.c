#include "types.h"
#include "user.h"

void testfunc(void) {
  printf(1, "Funkcja wykonana przez dziecko!\n");
  exitcb(); // Powrót do oryginalnego kodu
}

int main() {
  int pid;

  printf(1, "Proces nadrzedny nie ustawia funkcji\n");
  pid = fork();
  if (pid == 0) {
    printf(1, "Proces podrzedny bez funkcji\n");
    exit();
  }
  wait();

  printf(1, "Proces nadrzedny ustawia funkcje\n");
  forkcb(&testfunc);
  pid = fork();
  if (pid == 0) {
    printf(1, "Proces podrzędny z funkcja\n");
    exit();
  }
  wait();

  printf(1, "Test zakonczony\n");
  exit();
}