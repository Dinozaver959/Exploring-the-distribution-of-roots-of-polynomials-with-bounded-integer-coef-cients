#!/bin/bash

echo "This is end data about polynomials, after the main stage." > end_poly_data.txt

echo "" >> end_poly_data.txt

for file in RESULTS/REPORT/*;do
	echo $file >> end_poly_data.txt
	echo "" >> end_poly_data.txt
	head -20 $file | tail -18 >> end_poly_data.txt
	echo "" >> end_poly_data.txt
	echo "" >> end_poly_data.txt
	echo "DONE"
done
