#ifndef MYMORE_H
#define MYMORE_H
#include <iostream>
#include <fstream>
using namespace std;
class MyMore
{
    const static int PAGELEN = 24;
    const static int LINELEN = 512;
    FILE *file;
public:
    MyMore();
    MyMore(FILE *file);
    /*
     * responsible for the input
     *
     * */
    int see_more();
    /*
     * responsible for the output
     * */
    void do_more();
};

#endif // MYMORE_H
