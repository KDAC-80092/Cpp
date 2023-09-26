#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
using namespace std;

class Cylinder
{
private:
    float radius;
    float height;

public:
    Cylinder();
    Cylinder(double, double);
    void setRadius(double radius);
    void setHeight(double height);
    double getRadius();
    double getHeight();
    void printVolume();
};

#endif