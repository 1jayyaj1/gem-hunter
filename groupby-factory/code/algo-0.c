#define INITIAL_CAPACITY 3

void push(int *arr, int index, int value, int *size, int *capacity){
     if(*size > *capacity){
          int *p = realloc(arr, sizeof(arr) * 2);
          *capacity = sizeof(arr) * 2;
     }
     
     arr[index] = value;
     *size = *size + 1;
}

static int isSeen(int value, int *keys, int *size) {
	for (int i = 0; i < *size; i++) {
   		if (value == d[i]) {
   			return i;
   		}
   	}
   	return -1;
}

static void compute_groupby(int *d, int len){
    // ... groupby the data d
    // write your code here
	int indexK = 0;
    int sizeK = 0;
    int capacityK = INITIAL_CAPACITY;
    int* keys = malloc(INITIAL_CAPACITY * sizeof(int));


   	for (int i = 0; i < len; i++) {
   		int checkCurr = isSeen(d[i], keys, sizeK);
   		if (checkCurr == -1) {
   			push(keys, indexK, &i, &capacity);
   		} else {

   		}
   	}
}

static void run_groupby_a0(V d){
    printV2(d, 10);
    tic();
    compute_groupby(sI(d), vn(d));
    time_toc("Groupby execution time (ms): %g\n", elapsed);
}
