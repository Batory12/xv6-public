#include "types.h"
#include "user.h"
//sleep(1) - śpi przez 1 tick procesora, także to takie yield() którego nie moge uzyc z jakiegos powodu.
int main () {
    const int N = 60;
    for(int i = 1; i <= N; i++) {
        int pid = fork();
        if(pid == 0) {
            int l;
            if(i%3==1) {
                l = 50;
                setprio(1000);
            }
            else if(i%3==2) {
                l = 30;
                setprio(1000);
            }
            else {
                l = 30;
                setprio(200);
            }
            for(int j = 0; j < l; j++) {
                sleep(1);
            }
            printf(1, "Process of length %d with priority %d finished\n", l, getprio());
            exit();
        }
    }
    while(wait() != -1);
    exit();
}