#include<stdio.h>
    int main()
    {
        int n,i,j;
        scanf("%d",&n);
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            b[i]=1;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    b[i]=b[i]*a[j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",b[i]);
        }
    }
