#include <iostream>
#include <string>
#include <fstream>

int length;
bool sum_sign;
const int NUM_SIZE=100;
int num_arr[NUM_SIZE]={0};
int sum_arr[NUM_SIZE]={0};
int sub_arr[NUM_SIZE]={0};
using namespace std;
string minus_spaces(string a){
    string answer="";
    for(int i=0;i<a.length();i++){
        while(a[i]==' ')
            i++;
        answer+=a[i];
    }
    //  cout<<answer<<'\n';
    return answer;
}
void input(string str) {
    for(int i=0;i<NUM_SIZE;i++){
        num_arr[i]=0;
    }
    for (int j = 0; j < str.length(); j++){
        num_arr[NUM_SIZE + j - str.length()] = str[j] - 48;
        //  cout<<num_arr[NUM_SIZE + j - str.length()];
    }
    for (int i=0;i<NUM_SIZE;i++){
        sub_arr[i]=sum_arr[i];
    }
    // cout<<'\n';
}

int number_length(){
    length=NUM_SIZE;
    for(int i=0;i<=NUM_SIZE-1;i++){
        if(num_arr[i]!=0)
            break;
        length--;
    }
    return length;
}

int sum_length(){
    length=NUM_SIZE;
    for(int i=0;i<=NUM_SIZE-1;i++){
        if(sum_arr[i]!=0)
            break;
        length--;
    }
    return length;
}

int compare_abs(){
    //1=sum>a
    //0=sum==a
    //-1=sum<a
    if(sum_length()>number_length())
        return 1;
    if(sum_length()<number_length())
        return -1;
    for(int i=0;i<NUM_SIZE;i++){
        if(sum_arr[i]>num_arr[i])
            return 1;
        if(sum_arr[i]<num_arr[i])
            return -1;
    }
    return 0;
}

void addition_abs(int num_arr[NUM_SIZE],int sum_arr[NUM_SIZE]){
    int transfer=0;
    for(int i=0;i<number_length();i++){
        sum_arr[NUM_SIZE-1-i]+=num_arr[NUM_SIZE-1-i];
        if(sum_arr[NUM_SIZE-1-i]>9){
            transfer=sum_arr[NUM_SIZE-1-i]/10;
            sum_arr[NUM_SIZE-1-i]=sum_arr[NUM_SIZE-1-i]%10;
            sum_arr[NUM_SIZE-i-2]+=transfer;
        }
    }
    for(int i=0;i<sum_length();i++){
    }
}

void subtraction_abs(int num_arr[NUM_SIZE],int sum_arr[NUM_SIZE]){
    int transfer=0;
    int minuend;
    for (int i=0;i<sum_length();i++){
        minuend =sum_arr[NUM_SIZE-1-i] - transfer - num_arr[NUM_SIZE-1-i];
        if (minuend<0) {
            minuend+=10;
            sum_arr[NUM_SIZE-1-i]=minuend % 10;
            transfer=1;
        }
        else {
            sum_arr[NUM_SIZE-1-i]= minuend % 10;
            transfer = 0;
        }
    }
    for(int i=0;i<sum_length();i++){
    }
}

void addition(){
    if(sum_sign){
        addition_abs(num_arr,sum_arr);
        // cout<<"asfd";
    }
    else{
        if(compare_abs()>=0){
            subtraction_abs(num_arr,sum_arr);
        }
        else{
            subtraction_abs(sub_arr,num_arr);
            for (int i=0;i<NUM_SIZE;i++){
                sum_arr[i]=num_arr[i];
            }
            sum_sign=true;
        }
    }


}

void subtraction(){
    if(compare_abs()>=0){
        if(sum_sign){
            subtraction_abs(num_arr,sum_arr);
            //  cout<<"wfd";
        }
        else{
            //  cout<<"fasd";
            addition_abs(num_arr,sum_arr);
        }
    }
    else{
        if(sum_sign){
            subtraction_abs(sub_arr,num_arr);
            for (int i=0;i<NUM_SIZE;i++){
                sum_arr[i]=num_arr[i];
                //cout<<sum_arr[i];
            }
            sum_sign=false;
        }
        else{
            addition_abs(num_arr,sum_arr);
        }
    }
}

void output_result(){
    if(sum_sign)
        cout<<"Result is: ";
    else
        cout<<"Result is: -";
    for(int i=0;i<sum_length();i++){
        cout<<sum_arr[NUM_SIZE+i-sum_length()];
    }
    //cout<<" "<<sum_length()<<'\n';
}

int main()
{
    int counter=0;
    //ofstream - vivod

    ifstream f;
    string a,b,res_a;
    string sign="";
    sum_sign=true;
    res_a="";
    f.open("D:\\C++\\1\\1 course 1 term(2019)\\Lab_6(long ar in files)\\hello.txt");
    //getline(f,a);
    //addition();
    //output_result();
    while(!f.eof()){
        getline(f,a);
        res_a+=minus_spaces(a);
    }
    cout<<"Expression is: ";
    for(int i=counter;i<res_a.length();i++){
        cout<<res_a[i];
    }
    cout<<'\n';
    for(counter=0;counter<res_a.length();counter++){
        if(res_a[counter]=='+'||res_a[counter]=='-'){
            // cout<<b<<'\n';
            input(b);
            addition();
            // output_result();
            sign=res_a[counter];
            counter++;
            break;
        }
        b+=res_a[counter];
    }
    //cout<<b<<'\n';
    b="";
    while(counter<res_a.length()){
        if(res_a[counter]=='+'||res_a[counter]=='-'||counter==res_a.length()-1){
            if(counter==res_a.length()-1)
                b+=res_a[counter];
            //cout<<'\n'<<sign<<'\n';
            // cout<<b;
            input(b);
            if(sign[0]=='+'){
                //   cout<<"ESEF";
                addition();
            }
            else{
                subtraction();
            }
            b="";
            sign=res_a[counter];
            //output_result();
        }
        else{
            b+=res_a[counter];
            // cout<<b<<'\n';
        }
        counter++;
    }

    f.close();
    output_result();
}