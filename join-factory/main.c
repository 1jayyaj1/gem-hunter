#include "global.h"

V data1, data2;

void loadAllData(S arg1, S arg2){
    data1 = (V)malloc(sizeof(V0));
    data2 = (V)malloc(sizeof(V0));
    tic();
    loadData(data1, arg1);
    loadData(data2, arg2);
    P("\nLoaded:\n");
    P("  left [%s] = %lld\n", arg1, vn(data1));
    P("  right[%s] = %lld\n", arg2, vn(data2));
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
    if(argc == 4){
        loadAllData(argv[1], argv[2]);
        I algoId = atoi(argv[3]);
        switch(algoId){
            case 0: run_join_a0(data1, data2); break;
            //case 1: run_join_a1(data1, data2); break;
            //case 2: run_join_a2(data1, data2); break;
            default: EP("Unknown strategy number: %d\n", algoId);
        }
    }
    else {
        P("Usage: %s <left_data> <right_data> <algorithm_id>\n", argv[0]);
        exit(99);
    }
    return 0;
}


