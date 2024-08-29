#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int lli;

int main()
{
    int N;
    cin >> N;
    
    vector<lli> neotr;
    vector<lli> otr;

    for (int i = 0; i < N; i++)
    {
        lli elem;
        cin >> elem;
        if (elem < 0)
        {
            otr.push_back(elem*(-1));            
        }
        else
        {
            neotr.push_back(elem);
        }
    }

    sort(neotr.begin(), neotr.end());
    sort(otr.begin(), otr.end());

    for (int j = 0; j < neotr.size(); j++)
    {
        cout << neotr[j] << " ";    
    }

    for (int k = 0; k < otr.size(); k++)
    {
        cout << otr[k]*(-1) <<" ";
    }
    return 0;
}