#include "imagecompression.hpp"

int depth, verticesCount;

// "PRIVATE"
cv::Vec3b average_color(const cv::Mat& image, int x, int y, int width, int height){
    cv::Scalar sum = cv::sum(image(cv::Rect(x, y, width, height)));
    int totalPixels = width * height;
    return cv::Vec3b(sum[0] / totalPixels, sum[1] / totalPixels, sum[2] / totalPixels);
}

bool is_uniform(const cv::Mat& image, int x, int y, int width, int height, int errorMeasurementMethod, int threshold, cv::Vec3b averageColor){

    if(errorMeasurementMethod == 1){

        unsigned long long sumB = 0, sumG = 0, sumR = 0;
        for(int i = y; i < y + height; i++){
            for(int j = x; j < x + width; j++){
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                sumB += pow((pixel[0] - averageColor[0]), 2);
                sumG += pow((pixel[1] - averageColor[1]), 2);
                sumR += pow((pixel[2] - averageColor[2]), 2);
            }
        }

        if((sumB + sumG + sumR) / (3*width*height) >= threshold){
            return false;
        }

    }else if(errorMeasurementMethod == 2){

        unsigned long long sumB = 0, sumG = 0, sumR = 0;
        for(int i = y; i < y + height; i++){
            for(int j = x; j < x + width; j++){
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                sumB += abs((int) pixel[0] - averageColor[0]);
                sumG += abs((int) pixel[1] - averageColor[1]);
                sumR += abs((int) pixel[2] - averageColor[2]);
            }
        }

        if((sumB + sumG + sumR) / (3 * width * height) >= threshold){
            return false;
        }

    }else if(errorMeasurementMethod == 3){

        int maxB = 0, maxG = 0, maxR = 0, minB = 255, minG = 255, minR = 255;
        for(int i = y; i < y + height; i++){
            for(int j = x; j < x + width; j++){
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                if(maxB < pixel[0]) maxB = pixel[0];
                if(maxG < pixel[1]) maxG = pixel[1];
                if(maxR < pixel[2]) maxR = pixel[2];
                if(minB > pixel[0]) minB = pixel[0];
                if(minG > pixel[1]) minG = pixel[1];
                if(minR > pixel[2]) minR = pixel[2];
            }
        }

        if((maxB + maxG + maxR - minB - minG - minR) / 3 >= threshold){
            return false;
        }

    }else if(errorMeasurementMethod == 4){
        int freq[256][3];
        for(int i = 0; i < 256; i++){
            freq[i][0] = 0;
            freq[i][1] = 0;
            freq[i][2] = 0;
        }

        for(int i = y; i < y + height; i++){
            for(int j = x; j < x + width; j++){
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                freq[pixel[0]][0] += 1;
                freq[pixel[1]][1] += 1;
                freq[pixel[2]][2] += 1;
            }
        }

        double hB = 0, hG = 0, hR = 0;
        for(int i = y; i < y + height; i++){
            for(int j = x; j < x + width; j++){
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                double pB = (double) freq[pixel[0]][0]/(width*height);
                double pG = (double) freq[pixel[1]][1]/(width*height);
                double pR = (double) freq[pixel[2]][2]/(width*height);
                hB += (-1) * pB * log2(pB);
                hG += (-1) * pG * log2(pG);
                hR += (-1) * pR * log2(pR);
            }
        }

        if((hB + hG + hR) / 3 >= threshold){
            return false;
        }
    }
    return true;
}

void quadtree(cv::Mat& image, int width, int height, int errorMeasurementMethod, int threshold, int minBlockSize){
    queue<Node> q;
    q.push({0, 0, width, height, 0}); // x, y, currWidth, currHeight, depthOfVertice

    while(!q.empty()){
        Node temp = q.front();

        int x = temp.x;
        int y = temp.y;
        int currWidth = temp.currWidth;
        int currHeight = temp.currHeight;
        int depthOfVertice = temp.depthOfVertice;
        cv::Vec3b averageColor = average_color(image, x, y, currWidth, currHeight);

        verticesCount++;
        if(depthOfVertice > depth){
            depth = depthOfVertice;

            // cv::imwrite("tempImage.png", image);
            // ifstream tempImage("tempImage.png", ios::binary | ios::ate);
            // streamsize tempSize = tempImage.tellg();
            // tempImage.close();
            // system("del tempImage.png");

            // double tempCompressionRatio = (1.0 - (double) tempSize / imageFileSize);
            // if(tempCompressionRatio >= compressionPercentage){
            //     cout << "\n";
            //     cout << "Kompresi berhenti lebih cepat mengikuti target kompresi!\n";
            //     depth-=1;
            //     break;
            // }
        }

        int halfWidth = currWidth / 2;
        int halfHeight = currHeight / 2;
        if(halfWidth*halfHeight >= minBlockSize && !is_uniform(image, x, y, currWidth, currHeight, errorMeasurementMethod, threshold, averageColor)){
            q.push({x, y, halfWidth, halfHeight, depthOfVertice+1});
            q.push({x + halfWidth, y, currWidth - halfWidth, halfHeight, depthOfVertice+1});
            q.push({x, y + halfHeight, halfWidth, currHeight - halfHeight, depthOfVertice+1});
            q.push({x + halfWidth, y + halfHeight, currWidth - halfWidth, currHeight - halfHeight, depthOfVertice+1});
        }else{
            for(int i = y; i < y + currHeight; i++){
                for(int j = x; j < x + currWidth; j++){
                    image.at<cv::Vec3b>(i, j) = averageColor;
                }
            }
        }

        q.pop();
    }
    
}

// "PUBLIC"
cv::Mat compress_image(cv::Mat image, string address, int errorMeasurementMethod, int threshold, int minBlockSize){
    verticesCount = 0;
    depth = 0;

    quadtree(image, image.cols, image.rows, errorMeasurementMethod, threshold, minBlockSize);
    return image;
}