#include <iostream>
#include <vector>
#include <cmath>
typedef long long int lli;

using namespace std;

int recurent_sum(int a)
{
    int sum = 0;
    int temp = a;
    while(temp > 0)
    {
        sum += temp%10;
        temp /= 10;
    }
    if(sum > 9)
    {
        sum = recurent_sum(sum);
    }
    return sum;
}

int main()
{
    int number = 0;
    cin >> number;

    number = recurent_sum(number);
    cout << number <<endl;
}