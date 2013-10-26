#!/usr/bin/bash
MAXCOUNT=1000000;
count=1;
while [ "$count" -le $MAXCOUNT ]
do
    echo $RANDOM >>input;
    let "count += 1";
done
