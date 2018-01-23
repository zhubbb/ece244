#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Polygon.h"
#include "Rectangle.h"
using namespace std;


// Constructor. First set up base class (Shape), then store the
// vertices, which are 3 (x,y) points giving offsets from the Shape center
// to each Polygon vertex.
Polygon::Polygon (string _name, string _colour, float _xcen, float _ycen,t_point* vertices,int _num)
              : Shape (_name, _colour, _xcen, _ycen) {
    num=_num;

   for (int i = 0; i < num; i++) {
       relVertex[i]=vertices[i]; //for loop to assign value for array, it is not pointer.
   }
}


Polygon::~Polygon () {
   // No dynamic memory to delete
}


void Polygon::print () const {
   Shape::print();
   cout << "polygon";
   for (int i = 0; i < num; i++) {
      cout << " (" << getXcen() + relVertex[i].x << ","
              << getYcen() + relVertex[i].y << ")";
   }
   cout << endl;
}


void Polygon::scale (float scaleFac) {
   for (int i = 0; i < num; i++) {
      relVertex[i].x *= scaleFac; // for scale we need relative length
      relVertex[i].y *= scaleFac;
   }
}


float Polygon::computeArea () const {

   float area;
   int j,i;

   area = 0;//initialize
   j = num-1;
   //number of points assume to be 100
   for(i=0; i<num; i++){
       area = area +  (relVertex[j].x+relVertex[i].x) * (relVertex[j].y-relVertex[i].y);
       j = i;  //j is previous vertex to i
   }
   return area/2;
}


float Polygon::computePerimeter () const {
   float perimeter = 0;
   float length = 0;
   t_point vector;
   int j=num-1; //last point
   for (int i = 0; i <num; i++) {

      vector = getVecBetweenPoints (relVertex[i], relVertex[j]);
      length = sqrt (vector.x * vector.x + vector.y * vector.y);
      perimeter += length;
      j=i; //p previous to i.
   }
   return perimeter;
}


void Polygon::draw (easygl* window) const {
   // Load up the data structure needed by easygl, and draw the Polygon
   // using the easygl::draw_polygon call.
   t_point coords[num];

   for (int i = 0; i <num; i++) { // if we get 0 , means it is non-exist
      coords[i].x = getXcen() + relVertex[i].x;
      coords[i].y = getYcen() + relVertex[i].y;

   }
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, num);
}


bool Polygon::pointInside (float x, float y) const {

   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();

   // The test is that a horizontal line (ray) from x = -infinity to the click point


   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;

   for (int istart = 0; istart < num; istart++) {
      endIndex = (istart + 1) % num; // Next vertex after istart
      vecOfSide = getVecBetweenPoints (relVertex[istart], relVertex[endIndex]);
      yDistance = (click.y - relVertex[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; // Really infinity, but this is big enough
      }


      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = relVertex[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x )
             sidesToLeft++;
      }
   }

   return (sidesToLeft == 1);
}



t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}


