#!/bin/sh

echo '"name","count"' > hh_uniq_positions.csv

for jms in Junior Middle Senior; do
    echo -n "\"$jms\"," >> hh_uniq_positions.csv
    grep -c "$jms" ../ex03/hh_positions.csv >> hh_uniq_positions.csv
done
