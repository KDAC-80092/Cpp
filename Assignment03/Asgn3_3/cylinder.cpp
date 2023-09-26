#include "./cylinder.h"
#include<iostream>
using namespace std;


    Cylinder::Cylinder() : radius(1), height(1) {}

    Cylinder::Cylinder(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }

    void Cylinder::setRadius(double radius)
    {
        this->radius = radius;
    }

    void Cylinder::setHeight(double height)
    {
        this->height = height;
    }

    double Cylinder::getRadius()
    {
        return this->radius;
    }

    double Cylinder::getHeight()
    {
        return this->height;
    }

    void Cylinder::printVolume()
    {
        cout << "Volume of Cylinder is:" << 3.14 * radius * radius * height << endl;
    }