
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


void tcg_exec_init(unsigned long tb_size)

{

    cpu_gen_init();

    code_gen_alloc(tb_size);

    page_init();

#if defined(CONFIG_SOFTMMU)

    /* There's no guest base to take into account, so go ahead and

       initialize the prologue now.  */

    tcg_prologue_init(&tcg_ctx);

#endif

}
