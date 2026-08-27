#include <stdio.h>

void func1();
void func2();

int main() {
  //   func1();
  func2();
}

void func1() {
  int vet[] = {4, 9, 12};
  int i, *ptr;
  ptr = vet;
  for (i = 0; i < 3; i++) {
    printf("%d ", *ptr);
    ptr++;
  }
}

void func2() {
  int vet[] = {4, 9, 12};
  int i, *ptr;
  ptr = vet;
  for (i = 0; i < 3; i++) printf("%d ", (*ptr)++);
}