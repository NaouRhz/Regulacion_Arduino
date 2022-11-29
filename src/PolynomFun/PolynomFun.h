#ifndef POLYNOMFUN_H
#define POLYNOMFUN_H

#include <Arduino.h>
#include <math.h>
#include "tools/tools.h"

const String textoIntro = "Seleccionar 1 (recta) 2 (parábola) y introduzca los datos como indica el ejemplo siguiente\nEjemplo recta (y=mx+n):     0.5x+2.5\nIntroducir por teclado:     1 0.5 2.5 \n\n\t\tEjemplo parábola (y=ax^2+bx+c):     2x^2+0.1x+3 \nIntroducir por teclado:             2 2 0.1 3";
/*
    Seleccionar 1 (recta) 2 (parábola) y introduzca los datos como indica el ejemplo siguiente
    Ejemplo recta (y=mx+n):     0.5x+2.5 
    Introducir por teclado:     1 0.5 2.5 

    Ejemplo parábola (y=ax^2+bx+c):     2x^2+0.1x+3 
    Introducir por teclado:             2 2 0.1 3 
*/

void PolynomFun(){
    float x=0;
    float inc=1;
    float data[4];
    int dataLen = sizeof(data)/sizeof(typeof(data));
    int i=1;
    float y[100];
    
    while((Serial.available()>0) && (dataLen>=i)){
        data[dataLen-(i++)] = get_FloatUART();
    }

    if(data[dataLen-1]==1){
        for(int i=0; i<101; i++){
            y[(int)x] = data[dataLen-2]*x+data[0];
            x+=inc;
        }    
    }
    else if(data[dataLen-1]==2){
        for(int i=0; i<101; i++){
            y[(int)x] = data[dataLen-2]*x*x+ data[dataLen-3]*x+data[0];
            x+=inc;
        }
    }    

}

#endif /*   POLYNOMFUN_H   */