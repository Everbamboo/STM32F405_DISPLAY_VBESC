// 裸机最小C库适配，避免链接错误
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int _write(int file, char *ptr, int len) { return len; }
int _read(int file, char *ptr, int len) { return 0; }
int _close(int file) { return -1; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
void *_sbrk(ptrdiff_t incr) { static char heap[8192]; static char *cur = heap; char *prev = cur; cur += incr; return prev; }
void _exit(int status) { while (1) {} }
int _kill(int pid, int sig) { errno = EINVAL; return -1; }
int _getpid(void) { return 1; }
