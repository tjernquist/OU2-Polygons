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


