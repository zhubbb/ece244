#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Rectangle.h"
using namespace std;


//  she ding base class (Shape), then chu chun
// 4 (x,y) points
Rectangle::Rectangle (string _name, string _colour, float _xcen, float _ycen, float _width, float _height)
: Shape (_name, _colour, _xcen, _ycen) {
    width=_width;
    height=_height;
}


Rectangle::~Rectangle () {
   // No dynamic memory to delete
}


void Rectangle::print () const {
   Shape::print();
   cout << "rectangle width: "<< width << " height: "<< height;
   cout << endl;
}


void Rectangle::scale (float scaleFac) {
      width *= scaleFac;
      height *= scaleFac;
}

float Rectangle::computeArea () const {
   //  width * height
   float area;
   area = width*height;
   return area;
}

float Rectangle::computePerimeter () const {
   float perimeter = 0;

   perimeter = 2*(width+height);
   return perimeter;
}

void Rectangle::draw (easygl* window) const {
   // Load up the data structure needed by easygl

   window->gl_setcolor(getColour());
   window->gl_fillrect(getXcen()-width/2,getYcen()-height/2,getXcen()+width/2,getYcen()+height/2);

}


bool Rectangle::pointInside (float x, float y) const {
   // Make a point that corresponds to where you clicked. Since all my
   // vertices are relative to the  center,
   //click point so it is an offset from the
   // center.
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   return ((abs(click.x)<width/2)&&(abs(click.y)<height/2));
}


