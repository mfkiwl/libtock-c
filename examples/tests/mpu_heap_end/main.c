#include <console.h>

int main(void) {
  printf("[TEST] MPU test end of readable RAM\n");

  // sbrk with an increment of 0; this returns the end of the heap.
  uint8_t* heap_end = memop(1, 0);

  printf("Reading last readable byte in RAM, address 0x%x\n", heap_end - 1);
  printf("This should succeed.\n");
  uint8_t last_byte = *(heap_end - 1);
  printf("Address: %p, value: %02x\n", (heap_end - 1), last_byte);

  printf("Finding end of heap region...\n");
  while (1) {
    uint8_t next_byte = *heap_end;
    printf("Address: %p, value: %02x\n", heap_end, next_byte);
    heap_end++;
  }
}
