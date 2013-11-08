﻿/* Copyright 2013 Anna Zhbanova */

#include <Triangle.h>
#include <math.h>

const double PI = 3.1415926535;

Triangle::Triangle(PointXY a_, PointXY b_, PointXY c_): a(a_), b(b_), c(c_) {
}
Triangle::Triangle(): a(PointXY()), b(PointXY()), c(PointXY()) {
}
Triangle::~Triangle(void) {
}

float Triangle::AB() {
    return Length(a, b);
}
float Triangle::BC() {
    return Length(b, c);
}
float Triangle::AC() {
    return Length(a, c);
}

float Triangle::AngleA() {
    return Angle(b, a, c);
}
float Triangle::AngleB() {
    return Angle(a, b, c);
}
float Triangle::AngleC() {
    return Angle(a, c, b);
}

float Triangle::Square() {
    float s = -1;
    if ( IsCorrect() ) {
        float side1 = Length(a, b);
        float side2 = Length(a, c);
        float side3 = Length(b, c);

        float sinA = static_cast<float>(sqrt(1 - ((side1 * side1 + side2 * side2
           - side3 * side3)/(2 * side1 * side2))*((side1 * side1 + side2 * side2
           - side3 * side3)/(2 * side1 * side2))));
        s = side1 * side2 * sinA / 2;
    }
    return s;
}
float Triangle::Perimeter() {
    float p = -1;
    if ( IsCorrect() )
        p = AB() + AC() + BC();
    return p;
}

bool Triangle::IsCorrect() {
    if (AB() + AC() <= BC() || AB() + BC() <= AC() || BC() + AC() <= AB())
        return false;
    return true;
}
int Triangle::IsEquilateral() {
    if ( IsCorrect() ) {
        float eps = static_cast <float>(0.0001);
        if ((AB() - BC()) < eps || (AB() - AC()) < eps || (BC() - AC()) < eps)
            return 1;
    } else {
        return -1;
    }
    return 0;
}
int Triangle::IsIsosceles() {
    if ( IsCorrect() ) {
        float eps = static_cast <float>(0.0001);
        if ((AB() - BC()) < eps && (AB() - AC()) < eps)
            return 1;
    } else {
        return -1;
    }
    return 0;
}

PointXY Triangle::Get(char nameVertex) {
    PointXY coordinates;
    switch (nameVertex) {
    case 'a':
        coordinates = a;
        break;
    case 'b':
        coordinates = b;
        break;
    case 'c':
        coordinates = c;
        break;
    }
    return coordinates;
}

void Triangle::Set(char nameVertex, PointXY coordinates) {
    switch (nameVertex) {
    case 'a':
        a = coordinates;
        break;
    case 'b':
        b = coordinates;
        break;
    case 'c':
        c = coordinates;
        break;
    }
}

float Triangle::Length(PointXY point1, PointXY point2) {
    return static_cast <float>(sqrt ( (point1.x - point2.x) *
        (point1.x - point2.x) + (point1.y - point2.y) *
        (point1.y - point2.y) ));
}

float Triangle::Angle(PointXY endP1, PointXY vertexOfAngle, PointXY endP2) {
    float side1 = Length(endP1, vertexOfAngle);
    float side2 = Length(endP2, vertexOfAngle);
    float side3 = Length(endP1, endP2);

    return static_cast <float>(180 * acos((side1 * side1 + side2 * side2
                              - side3 * side3)/(2 * side1 * side2)) / PI);
}
