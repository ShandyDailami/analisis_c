
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


print_syscall_ret(int num, abi_long ret)

{

    int i;



    for(i=0;i<nsyscalls;i++)

        if( scnames[i].nr == num ) {

            if( scnames[i].result != NULL ) {

                scnames[i].result(&scnames[i],ret);

            } else {

                if( ret < 0 ) {

                    gemu_log(" = -1 errno=" TARGET_ABI_FMT_ld " (%s)\n", -ret, target_strerror(-ret));

                } else {

                    gemu_log(" = " TARGET_ABI_FMT_ld "\n", ret);

                }

            }

            break;

        }

}
