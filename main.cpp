#include <iostream>
#include <cmath>

using namespace std;


class Triangle1{
    private:

    // SIDES & ANGLE:

    double a;
    double b;
    double C;

    public:
        // THE CONSTRUCTOR:

        Triangle1(double a = 0, double b = 0, double C = 0){
            if(C >= M_PI){
                this->a = 0;
                this->b = 0;
                this->C = 0;
            } else {
                this->a = fabs(a);
                this->b = fabs(b);
                this->C = fabs(C);
            }
        }

        // GETTERS:

        double Geta(){return a;}
        double Getb(){return b;}
        double GetC(){return C;}

        // THE LEFT SIDE:

        double c(){
            if(C == 0 || Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return sqrt( Geta()*Geta() + Getb()*Getb() - (2 * Geta() * Getb()) * cos(GetC()) );
            }
        }

        // THE LEFT ANGLES:

        double A(){
            if(Getb() == 0 || c() == 0){
                return -1;
            } else {
                return acos( (Getb()*Getb() + c()*c() - Geta()*Geta()) / (2 * Getb() * c()) );
            }
        }

        double B(){
            if(Geta() == 0 || c() == 0){
                return -1;
            } else {
                return acos( (Geta()*Geta() + c()*c() - Getb()*Getb()) / (2 * Geta() * c()) );
            }
        }


        // PERIMETRE & AREA:

        double P(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return Geta() + Getb() + c();
            }
        }

        double S(){
            double p = P() / 2;
            if (p == 0){
                return -1;
            } else {
                return sqrt( p * ( p - Geta() ) * ( p - Getb() ) * ( p - c() ));
            }
        }

        // HEIGHTS:

        double Ha(){
            if(Geta() == 0){
                return -1;
            } else {
                return 2 * S() / Geta();
            }
        }

        double Hb(){
            if(Getb() == 0){
                return -1;
            } else {
                return 2 * S() / Getb();
            }
        }

        double Hc(){
            if(c() == 0){
                return -1;
            } else {
                return 2 * S() / c();
            }
        }

        // MEDIANS:

        double Ma(){
            if(Getb() == 0 || c() == 0){
                return -1;
            } else {
                return sqrt(2 * Getb()*Getb() + 2 * c()*c() - Geta()*Geta()) / 2;
            }
        }

        double Mb(){
            if(Geta() == 0 || c() == 0){
                return -1;
            } else {
                return sqrt(2 * Geta()*Geta() + 2 * c()*c() - Getb()*Getb()) / 2;
            }
        }

        double Mc(){
            if(Geta() == 0 || Getb() == 0){
                return -1;
            } else {
                return sqrt(2 * Geta()*Geta() + 2 * Getb()*Getb() - c()*c()) / 2;
            }
        }

        // BISSECTRICE:

        double Ba(){
            if(c() == 0){
                return -1;
            } else {
                return (2 * Getb() * c()) / (Getb() + c()) * cos(A() / 2);
            }
        }

            double Bb(){
            if(c() == 0){
                return -1;
            } else {
                return (2 * Geta() * c()) / (Geta() + c()) * cos(B() / 2);
            }
        }

            double Bc(){
            if(Geta() == 0 || Getb() == 0){
                return -1;
            } else {
                return (2 * Geta() * Getb()) / (Geta() + Getb()) * cos(C / 2);
            }
        }
};


Triangle1 CinFromConsole(){
    double a = 0; cout<<"Input a: "; cin>>a;
    double b = 0; cout<<"Input b: "; cin>>b;
    double C = 0; cout<<"Input C: "; cin>>C;
    return Triangle1(a, b, C);
}

void CoutToConsole(Triangle1 tmp){
    cout<<endl;

    cout<<"Your triangle:"<<endl<<endl;

    cout<<"Side a: "<<tmp.Geta()<<endl;
    cout<<"Side b: "<<tmp.Getb()<<endl;
    cout<<"Side c: "<<tmp.c()<<endl<<endl;

    cout<<"Perimeter: "<<tmp.P()<<endl;
    cout<<"Area: "<<tmp.S()<<endl<<endl;

    cout<<"Angle A: "<<tmp.A()<<endl;
    cout<<"Angle B: "<<tmp.B()<<endl;
    cout<<"Angle C: "<<tmp.GetC()<<endl<<endl;

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

    Triangle1 myTriangle = CinFromConsole();
    CoutToConsole(myTriangle);

    return 0;
}
