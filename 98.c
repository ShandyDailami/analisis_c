
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


void AUD_vlog (const char *cap, const char *fmt, va_list ap)

{

    if (conf.log_to_monitor) {

        if (cap) {

            monitor_printf(default_mon, "%s: ", cap);

        }



        monitor_vprintf(default_mon, fmt, ap);

    }

    else {

        if (cap) {

            fprintf (stderr, "%s: ", cap);

        }



        vfprintf (stderr, fmt, ap);

    }

}
