
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static int decode_blocks(SnowContext *s){

    int x, y;

    int w= s->b_width;

    int h= s->b_height;

    int res;



    for(y=0; y<h; y++){

        for(x=0; x<w; x++){



            if ((res = decode_q_branch(s, 0, x, y)) < 0)

                return res;

        }

    }

    return 0;

}