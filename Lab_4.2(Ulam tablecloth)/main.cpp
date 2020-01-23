#include <iostream>
#include <string>


using namespace std;

int a,m,n,i,j,d,k;

int table_size(int n){
    while(d<a){
        d=n*n;
        n+=2;
    }
    n-=2;
    return n;
}
int main()
{
    cin>> a;

    int *ar_ar = new int[a];
    for(i=0;i<a;i++){
        ar_ar[i]=i+1;
    }


    int d=1;
    n=1;
    n=table_size(n);

//    int** arr;
//    arr=new int*[n];
//    for (int i=0;i<n;i++)
//        arr[i]=new int[n];
//
//    arr[1][1]=2;

    int **ar_out = new int *[n];
    for (int i=0;i<n;i++)
          ar_out[i]=new int[n];
    m=1;
    k=1;
    j=(n-1)/2;
    i=(n-1)/2;

    for(int x=0;x<n;x++){

        for(int y=0;y<n;y++){
            ar_out[x][y]=0;
        }
    }
    ar_out[i][j]=1;
    cout<<ar_out[0][5]<<'\n';
    while(m<a){
        for(int k1=1;k1<=k;k1++){
            ar_out[i][j+k1]=ar_ar[m];
            m++;
            if(m>=a)
                break;
        }
        j+=k;

        if(m>=a)
            break;
        for(int k1=1;k1<=k;k1++){
            ar_out[i-k1][j]=ar_ar[m];
            m++;
            if(m>=a)
                break;
        }
        i-=k;
        k++;
        if(m>=a)
            break;
        for(int k1=1;k1<=k;k1++){
            ar_out[i][j-k1]=ar_ar[m];
            m++;
            if(m>=a)
                break;
        }
        j-=k;
        if(m>=a)
            break;
        for(int k1=1;k1<=k;k1++){
            ar_out[i+k1][j]=ar_ar[m];
            m++;
            if(m>=a)
                break;
        }
        i+=k;
        k++;
        if(m>=a)
            break;
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(ar_out[x][y]==0)
                cout<<"   ";
            else
            if(ar_out[x][y]<10)
                cout<<" "<< ar_out[x][y]<<" ";
            else
                cout<<ar_out[x][y]<<" ";
        }
        cout<<'\n';
    }
    delete[](ar_ar);
    delete[](ar_out);
    return 0;
}
