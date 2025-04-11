#include "./IO/input.hpp"
#include "./IO/output.hpp"
#include "./Function/imagecompression.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>
using namespace std::chrono;

int main(){

    int cmd, errorMeasurementMethod, minBlockSize;
    double threshold, compressionPercentage;
    string addressOld, addressNew;
    cv::Mat image, imageCompressed;

    while(1){

        cmd = input_home();

        if(cmd == 0){
            goodbye();
            break;
        }
        
        addressOld = input_image_address_import();
        errorMeasurementMethod = input_error_measurement_method();
        threshold = input_threshold(errorMeasurementMethod);
        minBlockSize = input_minimum_block_size();
        compressionPercentage = input_compression_percentage();

        image = cv::imread(addressOld, cv::IMREAD_COLOR);
        // cv::imshow("Gambar", image);
        // cv::waitKey(0);

        auto start = high_resolution_clock::now();

        // BEGIN COMPRESSION
        imageCompressed = compress_image(image, addressOld, errorMeasurementMethod, threshold, minBlockSize, compressionPercentage);
        // END COMPRESSION

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        compression_succeed();

        addressNew = input_image_address_export();
        cv::imwrite(addressNew, imageCompressed);

        save_succeed();

        process_information(duration.count(), addressOld, addressNew);

        cv::imshow("Gambar Terkompres", imageCompressed);
        cv::waitKey(0);

    }
    
    return 0;
}