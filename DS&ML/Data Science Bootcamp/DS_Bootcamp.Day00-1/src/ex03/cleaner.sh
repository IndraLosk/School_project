#!/bin/sh

head -n 1 ../ex02/hh_sorted.csv > hh_positions.csv

awk -F'",' '
    NR > 1 {
        third = "-"
        if ($3 ~ /Junior|Middle|Senior/) {
            if ($3 ~ /Junior/) third = "Junior"
            else if ($3 ~ /Middle/) third = "Middle"
            else if ($3 ~ /Senior/) third = "Senior"
        }

        printf "%s,%s,\"%s\",%s,%s\n", $1, $2, third, $4, $5
    }
' ../ex02/hh_sorted.csv >> hh_positions.csv

sed -i '1!s/.$//' hh_positions.csv



