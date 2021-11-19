#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void badfun(int num, int leak) 
{
  char * c = malloc(100);

  sprintf(c, "Alloc: %c", num);

  if (leak) {
    printf("Leaked!\n");
    return;
  }
  free(c);
  return;
}

int main(int argc, char * argv[]) 
{
  sleep(5);
  int times = 0;
  while (times < 10) {
    badfun(times, times % 2); // every other one is a leak
    times++;
    sleep(1);
  }
  printf("Exiting with leaks\n");

  return 0;
}
