#!/bin/sh

awk -F',' '
    NR == 1 {
        header = $0
        next
    }
    {
        date = substr($2, 1, 11)
        if (date != prev_date) {
            prev_date = date
            print header > date ".csv"
        }
        print $0 >> date ".csv"
    }
' ../ex03/hh_positions.csv
