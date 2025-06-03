#include<stdio.h>

int main(){
long long int num1,num2,num3,largest;
scanf("%lld%lld%lld",&num1,&num2,&num3);

if(num1>=num2&&num1>=num3){
    largest=num1;
}
else if(num2>=num1&&num2>=num3){
    largest=num2;
}
else {
largest= num3;
}
printf("The largest is %lld",largest);
return 0;
}
