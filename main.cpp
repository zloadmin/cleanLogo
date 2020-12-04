#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <experimental/filesystem>
#include <regex>

using namespace std;
using namespace cv;
namespace fs = std::filesystem;

bool replaceLogo(CV_IN_OUT Mat &img, CV_IN_OUT Mat &logo, CV_IN_OUT Mat &new_logo);

bool init(int argc, char **argv);

bool initLogo(char **argv);

bool initNewLogo(char **argv);

bool initFile(char **argv);

string getNewFilePath(char **argv);

string getOldFilePath(char **argv);

bool checkImageSize();

const double MAX_VAL = 0.8f;
const int LIMIT = 20;
Mat img;
Mat logo;
Mat new_logo;
Mat original;

/**
 * @function main
 */
int main(int argc, char **argv) {
    // Init
    if (!init(argc, argv)) return -1;

    int i = 0;
    while (true) {
        bool is_replaced = replaceLogo(img, logo, new_logo);
        if (!is_replaced) break;
        if (i > LIMIT) break;
        ++i;
    }
    if (i) {
        cout << "Save image" << endl;
        imwrite(getNewFilePath(argv), img);
        imwrite(getOldFilePath(argv), original);
    }
    return 0;
}

bool replaceLogo(CV_IN_OUT Mat &img, CV_IN_OUT Mat &logo, CV_IN_OUT Mat &new_logo) {
    Mat result;
    matchTemplate(img, logo, result, 5);
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Point matchLoc;
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
    if (maxVal > MAX_VAL) {
        matchLoc = maxLoc;
        cout << "Logo has been found. " << "Coordinates: " << maxLoc << endl;
        new_logo.copyTo(img(cv::Rect(matchLoc.x, matchLoc.y, new_logo.cols, new_logo.rows)));
        return true;
    } else {
        cout << "Logo has not found " << endl;
        return false;
    }
}

bool init(int argc, char **argv) {
    if (argc < 4) {
        cout << "Usage: cleanLogo <Logo_Path> <NewLogo_Path> <Image_Path>" << endl;
        return false;
    }
    return initLogo(argv) && initNewLogo(argv) && initFile(argv) && checkImageSize();
}

bool initLogo(char **argv) {
    logo = imread(argv[1], 1);
    if (!logo.data) {
        cout << "Can not load logo file " << argv[1] << endl;
        return false;
    }
    cout << "Loaded logo " << argv[1] << " Size col " << logo.cols << " row " << logo.rows << endl;
    return true;
}

bool initNewLogo(char **argv) {
    new_logo = imread(argv[2], 1);
    if (!new_logo.data) {
        cout << "Can not load new logo file " << argv[2] << endl;
        return false;
    }
    cout << "Loaded new logo " << argv[2] << " Size col " << new_logo.cols << " row " << new_logo.rows << endl;
    return true;
}

bool initFile(char **argv) {
    img = imread(argv[3], 1);
    if (!img.data) {
        cout << "Can not load file " << argv[3] << endl;
        return false;
    }
    cout << "Loaded file " << argv[3] << " Size col " << img.cols << " row " << img.rows << endl;
    original = img;
    return true;
}

bool checkImageSize() {
    if (img.cols > logo.cols && img.rows > logo.rows) return true;
    cout << "Image smallest then logo" << endl;
    return false;
}

string getNewFilePath(char **argv) {
    fs::path absolute_path = fs::absolute(argv[3]);
    string s(absolute_path);
    regex e("\\.(.*)$");
    return std::regex_replace(s, e, "_ORIGIN_.$1");
}

string getOldFilePath(char **argv) {
    return fs::absolute(argv[3]);
}