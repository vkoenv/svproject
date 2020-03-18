#include <assert.h>
#include <stdio.h>
#include <math.h>
typedef struct frac{
  long int num, den;
} frac;

typedef struct point{
  frac x, y;
} point;

void afficher_frac(frac f){
  printf("(%ld, %ld)\n", f.num, f.den);
}

frac build(long int n, long int d){
  assert(d!=0);
  frac frc = {n, d};
  return frc;
}

int eq(frac f, frac g){
  if((f.num*g.den)==(g.num*f.den)){
    return 1;
  }
  return 0;
}

int is_integer(frac f){
  return (f.num%f.den==0);
}

frac sum(frac f, frac g){
  if(f.den==g.den){
    return build(f.num+g.num, f.den);
  }
  else{
    return build((f.den*g.num)+(f.num*g.den), (f.den*g.den));
  }
}

frac sub(frac f, frac g){
  if(f.den==g.den){
    return build(f.num-g.num, f.den);
  }
  else{
    return build((f.den*g.num)-(f.num*g.den), (f.den*g.den));
  }
}

frac mul(frac f, frac g){
  return build(f.num*g.num, f.den*g.den);
}

long pgcd(long a, long b){
  long x=a;
  long y=b;
  if(x<0){
    x=-a;
  }
  if(y<0){
    y=-b;
  }
  if(x<y){
    long h=x;
    x=y;
    y=h;
  }
  long r;
  while(y!=0){
    r=x%y;
    x=y;
    y=r;
  }
  return x;
}

frac reduce(frac f){
  long q = pgcd(f.num, f.den);
  f.num=f.num/q;
  f.den=f.den/q;
  if((f.num<0)&&(f.den<0)){
    f.num = -f.num;
    f.den = - f.den;
  }
  return f;
}

int eqp(point p1, point p2){
  if(eq(p1.x, p2.x)&&eq(p1.y, p2.y)){
    return 1;
  }
  return 0;
}

double dist(point p1, point p2){
  frac dx = sub(p1.x, p2.x);//-4
  frac dy = sub(p1.y, p2.y);//-3
  frac d2 = sum(mul(dx, dx), mul(dy,dy));
  double distance = sqrt(d2.num/d2.den);
  printf("%f\n", distance);//use float template for printing double
  return distance;
}

int main(int argc, char const *argv[]) {
  frac ex_frac[] = {build(1, 1), build(1, 2), build(2, 4),
                    build(-9, 3), build(8, -20),
                    build(-5, -1), build(1, -3)
                   };
  afficher_frac(build(1, 3));
  eq(ex_frac[1], ex_frac[2]);
  is_integer(ex_frac[0]);
  /*for(int i=0; i<7; i++){
    afficher_frac(reduce(ex_frac[i]));
  }*/
  point p = { .x = build(3, 1), .y = build(4, 1)};
  point q = { .x = build(7, 1), .y = build(7, 1)};
  dist(p, q);
  return 0;
}
