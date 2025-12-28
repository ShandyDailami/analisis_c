
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static inline void RENAME(rgb24ToY)(uint8_t *dst, const uint8_t *src, int width, uint32_t *unused)

{

#if COMPILE_TEMPLATE_MMX

    RENAME(bgr24ToY_mmx)(dst, src, width, PIX_FMT_RGB24);

#else

    int i;

    for (i=0; i<width; i++) {

        int r= src[i*3+0];

        int g= src[i*3+1];

        int b= src[i*3+2];



        dst[i]= ((RY*r + GY*g + BY*b + (33<<(RGB2YUV_SHIFT-1)))>>RGB2YUV_SHIFT);

    }

#endif

}
