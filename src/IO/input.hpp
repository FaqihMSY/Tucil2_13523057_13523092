#ifndef _INPUT_HPP
#define _INPUT_HPP

#include <bits/stdc++.h>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int input_home();
string input_image_address_import();
int input_error_measurement_method();
double input_threshold(int errorMeasurementMethod);
int input_minimum_block_size();
double input_compression_percentage();
string input_image_address_export();

#endif