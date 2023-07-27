#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow{
    Display *d;
    Window *d;
    int s;
    GC gc;
    unsigned long colours[10];

    public:
    Xwindow(int width = 500, int height = 500);
    ~Xwindow();
    Xwindow(const Xwindow&) = delete;
    Xwindow &operator=(const Xwindow&) = delete;
    
    //colors 
    enum {White=0, Black, Red, Green, Blue};

    //draw a rectangle
    void fillRectangle(int x, int y, int width, int height, int colour=Black);

    //draw a string 
    void drawString(int x, int y, std::string msg);


};

#endif
