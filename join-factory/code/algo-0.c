#define INITIAL_CAPACITY 3

void push(int *arr, int index, int value, int *size, int *capacity){
     if(*size > *capacity){
          int *p = realloc(arr, sizeof(arr) * 2);
          *capacity = sizeof(arr) * 2;
     }
     
     arr[index] = value;
     *size = *size + 1;
}

static void compute_join(int *d1, int len1, int *d2, int len2){
    int currD1;
    int currD2;

    int indexD1 = 0;
    int sizeD1 = 0;
    int capacityD1 = INITIAL_CAPACITY;
    int* v1 = malloc(INITIAL_CAPACITY * sizeof(int));
   	
   	int indexD2 = 0;
    int sizeD2 = 0;
    int capacityD2 = INITIAL_CAPACITY;
    int* v2 = malloc(INITIAL_CAPACITY * sizeof(int));

    for(currD1 = 0; currD1 < len1; currD1++) {
    	for(currD2 = 0; currD2 < len2; currD2++) {
    		if (d1[currD1] == d2[currD2]) {
    			push(v1, indexD1, currD1, &sizeD1, &capacityD1);
    			indexD1++;
    			push(v2, indexD2, currD2, &sizeD2, &capacityD2);
    			indexD2++;
    		}
    	}
    }

    for(int p1 = 0; p1 < sizeD2; p1++) {
		P("[%d] %d\n", v1[p1], d1[v1[p1]]);
    }
    P("\n");
    for(int p2 = 0; p2 < sizeD1; p2++) {
		P("[%d] %d\n", v2[p2], d2[v2[p2]]);
    }
}

static void run_join_a0(V d1, V d2){
    P("\nDisplay left items:\n");
    printV2(d1, 10);
    P("\nDisplay right items:\n");
    printV2(d2, 10);
    tic();
    compute_join(sI(d1), vn(d1), sI(d2), vn(d2));
    time_toc("Join execution time (ms): %g\n", elapsed);
}