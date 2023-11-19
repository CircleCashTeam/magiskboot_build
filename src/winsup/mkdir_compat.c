#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int _mkdir_stub (const char *path, mode_t mode) {
    if (mkdir(path) < 0)
        return -1;

    if (chmod(path, mode) < 0) {
        int old_errno = errno;
        rmdir(path);
        errno = old_errno;
        return -1;
    }

    return 0;
}
