#ifndef _CANVAS_H_
#define _CANVAS_H_
#include "Shape.h"
#include <vector>

using namespace std;
namespace Graphics {

    class Canvas {
    private:
        int width, height;
        Color bgColor;
        vector<Shape*> allShapes;
        unsigned char* pixels;
    private:
        void RemoveAllShapes();
    public:
        Canvas() :bgColor(Color::white), width(640), height(480), pixels(nullptr) {}
        Canvas(int _width, int _height, Color _bgColor = Color::white) :
            width(_width), height(_height), bgColor(_bgColor),pixels(nullptr) {}
        Canvas(const Canvas& c);
        Canvas& operator=(const Canvas& c);

        ~Canvas() {
            delete[]pixels;
            RemoveAllShapes();
        }
       
        void Attach(const Shape& s) {
            allShapes.push_back(s.Clone());
        }

        void ReDraw() {}

        void ConvertToBitmap();
        void FloodFill(int x, int y, Color FillColor);
        void SaveToBitmap(const char* filename);
    };
}
#endif
