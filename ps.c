#include "types.h"
#include "user.h"
#include "processInfo.h"

int main () {
    struct processInfo info;
    int maxpid = getMaxPid();
    int procnum = getNumProc();
    printf(1, "Processes: %d\n", procnum);
    for(int pid = 1; pid <= maxpid; pid++) {
            if(getProcInfo(pid, &info)==0) {
                printf(1, "%s PID: %d PPID: %d  switches: %d size %dB \n", info.name, pid, info.ppid, info.sch_switches, info.size);
            }
    }
    exit();
}