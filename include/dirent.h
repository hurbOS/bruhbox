#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>

struct dirent {
    ino_t d_ino;
    long d_serial;
    unsigned short int d_reclen;
    unsigned char d_type; //filetype
    unsigned char d_namelen; //filename length

    char d_name[1];
};
