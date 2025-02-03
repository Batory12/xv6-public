#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_getNumProc(void) {
  return getNumProc();
}

int sys_getMaxPid(void) {
  return getMaxPid();
}

int sys_getProcInfo(void) {
  int pid;
  struct processInfo *info;
  if(argint(0, &pid) < 0 || argptr(1, &info, sizeof(info)))
    return -1;
  return getProcInfo(pid, info);
}

int sys_setprio(void) {
  int prio;
  if(argint(0, &prio) <0)
    return -1;
  myproc()->prio = prio;
  return 0;
}

int sys_getprio(void) {
  return myproc()->prio;
}

int sys_forkcb(void) {
  void (*func)(void);
  if(argptr(0, (void*)&func, sizeof(func)) < 0)
    return -1;
  myproc()->cb = func;
  return 0;
}

int sys_exitcb(void) {
  struct proc *curproc = myproc();
  if(curproc->cb_ret) {
    curproc->tf->eip = curproc->cb_ret;
    curproc->cb_ret = 0;
    return 0;
  }
  return -1;
}