#include <iostream>
#include <cmath>

using namespace std;


class Circle{
    private:
        double r;

    public:
        Circle(double r = 0){
            Setr(r);
        }

        double Getr(){return r;}

        void Setr(double r = 0){this->r = fabs(r);}

        double P(){
            return 2 * M_PI * Getr();
        }

        double S(){
            return 2 * M_PI * Getr()*Getr();
        }
};

Circle CinFromConsole(){
    double r; cout<<"Input r: "; cin>>r;
    return Circle(r);
}

void CoutToConsole(Circle mycircle){
    cout<<endl;

    cout<<"Radius of your circle: "<<mycircle.Getr()<<endl;
    cout<<"Perimeter of your circle: "<<mycircle.P()<<endl;
    cout<<"Area of your circle: "<<mycircle.S()<<endl;
}

Circle* ArrayofCircles(unsigned int size){
    Circle* arrayofcircles = {new Circle[size]};
    return arrayofcircles;
};

Circle* ArrayofCirclesFill(Circle* arrayofcircles, unsigned int size){
    for(int i = 0; i < size; ++i){
        arrayofcircles[i] = CinFromConsole();
        system("cls");
    }
    return arrayofcircles;
}

void AOCPrint(Circle* arrayofcircles, unsigned int size){
    for(int i = 0; i < size; ++i){
        CoutToConsole(arrayofcircles[i]);
    }
}


int main(int argc, char* argv[]){
    unsigned int size = 0;
    cout<<"Input size of your array: "; cin>>size;

    Circle* arrayofcircles = ArrayofCircles(size);

    arrayofcircles = ArrayofCirclesFill(arrayofcircles, size);
    AOCPrint(arrayofcircles, size);

    return 0;
}
