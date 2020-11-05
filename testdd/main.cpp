#include <iostream>
#include <cstdio>
#include<vector>
#include<iterator>
using namespace std;
const int INF=1000005;
int s[INF],lt[INF],rt[INF],dp[INF];
int main()
{
    //freopen("in.txt","r",stdin);
    int i,n,m;
    vector<double> result;
    int count=0;
    cin>>m;
        while(cin >> n)
        {
            for (i=1;i<=n;i++)scanf("%d",&s[i]);
            dp[n+1]=dp[0]=-INF;
            lt[0]=rt[n+1]=-INF;
            for (i=1;i<=n;i++)//正向
            {
                dp[i] = max(dp[i-1]+s[i],s[i]);
            }
             for (i=1;i<=n;i++)
             {
                 lt[i] =max(dp[i],lt[i-1]);
    //             lt[i] = dp[i];
             }
            for (i=n;i>=1;i--)  //逆向
            {
                dp[i] = max(dp[i+1]+s[i],s[i]);
            }
             for (i=n;i>=1;i--)
             {
                 rt[i] = max(dp[i],rt[i+1]);
    //                rt[i] = dp[i];
             }
             int sum=-INF;//枚举
            for (i=1;i<=n;i++)
            {
                sum = max(sum,lt[i]+rt[i+1]);
            }
            if(sum<=0){
                result.push_back(0);
            }
            else{
                result.push_back(sum);
            }
            count=count+1;
    //        cout <<'0' <<endl;
    //        else printf("%d\n",sum);
        }
    vector<double>::iterator iter;
    for (iter = result.begin(); iter != result.end(); ++iter) {
        cout<<*iter<<endl;
    }
    return 0;
}
