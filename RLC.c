#include <stdio.h>
#include <math.h>



/*void inputRLC ()
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
}*/
void hitungRLC()
{
    double R, V, t, L, C;
    double vt, vss, vc;

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

    double omega = 1/sqrt(L*C);
    double alpha = R/(2*L);
    double s1, s2, A1, A2;
    s1= -alpha + sqrt((alpha*alpha)-(omega*omega));
    s2= -alpha - sqrt((alpha*alpha)-(omega*omega));
    vss = V;
    double i;

    while(i<=t)
    {
        if(alpha > omega)
        {   
            A1 = vss / ((s1/s2)-1);
            A2 = vss / ((s2/s1)-1);
            vt = (A1*exp(s1*i))+(A2*exp(s2*i));
            vc = vss+vt;
            printf("%lf ", i);
            printf("%lf\n", vc);
            i = i+ 0.000001;

        }
        else if(alpha == omega)
        {
            A1 = alpha*(-vss);
            A2 = -vss;
            vt = (A1+(A2*i))*(exp(-alpha*i));
            vc = vss+vt;
            printf("%lf ", i);
            printf("%lf\n", vc);
            i = i+ 0.000001;
        }
        else
        {
            vt = - (vss*(exp(-alpha*i))*cos(omega*i)-((-alpha/omega)*sin(omega*i)));
            vc = vss+vt;
            printf("%lf ", i);
            printf("%lf\n", vc);
            i = i+ 0.000001;
        }
    }

    return;
    
}
