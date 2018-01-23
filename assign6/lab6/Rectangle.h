/*
 * File:   rectangle.h
 * Author: zhang823
 *
 * Created on November 26, 2014, 8:10 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include "Shape.h"
#include "easygl.h"

class Rectangle : public Shape{
private:
    //t_point relVertex[4];
    float width,height;

public:
    Rectangle (string _name,string _colour, float _xcen, float _ycen, float _width, float _height);
    virtual ~Rectangle();
    virtual void print() const;
    virtual void scale(float scaleFac);
    virtual float computeArea () const;
    virtual float computePerimeter() const;
    virtual void draw(easygl* window) const;
    virtual bool pointInside(float x, float y) const;

};


#endif	/* RECTANGLE_H */





