#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


/*请把下面的字符串分别改为你的姓名和学号*/
const char *name = "王浩宇";
const char *ID = "X01814031";

/*在下面添加你的代码
类的声明和实现代码都写在下方*/
class Matrix {
private:
    int rows;//矩阵的行数
    int cols;//矩阵的列数
    double *pValue;//矩阵的数值

public:
    /*改写默认构造函数*/
    Matrix():rows(0),cols(0) {
        pValue=nullptr;
    }

    /*构造函数*/
    Matrix(const int numRows, const int numCols)//构造函数
    {
        rows=numRows;
        cols=numCols;
        pValue=new double[numCols*numRows];//开辟空间
        for(int i=0;i<numRows*numCols;i++) //初始化pValue为0
        {
            pValue[i]=0;
        }
    }

    /*运算符=的重载*/
    Matrix &operator=(const Matrix &v)//=的重载
    {
        this->rows=v.rows;//行数更新
        this->cols=v.cols;//列数更新
        for(int i=0;i<rows*cols;i++)//pValue赋值
        {
            this->pValue[i]=v.pValue[i];
        }
        return *this;
    }
    /*在下方编写拷贝构造函数*/
    Matrix(const Matrix &v)//构造拷贝函数
    {
        rows=v.rows;//行数更新
        cols=v.cols;//列数更新
        pValue=new double[rows*cols];//开辟空间
        memset(pValue,0,sizeof(double)*rows*cols);//初始化为0
        for(int r=0;r<rows;r++)
        {
            for(int j=0;j<cols;j++)
            {
                int pos=r*cols+j;//pos为当前位置在一维数组的位置
                pValue[pos]=v.pValue[pos];
            }
        }
    }
    /*析构函数*/
    ~Matrix() {
        delete []pValue;//释放内存
    }

    /*在下方编写其它成员函数*/
    int GetColCount()//返回行数
    {
       return this->cols;
    }

    int GetRowCount()//返回列数
    {
        return this->rows;
    }

    void SetValue(int i,int j,double value)//给矩阵赋值
    {
        int pos=cols*i+j;
        this->pValue[pos]=value;
    }

    int GetValue(int i,int j)//获得矩阵某个位置的值
    {
        int pos=i*cols+j;
        return this->pValue[pos];
    }

    Matrix Transpose()//矩阵的转置
    {
        Matrix ans(cols,rows);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int pos=i*rows+j;//(i,j)在一维数组的位置
                int newpos=j*cols+i;//(j,i)在一维数组的位置
                ans.pValue[newpos]=pValue[pos];//(i,j)的值赋给(j,i)
            }
        }
        return ans;
    }

    Matrix Multiply(Matrix v)//矩阵乘法
    {
        if(this->cols!=v.rows)//如果矩阵乘法不成立
        {
            Matrix ans1;
            return ans1;
        }
        Matrix ans2(rows,v.cols);//
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<v.cols;j++)
            {
                int pos=i*v.cols+j;//结果矩阵中(i,j)在一维数组的位置
                for(int k=0;k<cols;k++)
                {
                    int pos_left=i*cols+k;//被乘数(i,k)在一维数组的位置
                    int pos_right=k*v.cols+j;//乘数(k,j)在一维数组的位置
                    ans2.pValue[pos]+=pValue[pos_left]*v.pValue[pos_right];//各项分别相乘的和
                }
            }
        }
        return ans2;
    }


    /*Display函数不用改写*/
    void Display() const {
        if (0 == rows || 0 == cols || nullptr == pValue) {
            cout << "Empty Matrix" << endl;
        }
        else {
            int i = 0;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    cout << pValue[i++] << ' ';
                }
                cout << endl;
            }
        }
    }
};


/*上述代码编写完成之后，请把下面的宏改为:
#define TEST 1
*/
#define TEST 1

/*=======================================================*/
/*以下代码不要修改*/
/*=======================================================*/
#define PI  3.1415926
int main(void) {

    cout << name<<" "<<ID << endl;

#if TEST
    Matrix Non;
    cout << "Non rows = " << Non.GetRowCount() << ", cols=" << Non.GetColCount() << endl;

    Matrix R(2, 2);
    double theta = PI / 4;
    R.SetValue(0, 0, cos(theta));
    R.SetValue(1, 0, -sin(theta));
    R.SetValue(0, 1, -R.GetValue(0,1));
    R.SetValue(1, 1, R.GetValue(0,0));
    R.Display();

    Matrix v(2, 1);
    v.SetValue(0, 0, sqrt(2.0)/2);
    v.SetValue(1, 0, sqrt(2.0)/2);

    Matrix w = R.Multiply(v);
    w.Display();

    Matrix vt = v.Transpose();
    Matrix wn = R.Multiply(vt);
    wn.Display();

#endif // TEST

    return 0;
}
