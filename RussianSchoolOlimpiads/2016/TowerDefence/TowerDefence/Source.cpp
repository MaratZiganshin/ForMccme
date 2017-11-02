#include <iostream>
#include <map>

using namespace std;

long long max(long long a, long long b)
{
    if (a > b) return a;
    return b;
}
long long min(long long a, long long b)
{
    if (a < b) return a;
    return b;
}
int main()
{
    long long n, s;
    cin >> n >> s;
    long long* a = new long long[n];
    long long* k = new long long[n];
    long long* x = new long long[n];
    map<long long, long long> pairs;
    
    long long sAttack = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i] >> k[i];
        x[i] = 0;
        sAttack += a[i];
        if (pairs.count(-k[i]) == 0)
        {
            pairs[-k[i]] = a[i] / k[i];
        }
        else pairs[-k[i]] += a[i] / k[i];
        if (pairs.count(-(a[i] % k[i])) == 0)
        {
            pairs[-(a[i] % k[i])] = 1;
        }
        else pairs[-(a[i] % k[i])] += 1;
    }
    long long defended = 0;
    for (pair<long long, long long> p : pairs)
    {
        if (s - p.second >= 0)
        {
            s -= p.second;
            defended -= p.first * p.second;
        }
        else
        {
            defended -= p.first * s;
            break;
        }
    }
    cout << max(sAttack - defended, 0);

   // system("pause");

}