#include "Shape.h"
#include< algorithm >
using namespace Graphics;

Color Color::red(0xFF, 0x00, 0x00);
Color Color::green(0x00, 0xFF, 0x00);
Color Color::blue(0x7A, 0xCA, 0xFF);
Color Color::white(0xFF, 0xFF, 0xFF);
Color Color::black(0x00, 0x00, 0x00);
Color Color::grey(0x7A, 0x7A, 0x7A);
Color Color::yellow(0xFF, 0xFF, 0x00);

bool operator==(const Color& c1, const Color& c2){
    return (c1.r == c2.r) && (c1.g == c2.g) && (c1.b == c2.b);
}

double Point::DistanceTo(const Point p) {
    return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
}

Rect& Rect::operator=(const Rect& r) {
    if (this != &r) {
        setLineColor(r.getLineColor());
        p = r.p;
        width = r.width;
        height = r.height;
    }
    return *this;
}

Shape* Rect::Clone() const {
    return new Rect(*this);
}

void Rect::GetEdgePointList(vector<Point>& ptList) {
    ptList.clear();
    for (int i = p.x; i < p.x + width; ++i) {
        ptList.push_back(Point(i, p.y));
        ptList.push_back(Point(i, p.y + height));
    }
    for (int j = p.y; j < p.y + height; ++j) {
        ptList.push_back(Point(p.x, j));
        ptList.push_back(Point(p.x + width, j));
    }
}

Circle& Circle::operator=(const Circle& c) {
    if (this != &c) {
        setLineColor(c.getLineColor());
        p = c.p;
        r = c.r;
    }
    return *this;
}

Shape* Circle::Clone() const { return new Circle(*this); }

void Circle::GetEdgePointList(vector<Point>& ptList) {
    ptList.clear();
    if (r <= 0)return;
    double delta = max(1.0 / r, 1e-5);
    static const double two_pi = 3.1415926 * 2;
    for (double t = 0; t < two_pi; t += delta) {
        int x = static_cast<int>(r * cos(t) + p.x);
        int y = static_cast<int>(r * sin(t) + p.y);
        ptList.push_back(Point(x, y));
    }
}
