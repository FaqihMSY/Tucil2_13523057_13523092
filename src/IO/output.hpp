#ifndef _OUTPUT_HPP
#define _OUTPUT_HPP

#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <filesystem>
using namespace std;

void set_home();
void set_image_address();
void set_error_measurement_method();
void set_threshold();
void set_minimum_block_size();
void set_compression_percentage();

void goodbye();
void image_not_found();
void compression_succeed();
void save_succeed();

void process_information(long long duration,  string addressOld, string addressNew);

#endif