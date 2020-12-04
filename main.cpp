#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <cstdio>

using namespace std;
using namespace cv;

bool replaceLogo(CV_IN_OUT Mat& img, CV_IN_OUT Mat temp);

const double MAX_VAL = 0.8f;
const int LIMIT = 20;

/**
 * @function main
 */
int main( int, char** argv )
{

    Mat img; Mat templ; Mat result;
    img = imread( argv[1], 1 );
    templ = imread( argv[2], 1 );

    int i = 0;
    while (true) {
        bool is_replaced = replaceLogo(img, templ);
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
bool replaceLogo(CV_IN_OUT Mat& img, CV_IN_OUT Mat temp)
{
    Mat result;
    matchTemplate(img, temp, result, 5);
    double minVal; double maxVal; Point minLoc; Point maxLoc; Point matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    if(maxVal > MAX_VAL) {
        matchLoc = maxLoc;
        cout << "minVal - " << minVal << endl;
        cout << "maxVal - " << maxVal << endl;
        cout << "minLoc - " << minLoc << endl;
        cout << "maxLoc - " << maxLoc << endl;
        rectangle(img, matchLoc, Point(matchLoc.x + temp.cols , matchLoc.y + temp.rows ), Scalar::all(0), CV_FILLED, 8, 0 );
        return true;
    } else {
        cout << "Logo has not found" << endl;
        return false;
    }
}
