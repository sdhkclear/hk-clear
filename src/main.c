#include "types.h"
#include "samples.h"
#include "functions.h"
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Hello, Space Packet!\n");

    print_hk_bit_field(&hk_bit_field_1);

    return 0;
}