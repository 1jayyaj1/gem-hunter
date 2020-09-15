typedef struct str {
    int value;
    int index;
} str;

struct bucket {
    int value;
    int inds[1000];
    int indsCurr;
};

static int cmpfunc (const void *a, const void *b) {
    struct str *a1 = (struct str *)a;
    struct str *a2 = (struct str *)b;
    if ((*a1).value > (*a2).value)
        return -1;
    else if ((*a1).value < (*a2).value)
        return 1;
    else
        return 0;
}

static void compute_groupby(int *d, int len){
    // ... groupby the data d
    // write your code here
    struct str objects[len];

    for (int i = 0; i < len; i++) {
        objects[i].value = d[i];
        objects[i].index = i;
    }

	qsort(objects, len, sizeof(str), cmpfunc);

	int currBucket = 0;
	struct bucket table[len];

	for (int i = 0; i < len; i++) {
        table[i].value = objects[i].value;
        table[i].indsCurr = 0;
    }

	if (len > 1) { 
		int curr = objects[0].value;
		printf("DEBUGME!");
		for (int i = 0; i < len; i++) {
			printf("%d\n", objects[i].value);
			if (objects[i].value != curr) {
				currBucket++;
				curr = objects[i].value;
			}
			table[currBucket].inds[table[i].indsCurr] = objects[i].index;
			table[currBucket].indsCurr++;
	    }
	}

	for (int i = 0; i < currBucket; i++) {
		printf("%d\n", table[i].value);
	}
}

static void run_groupby_a0(V d){
    printV2(d, 10);
    tic();
    compute_groupby(sI(d), vn(d));
    time_toc("Groupby execution time (ms): %g\n", elapsed);
}
