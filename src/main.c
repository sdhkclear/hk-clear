#include "types.h"
#include "samples.h"
#include "functions.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{

    struct command ground_command = {0};
    struct hk_bit_field onboard_bit_field = {0};

    if (1 < argc)
    {
        /* If files are supplied (command bit field, on-board bit field), use those files. */
        int opt;
        int file_count = 0;
        while ((opt = getopt(argc, argv, "c:o:")) != -1)
        {
            switch (opt)
            {
            case 'c': /* Clear bit field */
                printf("Given File: %s for clear bitfield\n", optarg);
                file_count++;
                break;
            case 'o': /* On-board bit field */
                printf("Given File: %s for on-board bitfield\n", optarg);
                file_count++;
                break;
            case '?': /*Option not in optstring*/
                /* C tells the user that the option is invalid. */
                break;
            }
            if (file_count == 2)
            {
                printf("Got both bit fields, parsing...\n", optarg);
            }
        }
    }
    else
    {
        /*If no args, run demo using the sample data in sample.h*/
        printf("No options provided; showing demo:\n");

        ground_command = input_command_a;
        onboard_bit_field = hk_bit_field_1;
    }

    printf("Initial on-board bit field:\n");
    print_hk_bit_field(&onboard_bit_field);

    printf("Command HK clear bit field:\n");
    print_hk_bit_field(&ground_command.hk_bit_clear);

    hk_clear(&input_command_a, &onboard_bit_field);
    printf("Cleared on-board bit field:\n");
    print_hk_bit_field(&onboard_bit_field);

    return 0;
}