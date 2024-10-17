#include <iostream>
#include <cmath>

using namespace std;



class RightTriangle{
    private:
        double a;
        double b;

    public:
        RightTriangle(double a = 0, double b = 0){
            Seta(a);
            Setb(b);
        }

        double Geta(){return a;}
        double Getb(){return b;}
        double Getc(){return sqrt(Geta() * Geta() + Getb() * Getb());}

        double GetC(){return M_PI / 2;}

        void Seta(double a = 0){this->a = fabs(a);}
        void Setb(double b = 0){this->b = fabs(b);}


        double P(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return Geta() + Getb() + Getc();
            }
        }

        double S(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return Geta() * Getb() / 2;
            }
        }


        double A(){
            if(Geta() == 0){
                return -1;
            } else {
                return atan(Getb() / Geta());
            }
        }

        double B(){
            if(Getb() == 0){
                return -1;
            } else {
                return atan(Geta() / Getb());
            }
        }


        double r(){
            if(Geta() == 0 || Getb() == 0){
                return 0;
            } else {
                return (Geta() + Getb() - Getc()) / 2;
            }
        }

        double R(){
            return Getc() / 2;
        }
};


RightTriangle CinFromConsole(){
    cout<<endl;
    double a = 0; cout<<"Input a: "; cin>>a;
    double b = 0; cout<<"Input b: "; cin>>b;
    cout<<endl;
    return RightTriangle(a, b);
}

void CoutToConsole(RightTriangle tmp){
    cout<<"\nHypotenuse: "<<tmp.Getc()<<endl;
    cout<<"Perimeter: "<<tmp.P()<<endl;
    cout<<"Area: "<<tmp.S()<<endl<<endl;
    cout<<"Angle A: "<<tmp.A()<<endl;
    cout<<"Angle B: "<<tmp.B()<<endl;
    cout<<"Angle C: "<<tmp.GetC()<<endl<<endl;
    cout<<"Circles: r = "<<tmp.r()<<" R = "<<tmp.R()<<endl;
}

RightTriangle* ArrayofRightTriangles(unsigned int size){
    RightTriangle* aorts = new RightTriangle[size];
    return aorts;
};

RightTriangle* AORTS_Fill(RightTriangle* aorts, unsigned int size){
    for(int i = 0; i < size; ++i){
        aorts[i] = CinFromConsole();
    }
    return aorts;
}

void AORTS_Print(RightTriangle* aorts, unsigned int size){
    for(int i = 0; i < size; ++i){
        CoutToConsole(aorts[i]);
    }
}

unsigned int BiggestS(RightTriangle* aorts, unsigned int size){
    unsigned int I = 0;
    for(int i = 1; i < size; ++i){
        if(aorts[I].S() < aorts[i].S()){
            I = i;
        }
    }
    return I;
}

unsigned int SmallestS(RightTriangle* aorts, unsigned int size){
    unsigned int I=0;
    for(int i = 1; i < size; ++i){
        if(aorts[I].S() > aorts[i].S()){
            I = i;
        }
    }
    return I;
}

void BiggestSPrint(RightTriangle* aorts, unsigned int size){
    cout<<"Biggest triangle:";
    CoutToConsole(aorts[BiggestS(aorts, size)]);
}

void SmallestSPrint(RightTriangle* aorts, unsigned int size){
    cout<<"Biggest triangle:";
    CoutToConsole(aorts[SmallestS(aorts, size)]);
}

RightTriangle* IncreasingSort(RightTriangle* aorts, unsigned int size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - 1; ++j){
            if(aorts[j].S() > aorts[j+1].S()){
                swap(aorts[j], aorts[j+1]);
            }
        }
    }
    return aorts;
}

int main(int argc, char* argv[]){

    unsigned int size = 0;
    cout<<"Input size of your AORTS: "; cin>>size;

    RightTriangle* aorts = ArrayofRightTriangles(size);
    aorts = AORTS_Fill(aorts, size);

    IncreasingSort(aorts, size);

    AORTS_Print(aorts, size);

    return 0;
}
