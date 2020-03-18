#include <stdio.h>

typedef struct{
  int x;
  int y;
} point;
void mirror(point p){
  p.x = -p.x;
  p.y = -p.y;
}
int main(void){
  point q = { .x = 9, .y = -11 };
  printf("q.x=%d q.y=%d\n", q.x, q.y);
  mirror(q);
  printf("q.x=%d q.y=%d\n", q.x, q.y);
  return 0;
}
