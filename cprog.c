#include <stdio.h> // 1
#include <stdlib.h> // 2
int add(int a,int b){return a+b;} // 3
int sub(int a,int b){return a-b;} // 4
int mul(int a,int b){return a*b;} // 5
int max(int a,int b){return a>b?a:b;} // 6
int min(int a,int b){return a<b?a:b;} // 7
void print_line(char c,int n){for(int i=0;i<n;i++)putchar(c);putchar('\n');} // 8
void banner(const char* t){print_line('=',40);printf("%s\n",t);print_line('=',40);} // 9
int fact(int n){int r=1;for(int i=1;i<=n;i++)r*=i;return r;} // 10
int fib(int n){if(n<=1)return n;int a=0,b=1,c;for(int i=2;i<=n;i++){c=a+b;a=b;b=c;}return b;} // 11
int is_even(int n){return n%2==0;} // 12
int clamp(int v,int lo,int hi){if(v<lo)return lo;if(v>hi)return hi;return v;} // 13
double avg(int a,int b){return (a+b)/2.0;} // 14
void swap(int* a,int* b){int t=*a;*a=*b;*b=t;} // 15
void fill(int* a,int n){for(int i=0;i<n;i++)a[i]=i;} // 16
int sum(int* a,int n){int s=0;for(int i=0;i<n;i++)s+=a[i];return s;} // 17
void reverse(int* a,int n){for(int i=0,j=n-1;i<j;i++,j--)swap(&a[i],&a[j]);} // 18
void print_arr(int* a,int n){for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");} // 19
int find(int* a,int n,int x){for(int i=0;i<n;i++)if(a[i]==x)return i;return -1;} // 20
int main(void){ // 21
    banner("C Demo Program"); // 22
    int x=6,y=4; // 23
    printf("add=%d\n",add(x,y)); // 24
    printf("sub=%d\n",sub(x,y)); // 25
    printf("mul=%d\n",mul(x,y)); // 26
    printf("max=%d min=%d\n",max(x,y),min(x,y)); // 27
    printf("avg=%.2f\n",avg(x,y)); // 28
    printf("fact(%d)=%d\n",x,fact(x)); // 29
    printf("fib(%d)=%d\n",x,fib(x)); // 30
    printf("%d is %s\n",x,is_even(x)?"even":"odd"); // 31
    int v=15; // 32
    printf("clamp=%d\n",clamp(v,0,10)); // 33
    int a[10]; // 34
    fill(a,10); // 35
    print_arr(a,10); // 36
    printf("sum=%d\n",sum(a,10)); // 37
    reverse(a,10); // 38
    print_arr(a,10); // 39
    int idx=find(a,10,5); // 40
    printf("find 5 at %d\n",idx); // 41
    int p=3,q=7; // 42
    printf("before swap p=%d q=%d\n",p,q); // 43
    swap(&p,&q); // 44
    printf("after swap p=%d q=%d\n",p,q); // 45
    for(int i=1;i<=5;i++)printf("i=%d square=%d\n",i,i*i); // 46
    int total=0; // 47
    for(int i=0;i<10;i++)total+=a[i]; // 48
    printf("total=%d\n",total); // 49
    char msg[]="Hello C"; // 50
    for(int i=0;msg[i];i++)putchar(msg[i]); // 51
    putchar('\n'); // 52
    FILE* f=fopen("example.txt","w"); // 53
    if(f){fprintf(f,"Sample file output\n");fclose(f);} // 54
    int r=rand()%100; // 55
    printf("rand=%d\n",r); // 56
    int count=0; // 57
    while(count<3){printf("count=%d\n",count);count++;} // 58
    do{count--;printf("down=%d\n",count);}while(count>0); // 59
    int m[3][3]; // 60
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)m[i][j]=i+j; // 61
    for(int i=0;i<3;i++){for(int j=0;j<3;j++)printf("%d ",m[i][j]);printf("\n");} // 62
    int ok=1; // 63
    if(ok)printf("ok\n");else printf("fail\n"); // 64
    int z=0; // 65
    switch(z){case 0:puts("zero");break;default:puts("other");} // 66
    double d=3.14; // 67
    printf("d=%.2f\n",d); // 68
    long long ll=123456789LL; // 69
    printf("ll=%lld\n",ll); // 70
    unsigned u=42u; // 71
    printf("u=%u\n",u); // 72
    const char* s="done"; // 73
    puts(s); // 74
    int n=5; // 75
    for(int i=0;i<n;i++)for(int j=0;j<i;j++)putchar('*'); // 76
    putchar('\n'); // 77
    int e=0; // 78
    e+=1; // 79
    e*=2; // 80
    e-=1; // 81
    printf("e=%d\n",e); // 82
    int t1=1,t2=2,t3=3; // 83
    printf("%d %d %d\n",t1,t2,t3); // 84
    t1=max(t1,t2); // 85
    t2=min(t2,t3); // 86
    printf("%d %d\n",t1,t2); // 87
    char c='A'; // 88
    printf("%c\n",c); // 89
    for(char ch='a';ch<='c';ch++)printf("%c ",ch); // 90
    putchar('\n'); // 91
    int flags=0; // 92
    flags|=1; // 93
    flags<<=1; // 94
    printf("flags=%d\n",flags); // 95
    int *ptr=&x; // 96
    printf("ptr=%d\n",*ptr); // 97
    puts("end"); // 98
    return 0; // 99
} // 100
output:-

add=10
sub=2
mul=24
max=6 min=4
avg=5.00
fact(6)=720
fib(6)=8
6 is even
clamp=10
0 1 2 3 4 5 6 7 8 9 
sum=45
9 8 7 6 5 4 3 2 1 0 
find 5 at 4
before swap p=3 q=7
after swap p=7 q=3
i=1 square=1
i=2 square=4
i=3 square=9
i=4 square=16
i=5 square=25
total=45
Hello C
rand=83
count=0
count=1
count=2
down=2
down=1
down=0
0 1 2 
1 2 3 
2 3 4 
ok
zero
d=3.14
ll=123456789
u=42
done
**********
e=1
1 2 3
2 2
A
a b c 
flags=2
ptr=6
end


=== Code Execution Successful ===
