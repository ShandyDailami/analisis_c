
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


void scsi_req_free(SCSIRequest *req)

{

    scsi_req_dequeue(req);

    qemu_free(req);

}
