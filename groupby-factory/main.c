#include "global.h"

V data1;

void loadAllData(S arg1){
    data1 = (V)malloc(sizeof(V0));
    tic();
    loadData(data1, arg1);
    P("\nLoaded:\n");
    P("  [%s] = %lld\n", arg1, vn(data1));
    P("\n");
    time_toc("Data loading time (ms): %g\n", elapsed);
}
 
static UL hash_murmur3_i32(I a){ // default: return 64-bit
    a ^= a >> 16;
    a *= 0x85ebca6b; // 2246822507
    a ^= a >> 13;
    a *= 0xc2b2ae35; // 3266489909
    a ^= a >> 16;
    R a;
}

/* include files */
#include "code/algo-0.c"
//#include "code/algo-1.c"
//#include "code/algo-2.c"

int main(int argc, char **argv){
    if(argc == 3){
        loadAllData(argv[1]);
        I algoId = atoi(argv[2]);
        switch(algoId){
            case 0: run_groupby_a0(data1); break;
            //case 1: run_groupby_a1(data1); break;
            //case 2: run_groupby_a2(data1); break;
            default: EP("Unknown strategy number: %d\n", algoId);
        }
    }
    else {
        P("Usage: %s <data> <algorithm_id>\n", argv[0]);
        exit(99);
    }
    return 0;
}


