# Exploring-the-distribution-of-roots-of-polynomials-with-bounded-integer-coef-cients

I have undertaken this as my Honors Project in Computer Science and Mathematics. The detail about the work can be found in the .pdf file.

In order to run the program, you can use the following commands.

AXIOM - axiom.input - POLYNOMIAL GENERATION.

Make sure you have Axiom installed. You can get the program here:
http://www.axiom-developer.org/axiom-website/download.html

First 'cd' into the folder "RAW_POLYNOME"
Then run Axiom by writing "axiom" in console. 
You can close the GUI that will pop out.
Run "axiom.input". The files will generate on their own.
If you would like to generate polynomials of specific degree, bound pair, you can just change the parameters at the top of the file.

C/C++ - PolynomialRootFinder.cpp - ROOT FINDING and ASSUMPTION TESTING

Make sure you are in the main folder.
Compile the program using: 
g++ -o poly PolynomialRootFinder.cpp -std=c++11 -lgsl -lgslcblas -lm

Here is an example on how to use the "poly" program:

./poly 10 200 RAW_POLYNOMES/ax-10-1-20.txt

Note the arguments:
10 - degree of polynomials
200 - final sample size (how many polynomials are there in the file "ax-10-1-20.txt")
You can find the final size at the bottom of the .txt file. Since the files are usually quite big and can take some time to open, you can use this command: "tail -5 ax-10-1-200.txt". This will give you the metadata about the generated sample, including the final sample size.
Last argument is the file with the polynomials


Program will generate 2 file. A file with results, which is located in the folder "RESULTS" and gives the information about the assumptions. And a file with a heatmaps in the folder "RESULTS/HeatMaps". Note that these heatmaps are in .txt format for now.

R - heat_map.R - Generate the HeatMaps
You will need the R Studio. You can get it here: https://www.rstudio.com/
Once you have the R Studio open, you can just run the entire script. 

This will create an image.jpg for every .txt file inside the folder "RESULTS/HeatMaps".

There are also bash scripts that you can use.

The program is "as it is", no guarantee of any kind is given. Other then that you can freely use it, as long as it is not for commercial use.


