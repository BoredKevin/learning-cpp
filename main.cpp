#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

int read(double a, double b)
{
    double c;
    c = a + b;
    return c;
}

int main()
{
    double a, b;
        fin>>a;
        fout<<"Goth Mommies = "<< a;
        fin>>b;
        fout<<"\nGoth Daddies = "<< b;
    fout<< "\nTotal number of Goths = " << read(a, b);
    return 0;
}
