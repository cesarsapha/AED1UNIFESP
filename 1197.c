#include <stdio.h>

int main ()
{
  int vel, s;

  while (scanf("%hd %hd", &vel, &s) != EOF)
    printf("%d\n", vel*s*2);

}
