#!/bin/sh

export LD_LIBRARY_PATH=.
./CtpDemo1 -s
pids=`ps -ef |grep "CtpDemo1" | grep -v "grep" | grep -v "stop" | awk '{ print $2 }'`
for pid in $pids
do
    kill -9 $pid
done

exit 0
