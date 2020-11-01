#include <queue>
#include <vector>
#include <iostream>
#include "Canvas.h"
#include "BmpIO.h"
using namespace Graphics;


Canvas::Canvas(const Canvas& c) :width(c.width),height(c.height),bgColor(c.bgColor),allShapes(c.allShapes),pixels(c.pixels){}

Canvas& Canvas::operator=(const Canvas& c) {
    width = c.width;
    bgColor = c.bgColor;
    allShapes = c.allShapes;
    pixels = c.pixels;
    return *this;
}

void Canvas::RemoveAllShapes() {
    for (auto x : allShapes)delete x;
    allShapes.clear();
}

void Canvas::FloodFill(int x,int y,Color FillColor)
{
    queue<Point>q;
    q.push(Point(x, y));
    int index = (x + y * width);
    pixels[index + 0] = FillColor.r;
    pixels[index + 1] = FillColor.g;
    pixels[index + 2] = FillColor.b;
    while (!q.empty())
    {
        Point temp = q.front();
        q.pop();
        //cout << temp.x << "  " << temp.y << " "<<pixels[temp.x+temp.y*width+1]<<endl;
        int x1 = temp.x + 1, y1 = temp.y ;
        int x2 = temp.x - 1, y2 = temp.y;
        int x3 = temp.x, y3 = temp.y + 1;
        int x4 = temp.x, y4 = temp.y - 1;
        int index1 = (x1 + y1 * width) * 3;
        int index2 = (x2 + y2 * width) * 3;
        int index3 = (x3 + y3 * width) * 3;
        int index4 = (x4 + y4 * width) * 3;
        
        if (pixels[index1 + 0] == Color::white.r && pixels[index1 + 1] == Color::white.g && pixels[index1 + 2] == Color::white.b)
        {
            pixels[index1 + 0] = FillColor.r;
            pixels[index1 + 1] = FillColor.g;
            pixels[index1 + 2] = FillColor.b;
            q.push(Point(x1,y1));
        }
        if (pixels[index2 + 0] == Color::white.r && pixels[index2 + 1] == Color::white.g && pixels[index2 + 2] == Color::white.b)
        {
            pixels[index2 + 0] = FillColor.r;
            pixels[index2 + 1] = FillColor.g;
            pixels[index2 + 2] = FillColor.b;
            q.push(Point(x2, y2));
        }
        if (pixels[index3 + 0] == Color::white.r && pixels[index3 + 1] == Color::white.g && pixels[index3 + 2] == Color::white.b)
        {
            pixels[index3 + 0] = FillColor.r;
            pixels[index3 + 1] = FillColor.g;
            pixels[index3 + 2] = FillColor.b;
            q.push(Point(x3, y3));
        }
        if (pixels[index4 + 0] == Color::white.r && pixels[index4 + 1] == Color::white.g && pixels[index4 + 2] == Color::white.b)
        {
            pixels[index4 + 0] = FillColor.r;
            pixels[index4 + 1] = FillColor.g;
            pixels[index4 + 2] = FillColor.b;
            q.push(Point(x4, y4));
        }
     }
}

void Canvas::ConvertToBitmap() {
     if (nullptr != pixels) delete[]pixels;
     pixels = nullptr;
     int numPixels = width * height;
     if (numPixels < 1) return;
     pixels = new unsigned char[numPixels*3];
     for (int j = 0; j < numPixels; j++) {
         pixels[3*j + 0] = bgColor.r;
         pixels[3*j + 1] = bgColor.g;
         pixels[3*j + 2] = bgColor.b;
     }

     vector<Point> ptList;
     for (auto x : allShapes) {
         x->GetEdgePointList(ptList);
         Color c = x->getLineColor();
         for (auto p : ptList) {
             if (p.x >= 0 && p.x < width && p.y>0 && p.y < height) {
                 int index = (p.x + p.y * width) * 3;
                 pixels[index + 0] = c.r;
                 pixels[index + 1] = c.g;
                 pixels[index + 2] = c.b;
             }
         }
     }
}
void Canvas::SaveToBitmap(const char* filename) {

    WriteBitmap(pixels, width, height, filename);
}