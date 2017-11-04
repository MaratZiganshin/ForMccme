#include <iostream>

using namespace std;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int min(int a, int b, int c)
{
    return min(a, min(b, c));
}

int main()
{
    int N;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    int* c = new int[N];
    int* dinam = new int[N];
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i] >> c[i];
    if (N == 1)
        cout << a[0];
    else if (N == 2)
    {
        cout << min(a[0] + a[1], b[0]);
    }  
    else
    {
        dinam[0] = a[0];
        dinam[1] = min(dinam[0] + a[1], b[0]);
        dinam[2] = min(dinam[0] + b[1], dinam[1] + a[2], c[0]);
        for (int i = 3; i < N; i++)
        {
            dinam[i] = min(dinam[i - 1] + a[i], dinam[i - 2] + b[i - 1], dinam[i - 3] + c[i - 2]);
        }
        cout << dinam[N - 1] << endl;
    }
    system("pause");
}