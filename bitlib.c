#include "bitlib.h"

int set_bit(bit *b, int value) {
    if (value != 0 && value != 1) {
        return -1; // return err
    }
    if (value == 0)
        (*b) = ZERO;
    else
        (*b) = ONE;
    return 0;
}

int get_bit(bit b) {
    if (b == ZERO) return 0;
    else return 1;
}

int is_little_endian() {
    uint16_t test = 0x1;
    return *((uint8_t*)&test) == 1;
}

bit_pack chunk_to_bit_array(void* chunk, const size_t chunk_size, const size_t chunk_type_size) {
    size_t actual_size = chunk_size * chunk_type_size * 8; // nr of bits
    bit *b = (bit*)malloc(sizeof(bit) * actual_size); //

    uint8_t* byte_ptr = (uint8_t*)chunk;

    int little_endian = is_little_endian();

    for (size_t i = 0; i < chunk_size * chunk_type_size; i++) { // procesăm fiecare octet
        size_t byte_index = little_endian ? (chunk_size * chunk_type_size - 1 - i) : i;
        uint8_t current_byte = byte_ptr[byte_index];

        for (size_t bit_index = 0; bit_index < 8; bit_index++) {
            set_bit(&b[i * 8 + bit_index], (current_byte >> (7 - bit_index)) & 1);
        }
    }

    bit_pack bp = {b, actual_size};
    return bp;
}
