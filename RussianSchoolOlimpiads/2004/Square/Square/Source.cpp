#include <iostream>

using namespace std;

int main()
{
    int N, K, S;
    cin >> N >> K >> S;
    int** a = new int*[K];
    for (int i = 0; i < K; i++)
        a[i] = new int[K];

    int v = 1;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (S <= 0) v = 0;
            a[i][j] = v;
            S--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i%K][j%K] << " ";
        cout << endl;
    }

    system("pause");
}