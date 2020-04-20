#include "stdio.h"
#include "math.h"
#include "RL.h"

void RL(float V,float R,float L,float t,){
    float const_t=-R/L;
    float iL,i,dt,waktu;
    iL=0;
    dt=0;
    i=V/R;
    while (iL<i && waktu<t){
        waktu=dt*0.000001;
        iL=i*(1-exp((const_t)*waktu));
        printf("Pada waktu %.6lf arus pada induktor = %lf\n",waktu,iL);
        dt++;
    }
}