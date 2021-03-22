#include <stdio.h>

int main(){
    
    int n,pivot,tmp,i,j;
    int a[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    i=-1;//L.14　のインクリメントを前置にしていて，while文の一周目をi=0で始められるようにしているため-1にしている
    j=n-1;//L.16 のデクリメントを前置にしていて，同じくwhile文の一周目をi=n-1で始められるようにしているためnにしている
    pivot=a[n-1];
    
    for(;;){
        while(a[++i]<pivot)
            ;
        while(i<--j && a[j]>pivot)
            ;
        
        if(i>=j)break;
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    tmp=a[i];
    a[i]=a[n-1];
    a[n-1]=tmp;
    
    for(int h=0;h<i;h++)printf("%d ",a[h]);
    printf("[%d]",a[i]);
    for(int h=i+1;h<n-1;h++)printf(" %d",a[h]);
    printf(" %d\n",a[n-1]);
    
    
    /*
    ---------------------------------- 
1 partition(A, p, r)
2   x = A[r]
3   i = p-1
4   for j = p to r-1
4     if A[j] <= x
5       i = i+1
6       A[i] と A[j] を交換
7   A[i+1] と A[r] を交換
8   return i+1
--------------------------------------
    */
    /*
    int n,x,i,j,tmp;
    int a[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    x=a[n-1];
    i=-1;
    for(j=0;j<n-2;j++){
        if(a[j]<=x){
            i++;
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    a[i+1]=a[n-1];
    for(int h=0;h<i+1;h++)printf("%d ",a[0]);
    printf("[%d]",a[i+1]);
    for(int h=i+2;h<n-1;h++)printf(" %d",a[0]);
    printf(" %d\n",a[n-1]);
    
    */
    
    return 0;
}