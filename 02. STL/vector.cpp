#include<iostream>
#include<vector>
using namespace std;

struct Car{
    string brand;
    double price;
};

void printVector(vector <Car> v){
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i].brand << ' ' << v[i].price << endl;
    }
    cout << endl;
}

int main()
{
    vector < Car > v;
    Car car1 = {"Ford", 55155.5};
    Car car2 = {"Ferrari", 500000};
    v.push_back(car1);
    v.push_back(car2);
    printVector(v);
    return 0;
}
