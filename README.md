# bitlib Library Documentation

## Overview

The `bitlib` library provides utilities for handling binary data at the bit level. It includes functions to manipulate individual bits, detect the system's endianness, and convert chunks of memory into bit-level representations. This library is particularly useful in low-level programming scenarios, where precise control over binary data is necessary.

----------

## Function Descriptions

### **`int set_bit(bit *b, int value)`**

-   **Purpose**: Sets a bit to either `ZERO` or `ONE`.
-   **Parameters**:
    -   `bit *b`: Pointer to the bit variable.
    -   `int value`: The value to set (`0` or `1`).
-   **Returns**:
    -   `0` on success.
    -   `-1` if the value is invalid.
-   **Usage**:
    
    c
    
    Copy code
    
    `bit b;
    set_bit(&b, 1); // Set the bit to ONE` 
    

----------

### **`int get_bit(bit b)`**

-   **Purpose**: Retrieves the value of a bit.
-   **Parameters**:
    -   `bit b`: The bit variable.
-   **Returns**:
    -   `0` if the bit is `ZERO`.
    -   `1` if the bit is `ONE`.
-   **Usage**:
    
    c
    
    Copy code
    
    `bit b = ONE;
    int value = get_bit(b); // value is 1` 
    

----------

### **`int is_little_endian()`**

-   **Purpose**: Checks if the system uses little-endian byte order.
-   **Returns**:
    -   `1` if the system is little-endian.
    -   `0` otherwise.
-   **Usage**:
    
    c
    
    Copy code
    
    `int is_le = is_little_endian();
    if (is_le) {
        printf("System is little-endian.\n");
    }` 
    

----------

### **`bit_pack chunk_to_bit_array(void* chunk, const size_t chunk_size, const size_t chunk_type_size)`**

-   **Purpose**: Converts a chunk of memory into an array of bits.
-   **Parameters**:
    -   `void* chunk`: Pointer to the memory chunk.
    -   `size_t chunk_size`: Number of elements in the chunk.
    -   `size_t chunk_type_size`: Size of each element in bytes.
-   **Returns**: A `bit_pack` structure containing:
    -   `bit* bits`: A dynamically allocated array of bits.
    -   `size_t size`: The total number of bits.
-   **Usage**:
    
    c
    
    Copy code
    
    `int data[2] = {5, 9}; // Binary: 00000101, 00001001
    bit_pack bp = chunk_to_bit_array(data, 2, sizeof(int));
    // Process bp.bits and bp.size` 
    

----------

## Example Usage

### **Complete Example**

Here is a complete example demonstrating the library's usage:

c

Copy code

`#include <stdio.h>
#include "bitlib.h"

int main() {
    // Data to be converted
    int data[2] = {5, 9}; // Binary representation: 00000101, 00001001

    // Convert data to bit array
    bit_pack bp = chunk_to_bit_array(data, 2, sizeof(int));

    // Print the bit array
    printf("Bit representation:\n");
    for (size_t i = 0; i < bp.size; i++) {
        printf("%d", get_bit(bp.bits[i]));
        if ((i + 1) % 8 == 0) printf(" "); // Add space after every byte
    }
    printf("\n");

    // Free allocated memory
    free(bp.bits);

    return 0;
}` 

### **Output**

For the example above:

yaml

Copy code

`Bit representation:
00000000 00000000 00000000 00000101 00000000 00000000 00000000 00001001` 

----------

## Notes

-   Ensure to free the memory allocated for the bit array using `free()` to avoid memory leaks.
-   The library assumes that the `bit` and `bit_pack` types are correctly defined in the `bitlib.h` header file.

Happy coding! 🎉
