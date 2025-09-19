#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    size_t size = 1024 * 1024; // 1MB
    int count = 0;
    while (1) {
        void* ptr = malloc(size);
        if (!ptr) {
            printf("Failed to allocate memory!\n");
            break;
        }
        printf("Allocated %d MB\n", ++count);
        sleep(1);
    }
    return 0;
}