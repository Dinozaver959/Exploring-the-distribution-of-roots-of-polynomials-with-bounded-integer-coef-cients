
#include "poly_JT.h"
#include <stdlib.h>
#include <gsl/gsl_poly.h>
#include <string.h>
#include <stdio.h>
//#include <math.h>
#include "sort_arrays.h"
#include "read_poly_string.h"


//------------------------------------------------------------------------------------------------------------------------------------

// check if the point is within the circle
int is_in_circle(double c_x, double c_y, double c_r, double x, double y){
  if(pow((c_x - x),2) + pow((c_y - y),2) < pow(c_r,2)){
	return 1;
  } else {
	return 0;
  }
}



// compare all the zeros of JT and QR method to the 'precission' specified, return 1 if all are equal and 0 otherwise
int compare(double* r_JT, double* i_JT, double* r_QR, int degree, double precision){

  int i;
  for (i = 0; i < degree; i++){	// it is 0 and # of precission decimal places
  
    if ( fabs(r_JT[i] - r_QR[2*i]) < precision  &&  fabs(i_JT[i] - r_QR[2*i+1]) < precision){
	// ok, zeros match
    } else {
	return 0; // at least 1 zero does not match
    }
  }
    return 1;	// all zeros match
}




// given a polynome, apply both methods, call the function to compare the zeros and print the zeros if the methods agree
int poly_to_result(double* a, int degree, FILE* output_file, double precision, int m_size, int* m_pointer, int* s_pointer, int* s_i_pointer, int* s_45_pointer, int* l_pointer, int* h_pointer, int heat_precision, double x_l, double x_u, double y_l, double y_u, int* area_pointer, int area_arr_size, int* in_a){


  //------------------------------------
  // JT method
  //------------------------------------
  double zeror_JT[degree];
  double zeroi_JT[degree];

  my_space::rpoly_ak1(a, &degree, zeror_JT, zeroi_JT);
  
  double *r_JT = (double*) zeror_JT;
  double *i_JT = (double*) zeroi_JT;

  sort_arrays_JT(r_JT, i_JT, degree); 


  //------------------------------------
  // QR method
  //------------------------------------
  // QR method requires that coefficients be given from smallest degree to the biggest
  // Hence, you need to reverse the array, before passing it to any of the functions below

  double *p_a = (double*) a;
  reverse_a(p_a, degree);

  double z_QR[2* degree];
  gsl_poly_complex_workspace * w = gsl_poly_complex_workspace_alloc (degree + 1);
  gsl_poly_complex_solve (a, degree + 1, w, z_QR);
  gsl_poly_complex_workspace_free (w); 

  double *r_QR = (double*) z_QR;
  sort_array_QR(r_QR, degree);


  //----------------
  // compare both methods
  //----------------
  // return 1 if they are equal and 0 otherwise
  int are_equal = compare(r_JT, i_JT, r_QR, degree, precision);


  // proceed only if methods agree on all roots
  if (are_equal == 1){

    // for each item in m-array, perform the loop below
    // KK CONJECTURE WITH CIRCLES
    int i;
    for (i = 0; i < m_size; i++){

      int m = m_pointer[i];

      double L_x = 0;
      double L_y = 0;
      double L_r = ((double)(m+2)) / ((double)(m+3)); 
      double S_x = ((double)(2*pow(m,2)+8*m+7)) / ((double)(2*(m+2)*(m+3)));
      double S_y = 0;
      double S_i_x = 0;
      double S_i_y = ((double)(2*pow(m,2)+8*m+7)) / ((double)(2*(m+2)*(m+3)));
      double S_45_x = (1/sqrt(2)) * ((double)(2*pow(m,2)+8*m+7)) / ((double)(2*(m+2)*(m+3)));
      double S_45_y = (1/sqrt(2)) * ((double)(2*pow(m,2)+8*m+7)) / ((double)(2*(m+2)*(m+3)));
      double S_r = 1 / ((double)(2*(m+2)*(m+3)));


      // Check if the root is inside the big and/or inside the small circle

      int j;
      for (j = 0; j < degree; j++){
        double p_x = (zeror_JT[j] + z_QR[2*j]) / 2;
        double p_y = (zeroi_JT[j] + z_QR[2*j+1]) / 2;

        l_pointer[i] += is_in_circle(L_x, L_y, L_r, p_x, p_y);
        s_pointer[i] += is_in_circle(S_x, S_y, S_r, p_x, p_y);
        s_i_pointer[i] += is_in_circle(S_i_x, S_i_y, S_r, p_x, p_y);
        s_45_pointer[i] += is_in_circle(S_45_x, S_45_y, S_r, p_x, p_y);
      }  
    }


    // testing the area near the real line, always halving the area and looking how many roots are in there
    int h;
    for(h=0; h < area_arr_size; h++){
	
	double x_1 = 0.5;
	double x_2 = 1.5;
	double y_1 = 0;
	double y_2 = 0.25 / area_pointer[h];

	int j;
	for(j=0; j < degree; j++){
            double p_x = (zeror_JT[j] + z_QR[2*j]) / 2;
            double p_y = (zeroi_JT[j] + z_QR[2*j+1]) / 2;
	    
	    if( x_1 < p_x && p_x < x_2 && y_1 < p_y && p_y < y_2){
		in_a[h] += 1;
	    }
	}

    }


// ----------------
// print to the file
// ----------------
    int j;
    for (j = 0; j < degree; j++){
// -----------------------------------
// UNCOMMENT NEXT LINE TO WRITE THE ROOTS TO A FILE
// ---------------------------------
      //fprintf (output_file, "%+.18f %+.18f\n", (zeror_JT[j] + z_QR[2*j])/2, (zeroi_JT[j] + z_QR[2*j+1])/2);

	// IF YOU WANT TO PRINT A VARIABLE NUMBER OF DIGITS (SUCH AS PRECISION), THEN USE
	// printf("%*.*f", width, precision, value-zero);
    }


// ----------------------------------------
//  Add the point to the Heat map
// ----------------------------------------    
    for (j = 0; j < degree; j++){
       // determine in which entry of the MATRIX should the point go, add +1 into that entry
        double p_x = (zeror_JT[j] + z_QR[2*j]) / 2;
        double p_y = (zeroi_JT[j] + z_QR[2*j+1]) / 2;
      
       // extra point (1/alfa)
        double p_x_inverse = p_x / (pow(p_x,2) + pow(p_y,2));
        double p_y_inverse = - p_y / (pow(p_x,2) + pow(p_y,2));


        // for the real roots
        if (x_l < p_x && p_x < x_u && y_l < p_y && p_y < y_u){     
          int x_entry = floor((p_x - x_l)/(x_u - x_l) * (2*heat_precision));
          int y_entry = floor((p_y - y_l)/(y_u - y_l) * (2*heat_precision));
          h_pointer[x_entry + 2*heat_precision * y_entry] += 1;
	}

        // for the inverse roots
        if (x_l < p_x_inverse && p_x_inverse < x_u && y_l < p_y_inverse && p_y_inverse < y_u){     
          int x_inverse_entry = floor((p_x_inverse - x_l)/(x_u - x_l) * (2*heat_precision));
          int y_inverse_entry = floor((p_y_inverse - y_l)/(y_u - y_l) * (2*heat_precision));
          h_pointer[x_inverse_entry + 2*heat_precision * y_inverse_entry] += 1;
	}


    }

  }
  
  return are_equal;
}







