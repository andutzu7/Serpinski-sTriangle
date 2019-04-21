#include <iostream>
#include "graphics.h"
#include <cmath>
using namespace std;
#define iteratii 20000
// plan de bataie: introducere a  3 pct in plan apoi asocierea unor nr tip zar 1,2 3,4 5,6 -1...
float x1=150;
float yl=350;
float x2=550;
float y2=150;
float x3=750;
float y3=500;//AM 3 PCT LA DISTANTA CARE IMI PLACE
float x_init=555;
float y_init=255;
int factor=0;
unsigned long long nr_it=0;
int dice()

{
    int n;
    n=rand()%6;
    return n;

}
int generate_color()
{
    int n;
    n=rand()%256;
    return n;

}
void calculare_distanta(float x1,float y1,float x2,float y2,float &newx,float &newy)
{
    newx=(x1+x2)/2.0;
    newy=(y1+y2)/2.0;

}
void create_fractal(float x,float y)
{
    nr_it++;
    Sleep(10);
    if(nr_it < iteratii)
    {


        float nx;
        float ny;
        int n=dice();
        cout<<n<<" ";
        int c1,c2,c3;
        c1=generate_color();
        c2=generate_color();
        c3=generate_color();
        putpixel(x,y,COLOR(c1,c2,c3));
        if(n==0||n==1)
        {

            calculare_distanta(x,y,x1,yl,nx,ny);
            create_fractal(nx,ny);
        }

        if(n==2 || n==3)
        {


            calculare_distanta(x,y,x2,y2,nx,ny);
            create_fractal(nx,ny);
        }

        if(n==4 ||n==5)
        {
            calculare_distanta(x,y,x3,y3,nx,ny);
            create_fractal(nx,ny);
        }
    }
}
int main()
{
    initwindow(1080,720);
    putpixel(x1,yl,WHITE);//150,350
    putpixel(x2,y2,WHITE);
    putpixel(x3,y3,WHITE);
    for(; nr_it<100000000; ++nr_it)
 {



        factor=0;
        float nx;
        float ny;
        int n=dice();
        int c1,c2,c3;
        c1=generate_color();
        c2=generate_color();
        c3=generate_color();
        if(n==0||n==1)
        {

            calculare_distanta(x_init,y_init,x1,yl,nx,ny);

            putpixel(nx,ny,COLOR(c1,c2,c3));
        }

        if(n==2 || n==3)
        {


            calculare_distanta(x_init,y_init,x2,y2,nx,ny);
            putpixel(nx,ny,COLOR(c1,c2,c3));
        }

        if(n==4 ||n==5)
        {

            calculare_distanta(x_init,y_init,x3,y3,nx,ny);
            putpixel(nx,ny,COLOR(c1,c2,c3));


        }

        x_init=nx;
        y_init=ny;

  //cout<<nx<<" "<<ny<<" ";

  Sleep(100);
    }
    getch();

}

