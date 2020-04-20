#include "stdio.h"
#include "InputVerification.h"

//Input Procedure
//X for Label, *n for variable
void Input(char X,float *n){
    //R atau r untuk memberikan input suatu resistor
    if ((X=='R')||(X=='r')){
        printf("Masukkan nilai Resistor:");
        scanf("%f",n);
        while (*n < 0){
            printf("Resistansi tidak boleh bernilai negatif \n");
            printf("Masukkan nilai resistor:");
            scanf("%f",n);
        }
    }
    //C atau c untuk memberikan input suatu kapasitor
    else if ((X=='C')||(X=='c')){
        printf("Masukkan nilai Kapasitor:");
        scanf("%f",n);
        while (*n < 0){
            printf("Kapasitansi tidak boleh bernilai negatif \n");
            printf("Masukkan nilai kapasitor:");
            scanf("%f",n);
        }
    }
    //I atau i untuk memberikan input suatu Induktor
    else if ((X=='I')||(X=='i')){
        printf("Masukkan nilai Induktor:");
        scanf("%f",n);
        while (*n < 0){
            printf("Induktansi tidak boleh bernilai negatif \n");
            printf("Masukkan nilai induktor:");
            scanf("%f",n);
        }
    }   
}