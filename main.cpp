#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <cstdio>

using namespace std;
using namespace cv;

bool replaceLogo(CV_IN_OUT Mat& img, CV_IN_OUT Mat& logo, CV_IN_OUT Mat& new_logo);

const double MAX_VAL = 0.8f;
const int LIMIT = 20;

/**
 * @function main
 */
int main( int, char** argv )
{


    Mat img = imread( "test.jpeg", 1 );
    Mat logo = imread( "logo.jpg", 1 );
    Mat new_logo = imread( "new_logo.jpg", 1 );

    int i = 0;
    while (true) {
        bool is_replaced = replaceLogo(img, logo, new_logo);
       ++i;
       if(!is_replaced) {
           cout << "Logo has not been replaced" << endl;
           break;
       }
       if(i > LIMIT) {
           cout << "Limit has been finished" << endl;
           break;
       }
    }
    cout << "Save image" << endl;
    imwrite("new_image.jpeg", img);
    return 0;
}
bool replaceLogo(CV_IN_OUT Mat& img, CV_IN_OUT Mat& logo, CV_IN_OUT Mat& new_logo)
{
    Mat result;
    matchTemplate(img, logo, result, 5);
    double minVal; double maxVal; Point minLoc; Point maxLoc; Point matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    if(maxVal > MAX_VAL) {
        matchLoc = maxLoc;
        cout << "Logo has been found" << "Coordinates " << maxLoc << endl;
        new_logo.copyTo(img(cv::Rect(matchLoc.x,matchLoc.y,new_logo.cols, new_logo.rows)));
        return true;
    } else {
        cout << "Logo has not found" << endl;
        return false;
    }
}
