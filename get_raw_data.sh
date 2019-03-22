#!/bin/bash

echo "This is raw data about polynomials, that have been generated, before they were sent to the main stage." > raw_poly_data.txt

echo "" >> raw_poly_data.txt

for file in RAW_POLYNOMES/*.txt;do
	echo $file >> raw_poly_data.txt
	echo "" >> raw_poly_data.txt
	tail -5 $file >> raw_poly_data.txt
	echo "" >> raw_poly_data.txt
	echo "" >> raw_poly_data.txt
	echo "DONE"
done
