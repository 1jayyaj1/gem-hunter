
static void compute_join(int *d1, int len1, int *d2, int len2){
    // ... join two columns: d1 and d2
}

static void run_join_a0(V d1, V d2){
    P("\nDisplay left items:\n");
    printV2(d1, 10);
    P("\nDisplay right items:\n");
    printV2(d2, 10);
    compute_join(sI(d1), vn(d1), sI(d2), vn(d2));
}

