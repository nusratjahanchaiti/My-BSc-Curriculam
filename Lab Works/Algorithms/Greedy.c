#include <stdio.h>

int minCoinsCalculation(int coins[],int numCoins,int target) {
int count=0;

for(int i=0; i<numCoins;i++) {
 if(target == 0) {
 break;
}

count += target / coins[i];
target %= coins[i];
}

return count;
}

int main(){
int coins[]={25,10,5,2};
int numCoins=sizeof(coins)/sizeof(coins[0]);
int target=63;
int result= minCoinsCalculation(coins,numCoins,target);
printf("Minimum number of coins needed to Target: %d\n", result);
return 0;

}
