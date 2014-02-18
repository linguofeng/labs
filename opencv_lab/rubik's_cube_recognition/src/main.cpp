#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

VideoCapture cap;
Mat frame;
Mat HSV;
Mat hsv;

const int hsv_max = 256;

int h_min = 0, h_max = hsv_max;
int s_min = 0, s_max = hsv_max;
int v_min = 0, v_max = hsv_max;

Scalar blueScalar[] = { Scalar(110, 104, 58), Scalar(158, 256, 256) };

void on_trackbar(int, void*)
{
    //inRange(HSV, Scalar(MIN(h_min, h_max), MIN(s_min, s_max), MIN(v_min, v_max))
            //, Scalar(MAX(h_min, h_max), MAX(s_min, s_max), MAX(v_min, v_max)), hsv);
    inRange(HSV, blueScalar[0], blueScalar[1], hsv);

    cout << "HMIN = " << h_min << "     HMAX = " << h_max << endl;
    cout << "SMIN = " << s_min << "     SMAX = " << s_max << endl;
    cout << "VMIN = " << v_min << "     VMAX = " << v_max << endl;

    // 边缘查找并描边
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(hsv, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
   
    // 获取Moments
    vector<Moments> mu(contours.size() );
    for( int i = 0; i < contours.size(); i++ )
    { 
        mu[i] = moments( contours[i], false ); 
    }

    // 获取重心
    vector<Point2f> mc( contours.size() );
    for( int i = 0; i < contours.size(); i++ )
    {
        mc[i] = Point2f( mu[i].m10 / mu[i].m00 , mu[i].m01 / mu[i].m00 );
    }
    
    for( int i = 0; i < contours.size(); i++ )
    {
        // 描边
        drawContours( frame, contours, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point() );
        // 画圆
        circle( frame, mc[i], 4, Scalar(0, 255, 0), -1, 8, 0 );
    }
    
}

int main( int argc, char** argv )
{
    // 打开摄像头
    cap.open(0);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
 
    // 创建窗口，同名的图像或控件都显示在一起
    namedWindow("HSV", CV_WINDOW_AUTOSIZE);
    createTrackbar("H min", "HSV", &h_min, hsv_max, on_trackbar);
    createTrackbar("H max", "HSV", &h_max, hsv_max, on_trackbar);
    
    createTrackbar("S min", "HSV", &s_min, hsv_max, on_trackbar);
    createTrackbar("S max", "HSV", &s_max, hsv_max, on_trackbar);
    
    createTrackbar("V min", "HSV", &v_min, hsv_max, on_trackbar);
    createTrackbar("V max", "HSV", &v_max, hsv_max, on_trackbar);
   
    while (true)
    {
        cap.read(frame);                  // 从摄像头读取图像数据
        flip(frame, frame, 1);            // 图像反转 大于0左右，等于0上下，小于0前两者
        cvtColor(frame, HSV, CV_BGR2HSV); // bgr -> hsv
        on_trackbar(0, NULL);
        
        imshow("source", frame);
        imshow("hsv", hsv);
       
        int key = waitKey(30);
        if(key >= 0) break;
    }

    return 0;
}
