#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <vector>
#include <queue>
using namespace std;
namespace Graphics {

    class Color {
    public:
        unsigned char r, g, b;
        static Color red, green, blue, white, black, grey, yellow;
    public:
        Color() :r(0xFF), g(0xFF), b(0xFF) {}
        Color(unsigned char _r, unsigned char _g, unsigned char _b) :
            r(_r), g(_g), b(_b) {}
        Color(const Color& clr) :r(clr.r), g(clr.g), b(clr.b) {}
        friend bool operator==(const Color& c1, const Color& c2)
        {
            if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)
                return true;
            return false;
        };
    };


    class Point {
    public:
        int x, y;
    public:
        Point() :x(0), y(0) {}
        Point(int _x, int _y) :x(_x), y(_y) {}
        Point(const Point& v) :x(v.x), y(v.y) {}
        Point& operator=(const Point& v)
        {
            x = v.x;
            y = v.y;
            return *this;
        }
        double DistanceTo(const Point p);
    };


    class Shape {
    private:
        Color lineColor;
    public:
        Shape() :lineColor(Color::black) {}
        Shape(const Color _lineColor) : lineColor(_lineColor) {}
        Shape(const Shape& s) :lineColor(s.lineColor) {}
        void setLineColor(const Color _lineColor) { lineColor = _lineColor; };
        Color getLineColor() const { return lineColor; }
        virtual void GetEdgePointList(vector<Point>& ptList) = 0;
        virtual Shape* Clone() const = 0;
        virtual ~Shape() {};
    };

    class Rect :public Shape {
    private:
        Point p;
        int width, height;
    public:
        //无参
        Rect() :p(Point()), width(1), height(1) {}
        //含参  颜色默认黑色
        Rect(const Point& position, const int _width, const int _height) :
            p(position), width(_width), height(_height) {}
        //含参 颜色自定义
        Rect(const Color _lineColor, const Point& position,
            const int _width, const int _height) :
            Shape(_lineColor), p(position), width(_width), height(_height) {}
        //复制构造函数
        Rect(const Rect& r) :Shape(r), p(r.p), width(r.width), height(r.height) {}
        //重载=
        Rect& operator=(const Rect& r);
        //clone一个一摸一样，使得画板独立不受影响
        Shape* Clone() const;
        //边表
        void GetEdgePointList(vector<Point>& ptList);
        ~Rect() {}
    };

    class Circle :public Shape {
    private:
        Point p;
        int r;
    public:
        Circle() :p(Point()), r(1) {}
        Circle(const Point& position, const int _r) :
            p(position), r(_r) {}
        Circle(const Color _lineColor, const Point& position, const int _r):
            Shape(_lineColor), p(position), r(_r) {}
        Circle(const Circle& v) :Shape(v), p(v.p), r(v.r) {}
        Circle& operator=(const Circle& v);
        Shape* Clone() const;
        void GetEdgePointList(vector<Point>& ptList);
        ~Circle() {}
    };


}
#endif
