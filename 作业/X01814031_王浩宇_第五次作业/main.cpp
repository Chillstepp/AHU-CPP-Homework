#include "PointAndLine.h"
#include "DataAndCalculate.h"
int main()
{
    Line L0(10, 35, 45);
    vector<point>data = CreateData(L0, 25);
    Line L1 = FitLine(data);
    double dis = CalcDistance(L1, data);
    cout << "L0:" << L0.GetParameter(1) << "x+" << L0.GetParameter(2) << "y+" << L0.GetParameter(3) << "=0" << endl;
    cout << "L1:" << L1.GetParameter(1) << "x+" << L1.GetParameter(2) << "y+" << L1.GetParameter(3) << "=0" << endl;
    cout << "Linear fitting error:" << dis << endl;
    return 0;
}
