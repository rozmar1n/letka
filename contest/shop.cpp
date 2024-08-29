#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<stdlib.h>

using namespace std;
typedef long long int lli;

int cmp( const void *p1, const void *p2 )
{
    int x = *( int * )p1;
    int y = *( int * )p2;

    return ( x > y ) - ( y > x );

}

int main()
{
    int N;
    cin >> N;

    int arr[N][2];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    qsort(arr, N, sizeof( int[2] ), cmp);


    lli money = 0;
    cin >> money;

    lli sum = 0, nbox = 0;
    for (int i = 0; sum < money; i++)
    {
        sum += arr[i][0];
        nbox++;
    }
    
    lli ncand = 0;

    for (int i = 0; i < nbox; i++)
    {
        ncand += arr[i][1];
    }
    cout << nbox <<" "<<ncand<<endl;
}