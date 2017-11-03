#include <iostream>
#include <list>

using namespace std;

int main()
{
    int N;
    cin >> N;
    N--;
    string a;
    for (int i = 0; i < N; i++)
    {
        string k;
        cin >> k;
        a = a + k;
    }
    int i;
    for (i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            bool ok = true;
            for (int j = 1; j < N / i; j++)
            {
                
                string sub1 = a.substr(j * i, i);
                string sub2 = a.substr(0, i);
                if (sub1 != sub2)
                {
                    ok = false;
                    break;
                }
            }
            if (ok == true)
                break;
        }
    }
    cout << i;

    system("pause");
}