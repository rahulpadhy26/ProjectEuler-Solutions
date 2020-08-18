#include <bits/stdc++.h>
using namespace std;

long reverse_number(long n)
{
    long res = 0;
    while(n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    long n, i, j, cnt, k;
    unordered_map<long, int> ump; 
    cin >> n;
    for(i = 1; i <= n; i ++)
    {
        cnt = 1;
        k = i;
        while(cnt <= 60)
        {
            j = reverse_number(k);
            if(j == k)
            {
                if(ump[k])
                    ump[k] += 1;
                else
                    ump[k] = 1;
                break;
            }
            k += j;
            cnt ++;
        }
    }
    cnt = -1;
    for(auto it = ump.begin(); it != ump.end(); it ++)
    {
        if(it->second >= cnt)
        {
            cnt = it->second;
            i = it->first;
        }
    }
    cout << i << ' ' << cnt;
}
