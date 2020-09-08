#ifndef __B_COMMON__
#define __B_COMMON__

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>
#include <stdint.h>

/* all types */ 
typedef bool       B;
typedef char       C,*S,*G;
typedef int8_t     J;
typedef int16_t    H;
typedef int32_t    I,M,D,U,W,T;
typedef long long  L,Q,Z;
typedef float      F;
typedef double     E;
typedef void       O;
typedef struct { F real,imag; } X;
typedef struct { Q source; G ek,ev; } Y0, *Y;  //key,value: V // Q source
typedef struct ListY { G y,cn;  struct ListY *next; } ListY; // cn: column name 
typedef struct { L row, col; ListY *fkey; } A0,*A;
typedef const char *CS;  // constant string

/* unsigned types */
typedef uint64_t UL;
typedef uint32_t UI;

#define P printf
#define R return
#define SP sprintf
#define FP fprintf


/* size: 4 + 2 * 8 + 16 = 36 */
typedef struct NodeValue {
    L len; G g; I typ;
    union{
        B b;   //boolean   1  byte
        J j;   //small     1  byte
        H h;   //short     2  bytes
        I i32; //int       4  bytes
        L i64; //long      8  bytes
        F f32; //float     4  bytes
        E f64; //double    8  bytes
        C c;   //char      1  byte
        Q q;   //symbol    8  bytes
        S s;   //string    8  bytes
        M m;   //month     4  bytes
        D d;   //date      4  bytes
        Z z;   //date time 8  bytes
        U u;   //minute    4  bytes
        W w;   //second    4  bytes
        T t;   //time      4  bytes
        X x;   //complex   8  bytes
        Y y;   //enum      8  bytes
        A a;   //table     16 bytes
        struct NodeValue *g2;
    };
}V0,*V;

#define DOI(n, x) {for(L i=0,i2=n;i<i2;i++)x;}
#define DOJ(n, y) {for(L j=0,j2=n;j<j2;j++)y;}

/* parallel DOI */
#define STRINGIFY(x) #x
#define DOP(n, x, ...) {L i2=n; \
    _Pragma(STRINGIFY(omp parallel for simd __VA_ARGS__)) \
    for(L i=0;i<i2;i++) x;}

#define FLine()   FP(stderr, "\n")
#define INFO(s)   FP(stderr, s "(%s:%d:%s):\n\t", __FILE__, __LINE__, __func__)
#define EP(...)   do{INFO("[ERROR]");  FP(stderr,__VA_ARGS__); FLine(); exit(1);}while(0)  // error

#define H_B 0
#define H_J 1
#define H_H 2
#define H_I 3
#define H_L 4
#define H_F 5
#define H_E 6
#define H_X 7
#define H_C 8  //char
#define H_Q 9  //sym
#define H_S 10 //str
#define H_M 11
#define H_D 12
#define H_Z 13
#define H_U 14
#define H_W 15
#define H_T 16
#define H_G 17 //list
#define H_N 18 //dict
#define H_Y 19 //enum
#define H_A 90 //table
#define H_K 91 //ktable
#define H_V 93 //value item

#define vp(x)  x->typ
#define vn(x)  x->len

#define vb(x)  x->b
#define vj(x)  x->j
#define vh(x)  x->h
#define vi(x)  x->i32
#define vl(x)  x->i64
#define vf(x)  x->f32
#define ve(x)  x->f64
#define vc(x)  x->c
#define vq(x)  x->q
#define vs(x)  x->s
#define vm(x)  x->m
#define vd(x)  x->d
#define vz(x)  x->z
#define vu(x)  x->u
#define vw(x)  x->w
#define vt(x)  x->t
#define vx(y)  y->x
#define vy(x)  x->y
#define va(x)  x->a
#define vg(x)  x->g
#define vg2(x) x->g2

#define sB(x) ((B*)(vg(x)))
#define sJ(x) ((J*)(vg(x)))
#define sH(x) ((H*)(vg(x)))
#define sI(x) ((I*)(vg(x)))
#define sL(x) ((L*)(vg(x)))
#define sE(x) ((E*)(vg(x)))
#define sF(x) ((F*)(vg(x)))
#define sC(x) ((C*)(vg(x)))
#define sQ(x) ((Q*)(vg(x)))
#define sS(x) ((S*)(vg(x)))
#define sX(x) ((X*)(vg(x)))
#define sY(x) ((L*)(vg(x)))
#define sM(x) ((M*)(vg(x)))
#define sD(x) ((D*)(vg(x)))
#define sZ(x) ((Z*)(vg(x)))
#define sU(x) ((U*)(vg(x)))
#define sW(x) ((W*)(vg(x)))
#define sT(x) ((T*)(vg(x)))
#define sG(x) ((G*)(vg(x)))
#define sV(x) ((V )(vg(x)))

#define vB(x,i) sB(x)[i]
#define vJ(x,i) sJ(x)[i]
#define vH(x,i) sH(x)[i]
#define vI(x,i) sI(x)[i]
#define vL(x,i) sL(x)[i]
#define vE(x,i) sE(x)[i]
#define vF(x,i) sF(x)[i]
#define vC(x,i) sC(x)[i]
#define vQ(x,i) sQ(x)[i]
#define vS(x,i) sS(x)[i]
#define vX(x,i) sX(x)[i]
#define vY(x,i) sY(x)[i]
#define vM(x,i) sM(x)[i]
#define vD(x,i) sD(x)[i]
#define vZ(x,i) sZ(x)[i]
#define vU(x,i) sU(x)[i]
#define vW(x,i) sW(x)[i]
#define vT(x,i) sT(x)[i]
#define vV(x,k) (sV(x)+(k))

#define xp  vp(x)
#define xn  vn(x)

#define xb  vb(x)
#define xj  vj(x)
#define xh  vh(x)
#define xi  vi(x)
#define xl  vl(x)
#define xf  vf(x)
#define xe  ve(x)
#define xc  vc(x)
#define xq  vq(x)
#define xs  vs(x)
#define xm  vm(x)
#define xd  vd(x)
#define xz  vz(x)
#define xu  vu(x)
#define xw  vw(x)
#define xt  vt(x)
#define xx  vx(x)
#define xg  vg(x)

void my_tic();
E my_toc(B isPrint);

#define tic() my_tic()
#define toc() my_toc(1)
#define calc_toc() my_toc(0)
#define time_toc(...) do{E elapsed=calc_toc();P("// ");P(__VA_ARGS__);}while(0)

void printV2(V x, L n);
void loadData(V x, S fn);
V initV(V x, I typ, L len);

#ifdef __cplusplus
}
#endif

#endif

