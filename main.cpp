#include <iostream>
#include <vector>

using namespace std;


template <class tmp>
class myVector{
    private:
        vector<tmp> myvector;
        unsigned int Dimension;

    public:
        // CONSTRUCTOR:
        myVector(unsigned int Dimension = 0){
            if(Dimension == 0) Dimension++;
        }

        // GETTERS:

        vector<tmp> GetVector(){return myvector;}

        tmp GetElement(unsigned int i){return myvector[i];}

        unsigned int GetDimension(){return Dimension;}

        tmp GetElement2(unsigned int i){
            cout<<i<<" r  "<<myvector[i]<<endl;
            return myvector[i];
        }

        // SETTERS:

        void SetD(unsigned int Dimension){
            this.Dimension = Dimension;
            }

        void SetElement(tmp element){
            myvector.push_back(element);
        }

        void SetElement2(unsigned int i, tmp element){
            myvector[i] = element;
            cout<<i<<"   "<<element<<endl;
        }
};

// VECTOR FUNCTIONS:

template <class tmp>
myVector<tmp> Dimension(){
    unsigned int dimension = 0;
    cout<<"Set dimension of your vector: ";
    cin>>dimension;
    return myVector<tmp>(dimension);
}

template <class tmp>
myVector<tmp> CinElements(myVector<tmp> myvector){
    for(unsigned int i = 0; i < myvector.GetDimension(); ++i){
        try{
            if(i == myvector.GetDimension()){
                throw(invalid_argument("Опаньки!"));
            }
            tmp element = 0;
            cout<<"urvector["<<i<<"] = "; cin>>element;
            myvector.SetElement(element);
        }
        catch(invalid_argument myexception){
            cout<<myexception.what();
            throw;
        }
    }
    return myvector;
}

template <class tmp>
void CoutElements(myVector<tmp> myvector){
    for(unsigned int i = 0; i < myvector.GetDimension(); ++i){
        cout<<myvector.GetVector()[i]<<" ";
    }
    cout<<endl;
}


int main(int argc, char* argv[]){
    myVector v1 = Dimension<int>();

    CinElements<int>(v1);
    CoutElements<int>(v1);

    return 0;
}
