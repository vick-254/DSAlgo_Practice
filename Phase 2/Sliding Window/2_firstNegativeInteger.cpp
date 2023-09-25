#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> ans;
    queue<long long> neg;

    long long i = 0;
    long long j = 0;

    while (j < N)
    {
        if (A[j] < 0)
            neg.push(A[j]);

        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            if (neg.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(neg.front());

            if (A[i] < 0)
                neg.pop();
            i++;
            j++;
        }
    }
    return ans;
}