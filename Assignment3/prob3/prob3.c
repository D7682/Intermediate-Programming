#include <stdio.h>

typedef double vec2df[2];

typedef struct {
  vec2df vec;
} vec2d;

void printSizeOfVec2df(vec2df *vec) {
  printf("Size of vec2df argument: %zu\n", sizeof(*vec));
}

void printSizeOfVec2d(vec2d vec) {
  printf("Size of vec2d argument: %zu\n", sizeof(vec));
}

int main() {
    vec2df vec1;
    vec2d vec2;

    printSizeOfVec2df(&vec1);
    printSizeOfVec2d(vec2);
    
    return 0;
}
