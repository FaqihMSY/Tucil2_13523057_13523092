#ifndef _IMAGECOMPRESSION_HPP
#define _IMAGECOMPRESSION_HPP

#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <filesystem>
using namespace std;

extern int depth, verticesCount;

struct Node{
    int x, y, currWidth, currHeight, depthOfVertice;
};

cv::Mat compress_image(cv::Mat image, string address, int errorMeasurementMethod, int threshold, int minBlockSize);

#endif