#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int p[]= {0,4,3,6,5};
int wt[]= {0,3,2,4,5};
int n=4,m=5;
int dp[5][6]={0};

for(int i = 1; i<=n;i++){
  for(int w=0;w<=m;w++){
    if(wt[i]<=w){
        dp[i][w]= max(p[i]+dp[i-1][w-wt[i]],dp[i-1][w]);
    }
    else{
        dp[i][w]=dp[i-1][w];
    }
  }
}
cout<<"Item   = 1,2,3,4";
cout<<"\nProfit = 4,3,6,5";
cout<<"\nWeight = 3,2,4,5\n";
cout << "\n0/1 Knapsack Table:\n"<< endl;

for(int i= 0;i<=n;i++){
    for(int w=0;w<=m;w++){
        cout<< dp[i][w]<<" ";
    }
    cout<<endl;
}
   cout<<"\nMaximum Profit = "<< dp[n][m]<<endl;
   return 0;
}
