//expr.c
//Add to makefile: EXTRA, UPROGS.
#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
  if(argc != 4){
    printf(1, "Usage: expr a <operator> b \n");
    exit();
  }
  int a = atoi(argv[1]);    
  int b = atoi(argv[3]);
  switch (argv[2][0]){
    case '+':
        printf(1, "%d\n", a+b);
        break;
    case '-':
        printf(1, "%d\n", a-b);
        break;
    case '*':
        printf(1, "%d\n", a*b);
        break;
    case '/':
        if(b == 0){
            printf(1, "Division by zero\n");
            break;
        }
        printf(1, "%d\n", a/b);
        break;
    case '%':
        if(b == 0){
            printf(1, "Division by zero\n");
            break;
        }
        printf(1, "%d\n", a%b);
        break;
    default:
        printf(1, "Unknown operator\n");
        break;
  }
  exit();
}