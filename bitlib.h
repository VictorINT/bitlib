#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum bit {
    ZERO,
    ONE
};

typedef enum bit bit;

struct bit_pack {
    bit* _bit;
    size_t _size;
};

typedef struct bit_pack bit_pack;

