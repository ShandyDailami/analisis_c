
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static void xvid_idct_put(uint8_t *dest, ptrdiff_t line_size, int16_t *block)

{

    ff_xvid_idct(block);

    ff_put_pixels_clamped(block, dest, line_size);

}
