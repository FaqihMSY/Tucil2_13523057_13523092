# Tucil2_13523092

## Description
A program for compressing image. The language used in this program is Bahasa Indonesia.

## Compile and Run Instruction (Windows)

### Requirement:
- MinGW (G++)
- OpenCV 4.11.0 (Installed & Configured)

### Compile Command:

Run this command inside the `src/` directory (adjust with the directory of `opencv-4.11.0/`):

```
g++ main.cpp IO/input.cpp IO/output.cpp Function/imagecompression.cpp -o ../bin/main.exe -I C:\opencv-4.11.0\build\install\include -L C:\opencv-4.11.0\build\install\x64\mingw\lib -lopencv_core4110 -lopencv_highgui4110 -lopencv_imgcodecs4110
```

Catatan:
- `-I` shows the path of OpenCV header file.
- `-L` shows the path of OpenCV library.
- `-l` for links OpenCV library.

### Run Program:

If the compilation succeed, run:

```
../bin/main.exe
```

## How to Use

1. At the home page, choose `1` to start entering the inputs for compression (continue to point 2), or `0` to exit the program.
2. Enter the exact path to the image file, for example: `C:\Users\Ahmad\Pictures\pisang.png`. The program supports the following formats: .jpg, .jpeg, .png, .bmp, .tiff, .tif, .webp, .gif, and .jp2.
3. Enter the number corresponding to the desired error measurement method. The error measurement method determines the method used to calculate how high is the variation of an image block color values (Blue, Green, and Red).
4. Enter the threshold value. The threshold is the maximum error value (variation of color from error measurement) allowed before a block is considered to have enough color variation.
5. Enter the minimum block size. This value determines the smallest block size allowed during the compression process.
6. Enter the target compression percentage. This indicates the desired percentage of compression for the image, ignoring the threshold that is entered before. If you want to use your threshold instead, set the target compression percentage to 0.
7. Enter the exact path of where you want to put your compressed image.
8. Your compressed image is ready on the path (point 7).

## Author
Faqih Muhammad Syuhada, 13523057
Muhammad Izzat Jundy, 13523092