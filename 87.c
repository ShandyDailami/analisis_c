
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static void do_change(const char *device, const char *target)

{

    if (strcmp(device, "vnc") == 0) {

	do_change_vnc(target);

    } else {

	do_change_block(device, target);

    }

}
