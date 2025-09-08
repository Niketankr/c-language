// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int original=n;
    int sum=0;
    while(n>0){
        int p=n%10;
        sum+=p*p*p;
        n/=10;
    }
if(original==sum){
    printf("%d is a armstrong.",original);
}
else{
    printf("%d is not a armstrong.",original);
}
    return 0;
}
