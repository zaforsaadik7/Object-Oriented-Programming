#include <stdio.h>

int *fun() {
 int num = 10;
 return &num;
}

int main() {
 int *ptr = NULL;
 ptr = fun();
 printf("%d", *ptr);
 return 0;
}

