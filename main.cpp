//
//  main.cpp
//  linkedList
//
//  Created by Mac on 10/3/14.
//  Copyright (c) 2014 Yiyuan. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>


using namespace std;

struct node{
    int i;
    node *next;
};
string visit(string s){                     //cut web link from getline
    string l = s.substr(6,s.length());
    //cout << l.length();
    return l;
}

int main() {
    stack <string> mystack;
    stack <string> mystack2;
    mystack.push("http://www.acm.org/");
    string s;
    while (1){
        getline(cin, s);
        if (s[0]=='V'){                 //push link l into stack1, empty stack2
            string l=visit(s);
            mystack.push(l);
            cout<<l<<endl;
            while (!mystack2.empty()){
                mystack2.pop();
            }
            
        }
        else if (s[0]=='B'){            //backward
            if(mystack.size()>1){
                mystack2.push(mystack.top());
                mystack.pop();
                cout<<mystack.top()<<endl;
            }
            else
                cout<<"Ignored"<<endl;
        }
        else if (s[0]=='F'){                    //forward
            if (mystack2.size()>0){
                mystack.push(mystack2.top());
                cout<<mystack2.top()<<endl;
                mystack2.pop();
            }
            else
                cout<<"Ignored"<<endl;
        }                                   //quit
        else if (s[0]=='Q'){
            break;
        }
    }
}
