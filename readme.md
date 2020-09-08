# Project: Gem Hunter

## Data Setup

Download data from

    http://www.sable.mcgill.ca/~hanfeng.c/t/gem-data/

Put join data

    mv data join-factory/

Put groupby data

    mv data groupby-factory/


## Join

Work directory

    cd join-factory

Create a binary

    ./make.sh

Execute it with the first join in query 2 and algorithm 0

    ./join data/q2/d0-left.txt data/q2/d1-right.txt 0

Write algorithm under the folder `code`

    code/algo-0.c


## Groupby

Work directory

    cd groupby-factory

Create a binary

    ./make.sh

Execute it with the first groupby in query 2 with algorithm 0

    ./group data/q2/g0.txt 0

Write algorithm under the folder `code`

    code/algo-0.c



