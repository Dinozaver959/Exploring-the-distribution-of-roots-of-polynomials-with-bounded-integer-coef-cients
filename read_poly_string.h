// just formalize the polynomial that was read from a file to an array representation 
// THIS PART IS HARD CODED - SHOULD BE ALTERED IF A DEGREE OF A POLYNOMIAL IS NOT 10,20 OR 30!
double* string_to_int_array(char* line, int degree){

  double* a;
  a = (double*) malloc (sizeof (double) * (degree + 1));
  int* b;
  b = (int*) malloc (sizeof (int) * (degree + 1));

  // THIS PART IS HARD CODED - YOU NEED TO SET THE EXACT NUMBER OF DIGITS(DEGREE) PER LINE

  if (degree == 4){
    sscanf(line,"(%d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4]);
  } else if (degree == 5){
    sscanf(line,"(%d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5]);
  } else if (degree == 6){
    sscanf(line,"(%d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6]);
  } else if (degree == 7){
    sscanf(line,"(%d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7]);
  } else if (degree == 8){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8]);
  } else if (degree == 9){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9]);
  } else if (degree == 10){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10]);
  } else if (degree == 11){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11]);
  } else if (degree == 13){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13]);
  } else if( degree == 17){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17]);
  }else if( degree == 19){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19]);
  } else if( degree == 20){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20] );
  } else if( degree == 23){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23]);
  } else if (degree == 29){ 
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29]); 
  } else if (degree == 30){ 
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30]);
  } else if (degree == 31){ 
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31]);  
} else if (degree == 37){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37]);     
  } else if (degree == 40){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40]);     
  } else if (degree == 41){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41]);     
  } else if (degree == 43){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43]);     
  } else if (degree == 47){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43], &b[44], &b[45], &b[46], &b[47]);  
  } else if (degree == 50){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43], &b[44], &b[45], &b[46], &b[47], &b[48], &b[49], &b[50]);  
  } else if (degree == 53){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43], &b[44], &b[45], &b[46], &b[47], &b[48], &b[49], &b[50], &b[51], &b[52], &b[53]);  
  } else if (degree == 60) {
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43], &b[44], &b[45], &b[46], &b[47], &b[48], &b[49], &b[50], &b[51], &b[52], &b[53], &b[54], &b[55], &b[56], &b[57], &b[58], &b[59], &b[60]); 
 } else if (degree == 75){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43], &b[44], &b[45], &b[46], &b[47], &b[48], &b[49], &b[50], &b[51], &b[52], &b[53], &b[54], &b[55], &b[56], &b[57], &b[58], &b[59], &b[60], &b[61], &b[62], &b[63], &b[64], &b[65], &b[66], &b[67], &b[68], &b[69], &b[70], &b[71], &b[72], &b[73], &b[74], &b[75]);  
 } else if (degree == 100){
    sscanf(line,"(%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d)", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11], &b[12], &b[13], &b[14], &b[15], &b[16], &b[17], &b[18], &b[19], &b[20], &b[21], &b[22], &b[23], &b[24], &b[25], &b[26], &b[27], &b[28], &b[29], &b[30], &b[31], &b[32], &b[33], &b[34], &b[35], &b[36], &b[37], &b[38], &b[39], &b[40], &b[41], &b[42], &b[43], &b[44], &b[45], &b[46], &b[47], &b[48], &b[49], &b[50], &b[51], &b[52], &b[53], &b[54], &b[55], &b[56], &b[57], &b[58], &b[59], &b[60], &b[61], &b[62], &b[63], &b[64], &b[65], &b[66], &b[67], &b[68], &b[69], &b[70], &b[71], &b[72], &b[73], &b[74], &b[75], &b[76], &b[77], &b[78], &b[79], &b[80], &b[81], &b[82], &b[83], &b[84], &b[85], &b[86], &b[87], &b[88], &b[89], &b[90], &b[91], &b[92], &b[93], &b[94], &b[95], &b[96], &b[97], &b[98], &b[99], &b[100]);  
 }

  int i;
  for (i = 0; i < degree + 1; i++){
    a[i] = (double) b[i];
  }

  if( a[0] == 0){

    printf("LEADING COEDDFICIENT IS ZERO...");
    printf("%s\n", line);

  }


  return a;  
}

