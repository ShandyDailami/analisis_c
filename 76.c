
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static int vfio_start_eventfd_injection(VFIOINTp *intp)

{

    int ret;



    ret = vfio_set_trigger_eventfd(intp, vfio_intp_interrupt);

    if (ret) {

        error_report("vfio: Error: Failed to pass IRQ fd to the driver: %m");

    }

    return ret;

}
