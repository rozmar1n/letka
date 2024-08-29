#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int facad[M][N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            facad[i][j] = 0;
        }
        
    }

    int nwin = 0;
    cin >> nwin;

    int minx = 0,
        maxx = 0,
        miny = 0,
        maxy = 0;
    
    int answer = 1;
    for (int iwin = 0; iwin < nwin; iwin++)
    {
        cin >> minx >> maxx >> miny >> maxy;
        for (int i = miny; i < maxy; i++)
        {
            for (int j = minx; j < maxx; j++)
            {
                if (facad[i][j] == 1 || i >= M || j >= N)
                {
                    answer = 0;
                }
                else
                {
                    facad[i][j] = 1;
                }
            }
        }
    }
if (answer)
{
    cout << "correct" <<endl;
}
else
{
    cout << "broken" <<endl;
}    
}