#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    long long int a,    
                  b,
                  c,
                  maxim,
                  minim;
    cin >> a;
    cin >> b; 
    cin >> c;

    maxim = max(a, max(b,c));
    minim = min(a, min(b,c));

    cout << maxim - minim <<endl;
}
