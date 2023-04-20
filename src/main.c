#include "types.h"
#include "samples.h"
#include "functions.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{

    /* Try to get input args. */
    if (1 == argc)
    {
        /*If 0 args, run demo using the sample data in sample.h*/
        printf("No options provided; showing demo instead:\n");

        struct command ground_command = input_command_a;
        struct hk_bit_field onboard_bit_field = hk_bit_field_1;

        printf("Initial on-board bit field:\n");
        print_hk_bit_field(&onboard_bit_field);

        printf("Command HK clear bit field:\n");
        print_hk_bit_field(&ground_command.hk_bit_clear);

        hk_clear(&input_command_a, &onboard_bit_field);
        printf("Cleared on-board bit field:\n");
        print_hk_bit_field(&onboard_bit_field);
    }
    else
    {
        /* If files are supplied (command bit field, on-board bit field), use those files. */
        int opt;
        int option_count = 0;
        while ((opt = getopt(argc, argv, "c:o:")) != -1)
        {
            switch (opt)
            {
            case 'c': /* Clear bit field */
                printf("Given File: %s for clear bitfield\n", optarg);
                option_count++;
                break;
            case 'o': /* On-board bit field */
                printf("Given File: %s for on-board bitfield\n", optarg);
                option_count++;
                break;
            case '?': /*Option not in optstring*/
                /* C tells the user that the option is invalid. */
                break;
            }
            if (option_count == 2)
            {
                printf("Got both bit fields, parsing...\n", optarg);
            }
        }
    }

    

    return 0;
}