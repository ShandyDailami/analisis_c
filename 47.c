
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

// Definisi tipe data umum biar CodeQL/Sonar gak pusing
typedef struct { int a; } av_struct;
typedef void* unknown_ptr;


static void omap_i2c_set_slave_addr(OMAPI2C *s, uint8_t addr)

{

    uint16_t data = addr;



    memwrite(s->addr + OMAP_I2C_SA, &data, 2);

    memread(s->addr + OMAP_I2C_SA, &data, 2);

    g_assert_cmphex(data, ==, addr);

}
