#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <stack>
using namespace std;
string minus_spaces(string a){
    string answer="";
    for(int i=0;i<a.length();i++){
        //cout<<answer<<'\n';
        if (a[i]!=' ')
            answer+=a[i];
    }

    return answer;
}
string extra_spaces(string a){
    string answer;
    for(int i=0;i<a.length();i++){
        while(a[i]==' '&&a[i+1]==' ' )
            i++;
        answer+=a[i];
    }
    //  cout<<answer<<'\n';
    return answer;
}
double power(double a){
    a=pow(2.71828182,a);
    return a;
}
int priority(string str){
    if(str[0]=='e')
        return 4;
    if(str[0]==')')
        return 3;
    if(str[0]=='(')
        return 2;
    if(str[0]=='/'||str[0]=='*')
        return 1;
    if(str[0]=='+'||str[0]=='-')
        return 0;
    return -1;
}

int main(){
    string str,str_in,str_spaces,sign,var, pol_str;
    string j="*";
    map<string,string> variables;
    string var_int;
    int k=1;
    cout<<"Please enter CORRECT expression\n";
    getline(cin,str_spaces);
    str_in=minus_spaces(str_spaces);
    string sign_p="";
    for(int i=0;i<str_in.size();i++){
        if(str_in[i]=='0'||str_in[i]=='1'||str_in[i]=='2'||str_in[i]=='3'||str_in[i]=='4'||str_in[i]=='5'||str_in[i]=='6'||str_in[i]=='7'||str_in[i]=='8'||str_in[i]=='9'){
            str+=str_in[i];
        }
        else{
            sign=str_in[i];
            sign_p=str_in[i+1];
            if(priority(sign)!=-1 && priority (sign)!=4){
                str+=sign;
            }
            else{
                if(priority(sign)==4&&priority(sign_p)==2){
                    str+=sign;
                }
                else {
                    //i++;
                    sign = str_in[i];
                    while (priority(sign) == -1 || priority(sign) == 4) {
                        if (i == str_in.size())
                            break;
                        var += sign;
                        i++;
                        //cout<<i<<'\n';
                        sign = str_in[i];
                    }
                    //cout<<var<<'\n';
                    if (variables.find(var) == variables.end() || variables.empty()) {
                        cout << "Enter variable " << var << '\n';
                        cin >> var_int;
                        if (var_int[0] == '-') {
                            //var_int+=')';
                            var_int = "(" + var_int + ")";
                        }
                        variables.insert({var, var_int});
                    }
                    str += variables[var];
                    var = "";
                    i--;
                }
            }
        }
    }
    cout<<"Our expression is\n"<<str<<'\n';
    stack<string> my_stack;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
            pol_str+=str[i];

        }
        else{
            pol_str+=' ';
            sign=str[i];
            if(my_stack.empty() && i!=0 ){
                my_stack.push(sign);

            }
            else{
                if(priority(sign)==4){
                    my_stack.push(sign);

                }
                else{
                    if(priority(sign)==2){
                        my_stack.push(sign);

                    }
                    else{
                        if(priority(sign)==3){
                            while(priority(my_stack.top())!=2){
                                //pol_str+=" ";
                                pol_str+=my_stack.top();
                                pol_str+=' ';
                                my_stack.pop();
                            }
                            my_stack.pop();
                            if(!my_stack.empty()) {
                                if (priority(my_stack.top()) == 4) {
                                    pol_str += my_stack.top();
                                    pol_str += ' ';
                                    my_stack.pop();
                                }
                            }
                        }
                        else{
                            if(sign[0]=='-'&&i==0){
                                my_stack.push(j);
                                pol_str+="-1 ";
                            }
                            else{
                                if((sign[0]=='-'&&str[i-1]=='(')){
                                    my_stack.push(j);
                                    pol_str+="-1 ";
                                }
                                else {
                                    if (priority(sign) > priority(my_stack.top())) {
                                        my_stack.push(sign);
                                    } else {
                                        if (priority(sign) == priority(my_stack.top())) {
                                            pol_str += my_stack.top();
                                            pol_str += ' ';
                                            my_stack.pop();
                                            my_stack.push(sign);

                                        } else {
                                            while (priority(sign) < priority(my_stack.top())) {

                                                if (priority(my_stack.top()) == 2)
                                                    break;
                                                if (priority(my_stack.top()) == 4)
                                                    break;
                                                pol_str += my_stack.top();
                                                pol_str += ' ';
                                                my_stack.pop();
                                                if (my_stack.empty())
                                                    break;
                                            }
                                            my_stack.push(sign);

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
//        if(!my_stack.empty())
//            cout<<my_stack.top()<<'\n';
//        cout<<pol_str<<'\n';
    }
    pol_str+=' ';
    while(!my_stack.empty()){
        pol_str+=my_stack.top();
        pol_str+=' ';
        my_stack.pop();
    }
    cout<<"Our expression in polish notation is\n"<<pol_str<<'\n';
    stack <double> number;
    string num="";
    pol_str=extra_spaces(pol_str);
    int num_int=1;
    double op_1=0;
    double op_2=0;
    //string sign_b=pol_str[0];
    string sign_plus="";
    string sign_min="";
    for(int i=0; i<pol_str.size();i++) {
        sign = pol_str[i];
        sign_min=pol_str[i-1];
        sign_plus=pol_str[i+1];
        if (priority(sign)==-1 && sign!=" ") {
            num += sign;

        }
        else{
            if(sign=="-"&&sign_plus!=" "){
                num_int=-1;
            }
            else{
                if(sign==" "&&priority(sign_min)==-1&&i!=0){
                    num_int=num_int*stoi(num);

                    number.push(num_int);
                    num_int=1;
                    num="";

                }
                else {
                    if (priority(sign) == 4) {

                        op_1 = power(number.top());
                        number.pop();
                        number.push(op_1);
                        op_1 = 0;

                    } else {
                        if (sign == "+") {
                            op_1 += number.top();
                            number.pop();
                            op_1 += number.top();
                            number.pop();
                            number.push(op_1);
                            op_1 = 0;

                        } else {
                            if (sign == "-") {
                                op_1 += number.top();
                                number.pop();
                                op_2 += number.top();
                                number.pop();
                                op_2 -= op_1;
                                number.push(op_2);
                                op_1 = 0;
                                op_2 = 0;

                            } else {
                                if (sign == "/") {
                                    op_1 += number.top();
                                    number.pop();
                                    op_2 += number.top();
                                    number.pop();
                                    op_2 = op_2 / op_1;
                                    number.push(op_2);
                                    op_1 = 0;
                                    op_2 = 0;

                                } else {
                                    if (sign == "*") {
                                        op_1 += number.top();
                                        number.pop();
                                        op_2 += number.top();
                                        number.pop();
                                        op_2 = op_2 * op_1;
                                        number.push(op_2);
                                        op_1 = 0;
                                        op_2 = 0;

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"Value of our expression is\n"<<number.top()<<"\n";

    return 0;
}
