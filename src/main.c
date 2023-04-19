#include "types.h"
#include "samples.h"
#include "functions.h"
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {

    struct command ground_command = input_command_a;
    struct hk_bit_field onboard_bit_field = hk_bit_field_1;

    printf("Initial on-board bit field:\n");
    print_hk_bit_field(&onboard_bit_field);

    printf("Command HK clear bit field:\n");
    print_hk_bit_field(&ground_command.hk_bit_clear);

    hk_clear(&input_command_a, &onboard_bit_field);
    printf("Cleared on-board bit field:\n");
    print_hk_bit_field(&onboard_bit_field);

    return 0;
}