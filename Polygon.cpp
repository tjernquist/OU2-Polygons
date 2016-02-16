#include <array>
#include <cmath>

#include "Vertex.h"
#include "Polygon.h"

using namespace std;

void Polygon::add(Vertex v) {

    arraySize++;
    Vertex * tempVertexes = new Vertex[arraySize];
    for (int i = 0; i < arraySize; i++) {
        if (i == arraySize - 1) {
            tempVertexes[i] = v;
        } else {
            tempVertexes[i] = vertices[i];
        }
    }
    delete [] vertices;
    vertices = tempVertexes;

}

Polygon::Polygon(Vertex vertexArray[], int size) {

    arraySize = size;
    vertices = new Vertex[size];

    for (int i = 0; i < size; i++) {
        vertices[i] = vertexArray[i];
    }
}

float Polygon::area() {

    float area = 0.0f;

    for (int i = 0; i < arraySize - 1; ++i) {
        area += (vertices[i].getXposition() * vertices[i + 1].getYposition()) - (vertices[i + 1].getXposition() * vertices[i].getYposition());
    }

    area += (vertices[0].getYposition() * vertices[arraySize - 1].getXposition()) - (vertices[arraySize - 1].getYposition() * vertices[0].getXposition());

    area = abs(area) *0.5;

    return area;
}

int Polygon::miny() {

    int yHolder = vertices[0].getYposition();

    for (int i = 0; i < arraySize; i++) {

        if (vertices[i].getYposition() < yHolder)
            yHolder = vertices[i].getYposition();
    }
    return yHolder;
}

int Polygon::maxy() {

    int yHolder = vertices[0].getYposition();

    for (int i = 0; i < arraySize; i++) {

        if (vertices[i].getYposition() > yHolder)
            yHolder = vertices[i].getYposition();
    }
    return yHolder;
}

int Polygon::minx() {

    int xHolder = vertices[0].getXposition();

    for (int i = 0; i < arraySize; i++) {

        if (vertices[i].getXposition() < xHolder)
            xHolder = vertices[i].getXposition();
    }

    return xHolder;
}

int Polygon::maxx() {

    int xHolder = vertices[0].getXposition();

    for (int i = 0; i < arraySize; i++) {


        if (vertices[i].getXposition() > xHolder)
            xHolder = vertices[i].getXposition();
    }

    return xHolder;
}

ostream& operator<<(ostream &output, const Polygon& polygon) { //Kolla denna!

    output << "{";
    for (int i = 0; i < polygon.numVertices(); i++) {
        output << "(" << polygon.vertices[i].getXposition() << "," << polygon.vertices[i].getYposition() << ")";
    }
    output << "}";

    return output;

}

bool operator<(Polygon polygon1, Polygon polygon2) {
    if (polygon1.area() < polygon2.area()) {
        return true;
    } else {
        return false;
    }
}

const Polygon & Polygon::operator=(const Polygon & arr) {

    if (this != &arr) {
        arraySize = arr.arraySize;
        delete[] vertices;

        vertices = new Vertex[arraySize];

        for (int i = 0; i < arraySize; i++)
            vertices[i] = arr.vertices[i];
    }
    return *this;
}

Polygon::Polygon(const Polygon & a) : arraySize(a.arraySize) {

    if (arraySize > 0) {
        vertices = new Vertex[arraySize];

        for (int i = 0; i < arraySize; i++)
            vertices[i] = a.vertices[i];
    } else
        vertices = 0;
}