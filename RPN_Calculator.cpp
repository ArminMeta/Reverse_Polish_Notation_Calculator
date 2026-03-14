#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>

using namespace std;

void prekid(){abort();}

int prednost(char a){
    if(a=='*' || a=='/') return 2;
    if(a=='-' || a=='+') return 1;
    if(a=='(' || a=='[') return 0;
    return -1;
}
bool isOperator(char a){
    if(a=='+' || a=='-' || a=='*' || a=='/') return true;
    return false;
}

string izvrnuto(string &izraz){
    int n=izraz.length();
    stack<char> izvrnut;
    deque<char> operacije;
    string temp = "";
    if(!isdigit(izraz[0]) && izraz[0] != '(' && izraz[0] != '[' || 
        !isdigit(izraz[n-1]) && izraz[n-1] != ')' && izraz[n-1] != ']') {
            throw logic_error("Prvi i posljedni element izraza moraju biti broj ili zagrada");
    }

    for(int i=0;i<n;i++){
        char c=izraz[i];
        
        if(!isOperator(c) && c!='(' && c!=')' && c!='[' && c!=']' && !isdigit(c)){
            throw domain_error("Element koji ste unijeli u string nije dozvoljen");
        }
        if(isdigit(c)==true && isdigit(izraz[i+1])==true ){
            throw domain_error("Koristeci visecifrenih elemenata nije dozvonljeno");
        }
        

        if(isdigit(c)){
            izvrnut.push(c);
        }else if(isOperator(c)){
            while(!operacije.empty() && prednost(operacije.back()) >= prednost(c)){
                izvrnut.push(operacije.back());
                operacije.pop_back();
            }
            operacije.push_back(c);
        }else if(c == '(' || c == '['){
            operacije.push_back(c);
        }else if(c == ')' || c == ']'){
            while(!operacije.empty() && (operacije.back() != '(' && operacije.back() != '[')){
                izvrnut.push(operacije.back());
                operacije.pop_back();
            }
            operacije.pop_back();
        }
    }

    while(!operacije.empty()){
        izvrnut.push(operacije.back());
        operacije.pop_back();
    }
    while(!izvrnut.empty()){
        temp+=izvrnut.top();
        izvrnut.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

double racun(string &izraz){
    int n = izraz.length();
    stack<double> stek;
    
    for(int i=0;i<n;i++){
        char c=izraz[i];
        if(isdigit(c)){
            stek.push(c-'0');
        }else if(isOperator(c)){
            double op2 = stek.top();
            stek.pop();
            double op1 = stek.top();
            stek.pop();

            double rezultat;

            switch(c){
                case '+':
                    rezultat = op1 + op2;
                    break;
                case '-':
                    rezultat = op1 - op2;
                    break;
                case '*':
                    rezultat = op1 * op2;
                    break;
                case '/':
                    if(op2==0){
                        throw logic_error("Nema djeljenja sa nulom");
                    }
                    rezultat = op1 / op2;
                    break;
                default:
                    break;
            }
            stek.push(rezultat);
        }
    }
    return stek.top();
}

int main(){
    string izraz;
    cout << "Unesite vas izraz | ako zelite izac napisite EXIT" << endl;
    getline(cin, izraz);
    if(izraz=="EXIT")break;
    string RPN;
    double res;
    try{
        RPN = izvrnuto(izraz);
        res = racun(RPN);
    }
    catch(exception &e){ 
        cout << e.what();
        set_terminate(prekid);
        terminate();
    }
    cout << "Vrijednost izraza je: " << res << endl;
    
    return 0;
}