static void compute_groupby(int *d, int len){
    // ... groupby the data d
    // write your code here
}

static void run_groupby_a0(V d){
    printV2(d, 10);
    tic();
    compute_groupby(sI(d), vn(d));
    time_toc("Groupby execution time (ms): %g\n", elapsed);
}
