#include <opencv2/opencv.hpp>

using namespace cv;

int main( int argc, char** argv )
{
    if(argc != 2)
    {
        printf("useage: %s <imagefile>\n ", argv[0]);
        return -1;
    }
    char* imageName = argv[1];

    Mat image;
    // 读取图片矩阵
    image = imread( imageName, CV_LOAD_IMAGE_COLOR);

    if( !image.data )
    {
        printf( " No image data \n " );
        return -1;
    }

    Mat gray_image;
    // 转换图片为灰色
    cvtColor( image, gray_image, CV_BGR2GRAY );

    // 保存图片到硬盘上
    imwrite( "../img/gray_test.jpg", gray_image );

    // 创建窗口
    namedWindow( imageName, CV_WINDOW_AUTOSIZE );
    namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

    // 显示图片
    imshow( imageName, image );
    imshow( "Gray image", gray_image );

    waitKey(0);

    return 0;
}
