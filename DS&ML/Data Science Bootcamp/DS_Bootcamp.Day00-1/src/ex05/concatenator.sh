#!/bin/sh
echo '"id","created_at","name","has_test","alternate_url"' > concatenator.csv

for file in *20*.csv; do
    tail -n +2 "$file" >> concatenator.csv
done