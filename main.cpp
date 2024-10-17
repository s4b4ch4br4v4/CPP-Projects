#include <iostream>
#include <cmath>



using namespace std;

class KvGantoleba {
    private:
        double a;
        double b;
        double c;

    public:
        KvGantoleba(double a=1, double b=0, double c=0){
            this->a = a;
            this->b = b;
            this->c = c;
        }

        double GetA(){return a;}
        double GetB(){return b;}
        double GetC(){return c;}


        double D(){
            return b * b - 4 * a * c;
        }

        double Re(){
            if(a == 0){
                return -1;
            } else {
                return -b / (2 * a);
            }
        }

        double Im(){
            if(a == 0){
                return -1;
            } else {
                return sqrt(fabs(D()))/(2*a);
            }
        }
};

void DisplayRoots(KvGantoleba kvg){
            if(kvg.D() >= 0){
                cout<<"Fesvebi roca D >= 0:"<<endl;
                cout<<"X1 = "<<kvg.Re()-kvg.Im()<<endl;
                cout<<"X2 = "<<kvg.Re()+kvg.Im()<<endl;
            } else {
                cout<<"Fesvebi roca D < 0:"<<endl;
                cout<<"X1 = "<<kvg.Re()<<" - "<<kvg.Im()<<" * i"<<endl;
                cout<<"X1 = "<<kvg.Re()<<" + "<<kvg.Im()<<" * i"<<endl;
            }
        }



int main(int argc, char* argv[]){

    double a; cout<<"Sheiyvanet a: "; cin>>a;
    double b; cout<<"Sheiyvanet b: "; cin>>b;
    double c; cout<<"Sheiyvanet c: "; cin>>c;

    cout<<endl;

    DisplayRoots(KvGantoleba(a,b,c));

    return 0;
}
