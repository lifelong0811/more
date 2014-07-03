#include <iostream>
#include "mymore.h"
#include <stdio.h>
using namespace std;



int main(int argc, char* argv[])
{
    FILE *fp;
    if(argc == 1){
        MyMore myMore;
        myMore.do_more();
    }
    else{
        while(--argc){
            fp = fopen(*++argv,"r");
            MyMore myMore(fp);
            myMore.do_more();
        }
    }
    return 0;
}

