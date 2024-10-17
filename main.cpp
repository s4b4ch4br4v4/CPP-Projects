#include <iostream>
#include <cmath>

using namespace std;



class Triangle2{
    private:

        // ANGLES & SIZE:

        double A;
        double B;
        double c;

    public:

        // THE CONSTRUCTOR:

        Triangle2(double A = 0, double B = 0, double c = 0){
            if(A >= M_PI || B >= M_PI){
                this->A = 0;
                this->B = 0;
                this->c = 0;
            } else if(A + B >= M_PI){
                this->A = 0;
                this->B = 0;
                this->c = 0;
            } else {
                this->A = A;
                this->B = B;
                this->c = c;
            }
        }

        // GETTERS:

        double GetA(){return A;}
        double GetB(){return B;}
        double Getc(){return c;}

        // THE LEFT ANGLE:

        double C(){
            if(GetA() == 0 || GetB() == 0){
                return -1;
            } else {
                return M_PI - (GetA() + GetB());
            }
        }

        // THE LEFT SIDES:

        double a(){
            return Getc() * ( sin(GetA()) / sin(C()) );
        }

        double b(){
            return Getc() * ( sin(GetB()) / sin(C()) );
        }

        // PERIMETRE & AREA:

        double P(){
            return a() + b() + Getc();
        }

        double S(){
            double p = P() / 2;
            if (p == 0){
                return -1;
            } else {
                return sqrt( p * ( p - a() ) * ( p - b() ) * ( p - Getc() ));
            }
        }

        // HEIGHTS:

        double Ha(){
            if(a() == 0){
                return 0;
            } else {
                return 2 * S() / a();
            }

        }

        double Hb(){
            if(b() == 0){
                return 0;
            } else {
                return 2 * S() / b();
            }
        }

        double Hc(){
            if(Getc() == 0){
                return 0;
            } else {
                return 2 * S() / Getc();
            }
        }

        // MEDIANS:

        double Ma(){
            if(b() == 0 || Getc() == 0){
                return -1;
            } else {
                return sqrt(2 * b()*b() + 2 * Getc()*Getc() - a()*a()) / 2;
            }
        }

        double Mb(){
            if(a() == 0 || Getc() == 0){
                return -1;
            } else {
                return sqrt(2 * a()*a() + 2 * Getc()*Getc() - b()*b()) / 2;
            }
        }

        double Mc(){
            if(a() == 0 || b() == 0){
                return -1;
            } else {
                return sqrt(2 * a()*a() + 2 * b()*b() - Getc()*Getc()) / 2;
            }
        }



        // BISSECTRICE:

        double Ba(){
            if(GetA() == 0){
                return -1;
            } else {
                return (2 * b() * Getc()) / (b() + Getc()) * cos(GetA() / 2);
            }
        }

        double Bb(){
            if(GetB() == 0){
                return -1;
            } else {
                return (2 * a() * Getc()) / (a() + Getc()) * cos(GetB() / 2);
            }
        }

        double Bc(){
            if(C() == 0 ){
                return -1;
            } else {
                return (2 * a() * b()) / (a() + b()) * cos(C() / 2);
            }
        }

};

Triangle2 CinFromConsole(){
    double A = 0; cout<<"Input A: "; cin>>A;
    double B = 0; cout<<"Input B: "; cin>>B;
    double c = 0; cout<<"Input c: "; cin>>c;

    return Triangle2(A, B, c);
}

void CoutToConsole(Triangle2 tmp){
    cout<<endl;

    cout<<"Your triangle:"<<endl<<endl;

    cout<<"Side a: "<<tmp.a()<<endl;
    cout<<"Side b: "<<tmp.b()<<endl;
    cout<<"Side c: "<<tmp.Getc()<<endl<<endl;

    cout<<"Perimeter: "<<tmp.P()<<endl;
    cout<<"Area: "<<tmp.S()<<endl<<endl;

    cout<<"Angle A: "<<tmp.GetA()<<endl;
    cout<<"Angle B: "<<tmp.GetB()<<endl;
    cout<<"Angle C: "<<tmp.C()<<endl<<endl;

    cout<<"Height a: "<<tmp.Ha()<<endl;
    cout<<"Height b: "<<tmp.Hb()<<endl;
    cout<<"Height c: "<<tmp.Hc()<<endl<<endl;

    cout<<"Median a: "<<tmp.Ma()<<endl;
    cout<<"Median b: "<<tmp.Mb()<<endl;
    cout<<"Median c: "<<tmp.Mc()<<endl<<endl;

    cout<<"Bissectrice a: "<<tmp.Ba()<<endl;
    cout<<"Bissectrice b: "<<tmp.Bb()<<endl;
    cout<<"Bissectrice c: "<<tmp.Bc()<<endl;
}


int main(int argc, char* argv[]){

    Triangle2 myTriangle = CinFromConsole();
    CoutToConsole(myTriangle);

    return 0;
}
