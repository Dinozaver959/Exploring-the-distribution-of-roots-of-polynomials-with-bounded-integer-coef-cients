
// sort the array for JT method
void sort_arrays_JT(double* zeror, double* zeroi, int degree){

    int n = degree; 

    int i;
    for (i = 0; i < n; i++){
        int j;
        for(j = i+1; j < n; j++){
            if (zeror[i] < zeror[j]){  // swap   
		
		double temp = zeror[i]; 
		zeror[i] = zeror[j];
		zeror[j] = temp;

		double tmp = zeroi[i];
		zeroi[i] = zeroi[j];
		zeroi[j] = tmp;
		
            }
            else if (zeror[i] == zeror[j]){ // if the real part is the sane, check the imaginary part to compare        
                if(zeroi[i] < zeroi[j]){ // swap

 		double temp = zeror[i]; 
		zeror[i] = zeror[j];
		zeror[j] = temp;

		double tmp = zeroi[i];
		zeroi[i] = zeroi[j];
		zeroi[j] = tmp;   
  
                }
            }
        }
    }
}



// sort the 2 arrays for QR method
void sort_array_QR(double* zeros, int degree){

    int n = degree; 

    int i;
    for (i = 0; i < 2*n; i+=2){
        int j;
        for(j = i+2; j < 2*n; j+=2){
            if (zeros[i] < zeros[j]){  // swap   
		
		double temp = zeros[i]; 
		zeros[i] = zeros[j];
		zeros[j] = temp;

		double tmp = zeros[i+1];
		zeros[i+1] = zeros[j+1];
		zeros[j+1] = tmp;
		
            }
            else if (zeros[i] == zeros[j]){ // if the real part is the sane, check the imaginary part to compare        
                if(zeros[i+1] < zeros[j+1]){ // swap

 		double temp = zeros[i]; 
		zeros[i] = zeros[j];
		zeros[j] = temp;

		double tmp = zeros[i+1];
		zeros[i+1] = zeros[j+1];
		zeros[j+1] = tmp;   
  
                }
            }
        }
    }
}




void reverse_a(double* p_a, int degree){

  int n = degree;

  int i;
  for (i = 0; i < ceil(degree/2); i++){
	double temp = p_a[i];
	p_a[i] = p_a[n-i];
	p_a[n-i] = temp;
  }

}



