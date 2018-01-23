/*
 * File:   Polygon.h
 * Author: zhang823
 *
 * Created on November 26, 2014, 10:00 PM
 */

#ifndef POLYGON_H
#define	POLYGON_H

#include "Shape.h"
#include "easygl.h"

class Polygon : public Shape {
private:

   t_point relVertex[100];
   int num;

   // Private helper
   t_point getVecBetweenPoints (t_point start, t_point end) const;

public:
   Polygon (string _name, string _colour, float _xcen, float _ycen,
            t_point* vertices,int _num);


   virtual ~Polygon();


   virtual void print () const;
   virtual void scale (float scaleFac);
   virtual float computeArea () const;
   virtual float computePerimeter () const;
   virtual void draw (easygl* window) const;
   virtual bool pointInside (float x, float y) const;
};

#endif	/* POLYGON_H */

