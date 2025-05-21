#include <stdint.h> // Contains the uint_64 data type which is an unsigned integer respresented on 64 bits
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* hash_function(char* password) {
    uint64_t hash = 0xcbf29ce484222325; // 64-bit initial value for the hash

    for (int i = 0; i < strlen(password); i++) {
        hash ^= password[i];
        hash *= 0x100000001b3; // Represent a specific prime number, its decimal value is 1099511628211
        hash ^= (hash >> 32); // We simply mix the right 32 bits of the hash with the left 32 bits
    }

    char* result = (char*) malloc(9 * sizeof(char)); // We need to allocate a certain amount of memory on the heap (9 bytes) to store the final result
    // in order to return a pointer to the character array containing the final hash

    if (result == NULL) { // In case of allocation error
        return NULL;
    }

    memcpy(result, &hash, 8);
    result[8] = '\0';

    return result;
}

void display_ascii_hash(char* hash) {
    for (int i = 0; i < 8; i++) {
        printf("%x", (unsigned char) hash[i]);
    }
    printf("\n");
}
