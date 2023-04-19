#ifndef HK_CLEAR_TYPES_H
#define HK_CLEAR_TYPES_H


struct hk_bit_field_octet {
    unsigned int value : 8;
};

struct hk_bit_field {
    struct hk_bit_field_octet octet[32];
};

struct command {
    unsigned int version                : 3;
    unsigned int packet_t               : 1;
    unsigned int secondary_header_t     : 1;
    unsigned int device                 : 3;
    unsigned int packet_sequence_count  : 8;
    unsigned int packet_data_len        : 16;
    struct hk_bit_field hk_bit_clear;   //256 bits
};

#endif //HK_CLEAR_TYPES_H