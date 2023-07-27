#include <X11/Xib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>

using namespace std;

Xwindow::Xwindow(int width, int height){
    
    d = XOpenDisplay(NULL);
    if (d == NULL){
        cerr << "Cannot open display" << endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = 

}


