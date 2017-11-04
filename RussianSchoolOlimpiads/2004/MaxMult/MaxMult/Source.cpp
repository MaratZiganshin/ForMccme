#include <iostream>

using namespace std;

int main()
{
    int max1 = -30000, max2 = -30000, max3 = -30000, min1 = 30000, min2 = 30000, min3 = 30000;
    int N;
    cin >> N;
    bool allNeg = true;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a < min1 && a < min2 && a < min3)
        {
            min3 = min2;
            min2 = min1;
            min1 = a;
        }
        else if (a < min2 && a < min3)
        {
            min3 = min2;
            min2 = a;
        }
        else if (a < min3)
        {
            min3 = a;
        }
        if (a > max1 && a > max2 && a > max3)
        {
            max3 = max2;
            max2 = max1;
            max1 = a;
        }
        else if (a > max2 && a > max3)
        {
            max3 = max2;
            max2 = a;
        }
        else if (a > max3)
        {
            max3 = a;
        }
        if (a >= 0)
            allNeg = false;
    }
    if (allNeg)
        cout << max1 << " " << max2 << " " << max3 << " " << endl;
    else
    {
        if (max2* max3 > min1*min2)
            cout << max1 << " " << max2 << " " << max3 << " " << endl;
        else cout << max1 << " " << min1 << " " << min2 << " " << endl;
    }
    system("pause");
}