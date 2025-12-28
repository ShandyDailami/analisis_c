
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static void encode_gray_bitstream(HYuvContext *s, int count){

    int i;

    

    count/=2;

    if(s->flags&CODEC_FLAG_PASS1){

        for(i=0; i<count; i++){

            s->stats[0][ s->temp[0][2*i  ] ]++;

            s->stats[0][ s->temp[0][2*i+1] ]++;

        }

    }else if(s->context){

        for(i=0; i<count; i++){

            s->stats[0][ s->temp[0][2*i  ] ]++;

            put_bits(&s->pb, s->len[0][ s->temp[0][2*i  ] ], s->bits[0][ s->temp[0][2*i  ] ]);

            s->stats[0][ s->temp[0][2*i+1] ]++;

            put_bits(&s->pb, s->len[0][ s->temp[0][2*i+1] ], s->bits[0][ s->temp[0][2*i+1] ]);

        }

    }else{

        for(i=0; i<count; i++){

            put_bits(&s->pb, s->len[0][ s->temp[0][2*i  ] ], s->bits[0][ s->temp[0][2*i  ] ]);

            put_bits(&s->pb, s->len[0][ s->temp[0][2*i+1] ], s->bits[0][ s->temp[0][2*i+1] ]);

        }

    }

}
