//
// Created by niubin on 18-3-28.
//


#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 50086;
int sum[N];
int a[N];
int n;
int ans = INT32_MAX;

void dfs(int cur, int k)
{
    ++ans;

    for(int i = 0; i < cur; i++)
    {
        printf("%d * ", a[i]);
    }
    printf("%d = %d\n", k, n);

    for(int i = 2; i < k; i++)
    {
        if( k % i == 0 )
        {
            a[cur] = i;
            dfs(cur+1, k / i);
        }
    }

}

int main()
{
    for(int i = 0; i <= N; i++) sum[i] = 1;
    cin>>n;
    dfs(0, n);
    //printf("%d * 1 = %d\n", n, n);

    printf("total = %d\n", ans);
    return 0;
}