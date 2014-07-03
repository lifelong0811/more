#include "mymore.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
MyMore::MyMore():file(stdin)
{
}

MyMore::MyMore(FILE *file):file(file){
}
int MyMore::see_more(FILE* fp){
    int c;
    cout << "Please input: q/Enter/\" \": ";
    while(c=fgetc(fp)){
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
    /*
     * read form /dev/tty virtual equipment
     * */
    FILE *fp_tty = fopen("/dev/tty","r");
    if(fp_tty == NULL){
        exit(-1);
    }
    while(fgets(line,LINELEN,file)){
        if(number_of_lines == PAGELEN){
            reply = see_more(fp_tty);
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
