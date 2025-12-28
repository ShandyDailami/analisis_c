
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


void qemu_file_skip(QEMUFile *f, int size)

{

    if (f->buf_index + size <= f->buf_size) {

        f->buf_index += size;

    }

}
