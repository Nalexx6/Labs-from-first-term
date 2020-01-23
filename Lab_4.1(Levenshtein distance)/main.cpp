#include <iostream>
#include <string>


using namespace std;
string s1,s2;
int main()
{
    cout<<"Please enter first line"<<'\n';
    cin>>s1;
    cout<<"Please enter second line"<<'\n';
    cin>>s2;

    int a=(s1.length()+1);
    int b=(s2.length()+1);
    int **ar_table = new int *[a];
    for (int i=0;i<a;i++)
        ar_table[i]=new int[b];

    for(int x=0;x<a;x++){
        for(int y=0;y<b;y++){
            ar_table[x][y]=0;
        }
    }
    int i,j,d1,d2,d3;
    int sub;
    for(i=1;i<a;i++){
        ar_table[i][0]=i;
    }
    for(j=1;j<b;j++){
        ar_table[0][j]=j;
    }
    for(i=1;i<a;i++){
        // cout<<"fsd"<<'\n';
        for(j=1;j<b;j++){
            // cout<<"zxc"<<'\n';
            if(s1[i-1]==s2[j-1])
                sub=0;
            else{
                sub=1;
            }
            d1=ar_table[i-1][j]+1;
            d2=ar_table[i][j-1]+1;
            d3=ar_table[i-1][j-1]+sub;
            ar_table[i][j]=min(d1,min(d2,d3));
            //  cout<<ar_table[i][j]<<'\n';
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<ar_table[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"Levenshtein distance="<<ar_table[a-1][b-1];
    delete[](ar_table);
}