int main(int argc, char **argv){

    if(argc != 4){
        std::cout << ("\n 3 args required! \n 1st: degree of polynomials \n 2nd: sample size \n 3nd: input file \n\n");
	return 0;
    }

    // HEATMAP PARAMETERS
    // -----------------------------------------------------------------------------------
    // CAREFUL: MAKE SURE YOU ALSO ADJUST "Heat_Map"
    const int heat_precision = 256; // should be of power 2,  0-1 is divided into 256 parts    
    static int Heat_Map [(int) pow(2*256,2)] = {0};
    int * h_pointer = Heat_Map;
    // Set the bounds for heatmap display
    const double x_lower_b = -2;
    const double x_upper_b =  2;
    const double y_lower_b = -2;
    const double y_upper_b =  2;
    // -----------------------------------------------------------------------------------
    // MAKE A STRING OUT OF PARAMETERS
    
    char h_buff [8];
    snprintf(h_buff, sizeof(h_buff), "%d", heat_precision);
    char x_l_buff [8];
    snprintf(x_l_buff, sizeof(x_l_buff), "%.2f", x_lower_b);
    char x_u_buff [8];
    snprintf(x_u_buff, sizeof(x_u_buff), "%.2f", x_upper_b);
    char y_l_buff [8];
    snprintf(y_l_buff, sizeof(y_l_buff), "%.2f", y_lower_b);
    char y_u_buff [8];
    snprintf(y_u_buff, sizeof(y_u_buff), "%.2f", y_upper_b);
    
    char * h_param_string = (char *) malloc(1 + strlen("_") + strlen(h_buff) + strlen("_") + strlen(x_l_buff) + strlen("_") + strlen(x_u_buff) + strlen("_") + strlen(y_l_buff) + strlen("_") + strlen(y_u_buff) + strlen(".txt"));

    strcpy(h_param_string, "_");
    strcat(h_param_string, h_buff);
    strcat(h_param_string, "_");
    strcat(h_param_string, x_l_buff);
    strcat(h_param_string, "_");
    strcat(h_param_string, x_u_buff);
    strcat(h_param_string, "_");
    strcat(h_param_string, y_l_buff);
    strcat(h_param_string, "_");
    strcat(h_param_string, y_u_buff);
    strcat(h_param_string, ".txt");
    // -----------------------------------------------------------------------------------


    // INPUT ARGUMENTS
    // ------------------------------------------------------------------
    int degree = std::stoi(argv[1]); 
    int sampleSize = atoi(argv[2]);           
    FILE* file = fopen(argv[3], "r");         // input file with coefficients of polynomials

    // ------------------------------------------
    // FILE NAME FORMATING
    const char separator = '/';
    char * str_1;
    char * const sep_at = strrchr(argv[3], separator);
    if(sep_at != NULL){
      *sep_at = '\0';
      str_1 = sep_at + 3;    // +3, it is assumed that the input file name is "../ax-,,,", so delete "../ax"
    } else {
      str_1 = argv[3];
    }
    
    // this part will delete the ".txt" part in the str_1
    int g = 0;
    while(*(str_1 + g) != '\0'){
      if(*(str_1 + g) == '.'){
        *(str_1 + g) = '\0';
        break;
      }
      g++;
    }

    // -------------------------------------------
    // Heat Map File Name Formating
    char * heat_str_2 = (char *) malloc(1 + strlen("RESULTS/HeatMaps/heatmap") + strlen(str_1) + strlen(h_param_string));
    strcpy(heat_str_2, "RESULTS/HeatMaps/heatmap");
    strcat(heat_str_2, str_1);
    strcat(heat_str_2, h_param_string);
    FILE* heat_file = fopen(heat_str_2, "w");
    // -------------------------------------------
    // Results File Name Formating
    char * results_str_2 = (char *) malloc(1 + strlen("RESULTS/res") + strlen(str_1));
    strcpy(results_str_2, "RESULTS/res");
    strcat(results_str_2, str_1);
    FILE* results_file = fopen(results_str_2, "w");
    // -------------------------------------------
    // Zeros File Name Formating
    char * output_str_2 = (char *) malloc(1 + strlen("RESULTS/Zeros/zeros") + strlen(str_1));
    strcpy(output_str_2, "RESULTS/Zeros/zeros");
    strcat(output_str_2, str_1);
    FILE* output_file = fopen(output_str_2, "w");  
    // -------------------------------------------
    char * output_str_3 = (char *) malloc(1 + strlen("RESULTS/GoodPoly/good") + strlen(str_1));
    strcpy(output_str_3, "RESULTS/GoodPoly/good");
    strcat(output_str_3, str_1);
    FILE* good_file = fopen(output_str_3, "w"); 
    // -------------------------------------------

    double precision = pow(10, -12); // set the number of decimal places for comparison of the 2 methods

    double* a;

    int k = 0;
    char line[256];
    char raw_poly[256];

    int agreeing = 0;
    int disagreeing = 0;

    int area[] = {1,2,4,8,16,32,64,128,256,512,1024};  // is used to the checking of that area near the real line (area is halved on every iteration, defult is 1/4 of unit, e,g, imaginary part (0,1/4))
    int * area_pointer = area;
    int area_arr_size = sizeof(area)/sizeof(area[0]);
    int * in_a = (int *) calloc( area_arr_size, sizeof(area[0]));

    int m[] = {1,2,4,8,16,32,64,128,256,512,1024};
    int * m_pointer = m;
    int m_size = (sizeof (m)) / (sizeof(*m));
    
    int s [50] = {};
    int s_i [50] = {};
    int s_45 [50] = {};
    int l [50] = {};
    int * s_pointer = s;
    int * s_i_pointer = s_i;
    int * s_45_pointer = s_45;
    int * l_pointer = l;

    while(fgets(line, sizeof(line), file)){

	int j;
	for (j = 0; j < 256; j++){
		raw_poly[j] = line[j];
	}

        a = string_to_int_array(line, degree);

//printf("starting %s polynomial\n\n", line);

        int tmp = poly_to_result(a, degree, output_file, precision, m_size, m_pointer, s_pointer, s_i_pointer, s_45_pointer, l_pointer, h_pointer, heat_precision, x_lower_b, x_upper_b, y_lower_b, y_upper_b, area_pointer, area_arr_size, in_a);

	if (tmp  == 1){
		agreeing += 1;

		// TO PRINT THE GOOD POLY TO A FILE, UNCOMMENT THE NEXT FEW LINES
		// fprintf(good_file, "(");
		// int q;
		// for(q = degree; q > 0; q--){ fprintf(good_file, "%d ", (int) a[q]); }
		// fprintf(good_file, "%d)\n", (int) a[0]);
	}
	else{ disagreeing += 1;}

        k += 1;

    if( k == sampleSize){
        break;
    }

//printf("\n %d \n", agreeing + disagreeing);
  }

  fprintf(results_file, "Polynomial file name:     %s\n", argv[3]);
  fprintf(results_file, "\nmatching polynomials:     %d", agreeing);
  fprintf(results_file, "\nnot-matching polynomials: %d\n\n", disagreeing);

  fprintf(results_file, "\nS on the real line\n");  
  fprintf(results_file, "\nm \tin S \t\tE[Sm] \t\t\tin L \t\tE[Lm] \t\t\tum \t\t\tem\n");
  // s (on real line)
  // Print results to the file
  int i;
  for (i = 0; i < m_size; i++){
    double E_Sm = ((double) s[i])/agreeing;
    double E_Lm =  ((double) l[i])/agreeing;
    double sm = 1 / ((double)(2*(m[i]+2)*(m[i]+3)));
    double lm = ((double) (m[i] + 2)) / ((double) (m[i] + 3));

    fprintf(results_file, "%d \t", m[i]);
    fprintf(results_file, "%d \t\t", s[i]);
    fprintf(results_file, "%.12f \t\t", E_Sm);
    fprintf(results_file, "%d \t\t", l[i]);
    fprintf(results_file, "%.12f \t\t", E_Lm);
    fprintf(results_file, "%.12f \t\t",   E_Lm * pow((sm /lm),2));
    fprintf(results_file, "%.12f \n", (log(E_Sm / E_Lm)) / (log(sm / lm)));
  }

  fprintf(results_file, "\n\n\nS on the imaginary line\n");  
  fprintf(results_file, "\nm \tin S \t\tE[Sm] \t\t\tin L \t\tE[Lm] \t\t\tum \t\t\tem\n");
  // s (on imaginary line)
  // Print results to the file
  for (i = 0; i < m_size; i++){
    double E_Sm = ((double) s_i[i])/agreeing;
    double E_Lm =  ((double) l[i])/agreeing;
    double sm = 1 / ((double)(2*(m[i]+2)*(m[i]+3)));
    double lm = ((double) (m[i] + 2)) / ((double) (m[i] + 3));

    fprintf(results_file, "%d \t", m[i]);
    fprintf(results_file, "%d \t\t", s_i[i]);
    fprintf(results_file, "%.12f \t\t", E_Sm);
    fprintf(results_file, "%d \t\t", l[i]);
    fprintf(results_file, "%.12f \t\t", E_Lm);
    fprintf(results_file, "%.12f \t\t",   E_Lm * pow((sm /lm),2));
    fprintf(results_file, "%.12f \n", (log(E_Sm / E_Lm)) / (log(sm / lm)));
  }

  fprintf(results_file, "\n\n\nS on the line at 45 degrees\n");
  fprintf(results_file, "\nm \tin S \t\tE[Sm] \t\t\tin L \t\tE[Lm] \t\t\tum \t\t\tem\n");
  // s (on line at 45 degree angle)
  // Print results to the file
  for (i = 0; i < m_size; i++){
    double E_Sm = ((double) s_45[i])/agreeing;
    double E_Lm =  ((double) l[i])/agreeing;
    double sm = 1 / ((double)(2*(m[i]+2)*(m[i]+3)));
    double lm = ((double) (m[i] + 2)) / ((double) (m[i] + 3));

    fprintf(results_file, "%d \t", m[i]);
    fprintf(results_file, "%d \t\t", s_45[i]);
    fprintf(results_file, "%.12f \t\t", E_Sm);
    fprintf(results_file, "%d \t\t", l[i]);
    fprintf(results_file, "%.12f \t\t", E_Lm);
    fprintf(results_file, "%.12f \t\t",   E_Lm * pow((sm /lm),2));
    fprintf(results_file, "%.12f \n", (log(E_Sm / E_Lm)) / (log(sm / lm)));
  }


  // printf the h-area data to the result file
  fprintf(results_file, "\n\nh\tin H area \t\t(note the default size is 1/4, the size is than 0.25/h\n");
  for(i=0; i < (int) sizeof(area)/sizeof(area[0]); i++){
    fprintf(results_file, "%d\t%d\n", area[i], in_a[i]); 
  }



  // Print Heat Map to the file
  for (i = 0; i < 2*heat_precision; i++){
    int j;
    for (j = 0; j < 2*heat_precision; j++){
      if(j == 2*heat_precision - 1){
        fprintf(heat_file, "%d", h_pointer[2*heat_precision * i + j]);
      } else {
        fprintf(heat_file, "%d ", h_pointer[2*heat_precision * i + j]);
      }
    }
    fprintf(heat_file, "\n");
  }


  printf("Done.....\n\n");

  fclose (file);
  fclose (output_file);
  fclose (results_file);
  fclose (heat_file);
  fclose (good_file);
  return 0;
}

