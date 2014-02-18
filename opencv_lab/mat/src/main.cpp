#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    // 通过Mat构造函数创建，行，列，数据类型，标量
    Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));

    cout << "M = " << M << endl;

    int sz[3] = {2, 2, 2};
    Mat L(3, sz, CV_8UC(1), Scalar::all(0));
    
    //cout << "L = " << L << endl;
    
    M.create(4, 4, CV_8UC(2));
    cout << "M = " << M << endl;
}
