#include "functions.h"
#include <stdio.h>

int hk_clear(struct command * c, struct hk_bit_field * bf){
    for (int i = 0; i < 32; i++) {
        if ( 0 != bf->octet[i]){
            /* Want to zero the bits specified by the command.
             * Let input bit field be I and command bit mask be M.
             * ~M AND I = desired result */
        }
    }
    return 0;
}

void print_hk_bit_field(struct hk_bit_field * bf){
    
    printf("{ ");

    for (int i = 0; i < 32; i++){

        printf("0x%x ", bf->octet[i]);

        if (0 == (i + 1) % 8){
            if ( i != 31) {
                printf("\n  ");
            }
            else {
                printf("}\n");
            }
        }
    }
}