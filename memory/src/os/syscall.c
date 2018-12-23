#include "defines.h"
#include "kozos.h"
#include "syscall.h"
#include "lib.h"

/* システムコーーーーーーール，の，Wrapper */

kz_thread_id_t kz_run(kz_func_t func, char *name, int priority, int stacksize, int argc, char *argv[]){
    kz_syscall_param_t param;
    param.un.run.func = func;
    param.un.run.name = name;
    param.un.run.priority = priority;
    param.un.run.stacksize = stacksize;
    param.un.run.argc = argc;
    param.un.run.argv = argv;
    puts("calling\n");
    kz_syscall(KZ_SYSCALL_TYPE_RUN, &param);
    return param.un.run.ret;
}

void kz_exit(void){
    kz_syscall(KZ_SYSCALL_TYPE_EXIT, NULL);
}

int kz_wait(void){
    kz_syscall_param_t param;
    kz_syscall(KZ_SYSCALL_TYPE_WAIT, &param);
    return param.un.wait.ret;
}

int kz_sleep(void){
    kz_syscall_param_t param;
    kz_syscall(KZ_SYSCALL_TYPE_SLEEP, &param);
    return param.un.sleep.ret;
}

int kz_wakeup(kz_thread_id_t id){
    kz_syscall_param_t param;
    param.un.wakeup.id = id;
    kz_syscall(KZ_SYSCALL_TYPE_WAKEUP, &param);
    return param.un.wakeup.ret;
}

kz_thread_id_t kz_getid(void){
    kz_syscall_param_t param;
    kz_syscall(KZ_SYSCALL_TYPE_GETID, &param);
    return param.un.getid.ret;
}

int kz_chpri(int priority){
    kz_syscall_param_t param;
    param.un.chpri.priority = priority;
    kz_syscall(KZ_SYSCALL_TYPE_CHPRI, &param);
    return param.un.chpri.ret;
}
