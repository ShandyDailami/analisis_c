
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static void destroy_buffers(SANMVideoContext *ctx)

{

    av_freep(&ctx->frm0);

    av_freep(&ctx->frm1);

    av_freep(&ctx->frm2);

    av_freep(&ctx->stored_frame);

    av_freep(&ctx->rle_buf);

    ctx->frm0_size =

    ctx->frm1_size =

    ctx->frm2_size = 0;


}