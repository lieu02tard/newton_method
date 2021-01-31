#include "math.h"
#include <iostream>
using namespace std;
namespace MyMath
{
    const double aprox_1=1e-8;
    int solve(double f(double),double dev_f(double),double top,double bot,double* res_1,double* res_2,double approach=aprox_1)
    {
        if(f(top)==0) {*res_1=top;*res_2=top;return 1;}
        if(f(bot)==0) {*res_1=bot;*res_2=bot;return 2;}
        if ((f(top)<0)||(f(bot)>0)) return -1;
        double x=bot;
        while (abs(f(x))>approach)
        {
            x-=(f(x))/(dev_f(x));
        }
        *res_1=x;
        x=top;
        while(abs(f(x))>approach)
        {
            x-=(f(x)/(dev_f(x)));
        }
        *res_2=x;
        return 0;
    }
}
double func(double d)
{
    return d*exp(d)-1;
}
double dev_func(double d)
{
    return (d+1)*exp(d);
}
int main()
{
    double x1,x2;
    cout<<MyMath::solve(func,dev_func,1,0,&x1,&x2,1e-24)<<endl;
    printf("%1.20f \n",x1);
    printf("%1.20f \n",x2);
}
