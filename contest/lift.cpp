#include <iostream>
#include <vector>
#include <cmath>
typedef long long int lli;

using namespace std;


int main()
{
    lli N,
        M,
        K;

    double Ta,
           Tb,
           Tc;

    double lift,
           lest;

    cin >> N >> M >> K >> Ta >> Tb >> Tc;

    lift = 3*Tb + Ta*(abs(N-K) +abs(M-N));
    lest = Tc * (abs(N-M));

    if (lift > lest)
    {
        cout << "stairs" <<"\n";
    }
    else
    {
        cout << "elevator" <<endl;
    }
    



    
}