
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static void pop_output_configuration(AACContext *ac) {

    if (ac->oc[1].status != OC_LOCKED) {

        if (ac->oc[0].status == OC_LOCKED) {

            ac->oc[1] = ac->oc[0];

            ac->avctx->channels = ac->oc[1].channels;

            ac->avctx->channel_layout = ac->oc[1].channel_layout;

        }else{

            ac->avctx->channels = 0;

            ac->avctx->channel_layout = 0;

        }

    }

}
