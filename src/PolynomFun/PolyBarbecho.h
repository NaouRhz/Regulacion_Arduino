#include <Arduino.h>

typedef struct{
    float* fx;
    int fx_num;
}results_t;

typedef struct{
    float* coefficients;
    int degree;
}degreeANDcoeffi_t;

const String IntroducingText = "\t\tFunctions calculator\n\nPlease enter your ecuation as is indicated\n\n f(x): a4x^4+a3x^3+a2x^2+a1x+2 --> Introduce a4 a3 a2 a1 2\n\n NOTE: if any term is 0 introduce 0 like is indicated\n\n f(x): a4x^4+a3x^3+a1x --> Introduce a4 a3 0 a1 0";

results_t get_funResults(String cmd);
degreeANDcoeffi_t get_coefficients(String cmd);
bool verify_fx(degreeANDcoeffi_t parameters);

/*CPP*/

results_t get_funResults(String cmd){
  degreeANDcoeffi_t parameters = get_coefficients(cmd);

  if(!verify_fx({parameters.coefficients, parameters.degree})){
    Serial.println("There was an error entering data, please try again.");
    return {nullptr, 0};
  }

  int results_num = 100;
  int inc = 1;

  //dynamic array assignment for results or images
  float* fx_results = (float*) calloc(results_num, sizeof(float));
  
  for(int j=1; j<=(results_num+1); j+=inc){
    if(j==0){
        fx_results[j]=parameters.coefficients[j];
    }
    else{
        for (int i=0; i<=parameters.degree; i++){
            fx_results[j] += (i==0) ? parameters.coefficients[0] : 
                                      parameters.coefficients[i]*pow(j,i);
        }
    }
  }
  
  return {fx_results, results_num};
}

degreeANDcoeffi_t get_coefficients(String cmd){
  int degree=0;
  float* coeffiVolatil = (float*) malloc (20*sizeof(float)); //reserve memory
  

  for(int i=0; cmd.indexOf(" ")>0; i++){
    degree++;
    String aux = cmd.substring(0, cmd.indexOf(" "));
    coeffiVolatil[i] = aux.toFloat();
    cmd = cmd.substring(cmd.indexOf(" ")+1);
    
    if(cmd.indexOf(" ")<0){
      i++;
      coeffiVolatil[i] = cmd.toFloat();
    } 
  }
  
  float* coefficients = (float*) malloc((degree+1)*sizeof(float));
  for(int i=degree,j=0; i>=0; i--,j++){
    coefficients[i]=coeffiVolatil[j];
  }

  free(coeffiVolatil); //Free memory
  
  return {coefficients, degree};
}

bool verify_fx(degreeANDcoeffi_t parameters){
  for(int i=parameters.degree; i>=0; i--){
    if(i==parameters.degree) Serial.print("f(x): ");

    if(parameters.coefficients[i]<0){
      Serial.print(" "); Serial.print(parameters.coefficients[i]); 
      if(i!=0) {
        Serial.print("x^"); Serial.print(i);
      }
    }
    else{
      Serial.print(" +"); Serial.print(parameters.coefficients[i]); 
      if(i!=0) {
        Serial.print("x^"); Serial.print(i);
      }
    }
  }
  Serial.println("\nPlease verify the ecuation is correct, in positive case enter: y");
  while (!Serial.available()){}
  
  return (Serial.readString()=="y") ? true : false;
}