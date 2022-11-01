#include <Arduino.h>
#include "PolynomFun/PolynomFun.h"

/* float get_FloatUART();

void setup() {
  Serial.begin(9600);

  Serial.println(IntroducingText);
}

void loop() {
  if(Serial.available()>0){
    String command = Serial.readString();
    results_t results = get_funResults(command);
    for(int i=0; i<results.fx_num; i++){
      Serial.println(results.fx[i]);
    }
    Serial.println(IntroducingText);
  }
}


float get_FloatUART(){
  float data;
  data = (Serial.available()) ? Serial.parseFloat() : data;
  return data;
} */

/*Ejemplo: Desarrolla un programa que permita calcular los permita obtener los primeros 100
valores de las siguientes funciones matemáticas, pudiendo seleccionar de cuál se realiza el
cálculo.
a) Recta: 𝑦 = 𝑚x + 𝑛𝑛.
b) Parábola: 𝑦 = 𝑎x^2 + 𝑏𝑏x + c.
Todos los datos necesarios deben ser introducidos por teclado. Es necesario que los datos sean
solicitados al usuario. El resultado también debe mostrarse al mismo.

*/
bool start = LOW;
float readFloat(void);
float calcularRecta(float pendiente, float offset, float variable);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float m,n;

  if (start == LOW){
    Serial.println("Introducir los parámetros de la recta m y n (y=mx+n) como floats separados por comas. Ej. 12.7,2.98");
    start = HIGH;
  } 
  else if(Serial.available()>0){

    m = readFloat();
    n = readFloat();

    
    for (int i = 0; i<100; i++){
      //Serial.println(calcularRecta(m,n,float(i)));
    }
    start = LOW;
  }  
}

float calcularRecta (float pendiente, float offset, float variable){
  float value;
  value = pendiente * variable + offset;
  return value;
}

float readFloat (void){
  float dataInFloat;

  if (Serial.available() > 0) {
    // read the incoming float:
    dataInFloat = Serial.parseFloat();
    Serial.println(dataInFloat);
    dataInFloat = Serial.parseFloat();
    Serial.println(dataInFloat);
    dataInFloat = Serial.parseFloat();
    Serial.println(dataInFloat);

    // say what you got:
    /*Serial.print("I received: ");
    Serial.println(dataInFloat);*/
  }
  return dataInFloat;
}

