#include "global.h"
// ----- memory

static L getTypeSize(I typ, L len){
    L r = -1, k = 0;
    switch(typ){
        case H_B  : r = sizeof(B);     break;
        case H_J  : r = sizeof(J);     break;
        case H_C  : r = sizeof(C); k=1;break;
        case H_H  : r = sizeof(H);     break;
        case H_I  : r = sizeof(I);     break;
        case H_L  : r = sizeof(L);     break;
        case H_F  : r = sizeof(F);     break;
        case H_E  : r = sizeof(E);     break;
        case H_X  : r = sizeof(X);     break;
        case H_Q  : r = sizeof(Q);     break;
        case H_S  : r = sizeof(S);     break;
        case H_M  : r = sizeof(M);     break;
        case H_D  : r = sizeof(D);     break;
        case H_Z  : r = sizeof(Z);     break;
        case H_U  : r = sizeof(U);     break;
        case H_W  : r = sizeof(W);     break;
        case H_T  : r = sizeof(T);     break;
        case H_G  : r = sizeof(V0);    break;
        case H_N  : r = sizeof(V0);    break;
        case H_Y  : r = sizeof(L);     break; /* integers */
        case H_A  : r = sizeof(V0);    break;
        case H_K  : r = sizeof(V0);    break;
        case H_V  : r = sizeof(V0);    break;
        default: EP("Type not supported: %d", typ);
    }
    return r * len + k;
}

static G getHeapMem(I typ, L len){
    L size = getTypeSize(typ, len);
    R (G)malloc(size);
}

V initV(V x, I typ, L len){
    xp = typ;
    xn = len;
    xg = (len>1)?getHeapMem(typ, len):(G)&xb;
    R x;
}

// ----- time
#define TIMEVAL_N 10
static I timeSlotId = 0;
struct timeval tv0a[TIMEVAL_N], tv0b[TIMEVAL_N];

static void time_check(){
    if(timeSlotId >= TIMEVAL_N || timeSlotId < 0){
        EP("No sufficient lots for timeval: %d >= %d or a negative num", \
                timeSlotId, TIMEVAL_N);
    }
}

static L calcIntervalPrecise(struct timeval t0, struct timeval t1){
    return (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
}

// return: ms (Linux/MacOS)
static E calcInterval(struct timeval t0, struct timeval t1){
    return calcIntervalPrecise(t0, t1) / 1000.0;
}

void my_tic(){
    time_check();
    gettimeofday(&tv0a[timeSlotId++], NULL);
}

E my_toc(B isPrint){
    timeSlotId--; time_check();
    gettimeofday(&tv0b[timeSlotId], NULL);
    E elapsed = calcInterval(tv0a[timeSlotId], tv0b[timeSlotId]);
    if(isPrint)
        P("[%d] The elapsed time (ms): %g\n\n", timeSlotId, elapsed);
    return elapsed;
}

static void time_clear(){
    timeSlotId = 0;
}

// ----- print

void printV2(V x, L n){
    L size = xn < n ? xn : n;
    DOI(size, P("[%2lld] %d\n", i, vI(x,i)))
}

// ----- load data

B isDataList(S line){
    DOI(strlen(line), if(line[i]==' ') R 1) R 0;
}

void loadDataListInit(V x, C typ, I row){
    switch(typ){
        case 'H': initV(x, H_H, row); break;
        case 'I': initV(x, H_I, row); break;
        case 'E': initV(x, H_E, row); break;
        case 'Q': initV(x, H_Q, row); break;
        case 'D': initV(x, H_D, row); break;
        default: EP("Unknown type: %c",typ);
    }
}

void loadData(V x, S fn){
    FILE *fp = fopen(fn, "r");
    if(!fp){
        P("File not found: %s\n", fn);
        exit(99);
    }
    C temp[99];
    if(fgets(temp, 99, fp)){
        if(isDataList(temp)){ // load list
            I size, row;
            sscanf(temp, "%d %d", &size, &row);
            initV(x, H_G, size);
            if(!fgets(temp, 99, fp)){
                EP("Error ...");
                exit(1);
            }
            C types[99];
            DOI(size, types[i]=temp[i*2])
            DOI(size, loadDataListInit(vV(x,i), types[i], row))
            for(I i=0; i<row; i++){
                if(fgets(temp, 99, fp)){
                    S line = temp;
                    DOJ(size, { // P("line = %s\n", line); getchar();
                        switch(types[j]){
                            case 'H': sscanf(line, "%hd", sH(vV(x,j))+i); break;
                            case 'I': sscanf(line, "%d" , sI(vV(x,j))+i); break;
                            case 'E': sscanf(line, "%lf", sE(vV(x,j))+i); break;
                            case 'Q': sscanf(line, "%lld",sQ(vV(x,j))+i); break;
                            case 'D': sscanf(line, "%d" , sD(vV(x,j))+i); break;
                        } while((*line)!=' ')line++; line++; } )
                }
            }
            P("Imported list: %d %d\n", size, row);
            // printV(x);
            // DOI(size, printV2(vV(x,i), 10))
            // P("x: size = %lld, type = %s\n", xn,getTypeName(xp));
            // DOI(size, printV(vV(x,i)))
            // getchar();
        }
        else {  // load vector
            I num = atoi(temp);
            initV(x, H_I, num);
            for(I i=0; i<num; i++){
                if(fgets(temp, 99, fp)){
                    // P("line: %s\n", temp);
                    vI(x,i) = atoi(temp);
                }
            }
        }
    }
    else {
        P("Nothing here: %s\n", fn);
        exit(99);
    }
}

