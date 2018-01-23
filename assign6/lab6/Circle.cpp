#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Circle.h"
using namespace std;


//  she ding base class (Shape), then chu chun
// 4 (x,y) points
Circle::Circle (string _name, string _colour, float _xcen, float _ycen, float _radius)
: Shape (_name, _colour, _xcen, _ycen) {
    radius=_radius;
}


Circle::~Circle () {
   // No dynamic memory to delete
}


void Circle::print () const {
   Shape::print();
   cout << "circle radius: "<< radius;
   cout << endl;
}


void Circle::scale (float scaleFac) {
      radius *= scaleFac;
}

float Circle::computeArea () const {
   //  width * height
   float area;
   area = PI*radius*radius;
   return area;
}

float Circle::computePerimeter () const {
   float perimeter = 0;

   perimeter = 2*PI*radius;
   return perimeter;
}

void Circle::draw (easygl* window) const {
   // Load up the data structure needed by easygl

   window->gl_setcolor(getColour());
   window->gl_fillarc(getXcen(),getYcen(),radius, 0, 360);

}


bool Circle::pointInside (float x, float y) const {
   // Make a point that corresponds to where you clicked. Since all my
   // vertices are relative to the  center,
   //click point so it is an offset from the
   // center.
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();

   return ((click.x*click.x+click.y*click.y)<radius*radius);
}

