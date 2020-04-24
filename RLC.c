#include <stdio.h>
#include <math.h>

void inputRLC ()
{
    double R;
    double L;
    double C;
    double t;
    double V;
    printf("Masukkan nilai resistor : ");
    scanf("%lf", &R);
    while(R<0)
    {
        printf("Input salah silakan masukan input ulang!!\n");
        printf("Masukkan nilai resistor : ");
        scanf("%lf", &R);
    }
    printf("Masukkan nilai induktor : ");
    scanf("%lf", &L);
    while(L<0)
    {
        printf("Input salah silakan masukan input ulang!!\n");
        printf("Masukkan nilai induktor : ");
        scanf("%lf", &L);
    }
    printf("Masukkan nilai kapasitor : ");
    scanf("%lf", &C);
    while(C<0)
    {
        printf("Input salah silakan masukan input ulang!!\n");
        printf("Masukkan nilai kapasitor : ");
        scanf("%lf", &C);
    }
    printf("Masukkan nilai sumber tegangan : ");
    scanf("%lf", &V);
    while(V<0)
    {
        printf("Input salah silakan masukan input ulang!!\n");
        printf("Masukkan nilai sumber tegangan : ");
        scanf("%lf", &V);
    }
    printf("Masukkan durasi perhitungan dalam mikrosecond : ");
    scanf("%lf", &t);
    while(t<0)
    {
        printf("Input salah silakan masukan input ulang!!\n");
        printf("Masukkan durasi perhitungan dalam mikrosecond : ");
        scanf("%lf", &t);
    }
    return;
}
void hitungRLC(double R, double L, double C, double t,double V)
{
    inputRLC();
    double vt, vss, vc;
    double omega = 1/sqrt(L*C);
    double alpha = R/(2*L);
    double s1, s2, A1, A2;
    double io = V/R;
    s1= -alpha + sqrt((alpha*alpha)-(omega*omega));
    s2= -alpha - sqrt((alpha*alpha)-(omega*omega));
    vss = V;
    
    if(alpha > omega)
    {   
        A2 = (((1/C)*io)+vss*s1)/(-s1+s2);
        A1 = -A2-vss;
        vt = (A1*exp(s1*t))+(A2*exp(s2*t));
    }
    else if(alpha == omega)
    {
        A1 = -vss;
        A2 = ((1/C)*io)+2*alpha+vss;
        vt = (A1+(A2*t))*(exp(-alpha*t));
    }
    else
    {
        A1 = -vss;
        A2 = ((1/C)*io)/(omega*-alpha);
        vt = ((A1*cos(omega*t))+(A2*sin(omega*t)))*(exp(-alpha*t));
    }

    vc = vss+vt;
    printf("Tegangan output = %.4lf\n ", vt);
    return;
}

int main ()
{
    double R;
    double L;
    double C ;
    double  t;
    double V;

    hitungRLC(R, L, C, t, V);

    return (0);
}
