#ifndef __MRTOS_TASK__
#define __MRTOS_TASK__
#define MAX_NUM_TASKS 10
#define STACK_SIZE 0x100
typedef void (*FuncPtr)( void* );
typedef void*  FuncArgs;
typedef int    TaskID;

TaskID add_task(FuncPtr fn, FuncArgs args);
void task_yield();
void pend_sv_handler();

// Does not return
void   run_tasks();
#endif