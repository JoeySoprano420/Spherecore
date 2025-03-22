#include <sys/syscall.h>
#include <unistd.h>

void FastSyscallWrite(const char* msg) {
    syscall(SYS_write, STDOUT_FILENO, msg, strlen(msg));
}
