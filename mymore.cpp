#include "mymore.h"
#include <iostream>
#include <cstdio>
using namespace std;
MyMore::MyMore():file(stdin)
{
}

MyMore::MyMore(FILE *file):file(file){
}
int MyMore::see_more(){
    int c;
    cout << "Please input: q/Enter/\" \": ";
    while(c=cin.get()){
        if(c=='q'){
            return 0;
        }
        if(c=='\n'){
            return 1;
        }
        if(c==' '){
            return PAGELEN ;
        }
    }
}

void MyMore::do_more(){
    char line[LINELEN] = {0};
    int number = 1;
    int number_of_lines = 0;
    int reply = 0;
    while(fgets(line,LINELEN,file)){
        if(number_of_lines == PAGELEN){
            reply = see_more();
            if(reply == 0){
                break;
            }
            number_of_lines = number_of_lines - reply;
        }
        cout << number << ": ";
        cout << line ;
        number_of_lines++;
        number++;
    }
}
