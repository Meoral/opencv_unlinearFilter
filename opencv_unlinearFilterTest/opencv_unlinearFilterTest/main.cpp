//
//  main.cpp
//  opencv_nonlinearFilterTest
//
//  Created by ZHHJemotion on 2016/10/12.
//  Copyright ý 2016Äê Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

#define PATH string("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test7/opencv_unlinearFilterTest/opencv_unlinearFilterTest/")

// =================================== global varibales declaration section ======================
//    Describe: global varibales È«¾Ö±äÁ¿
// ========================================================================================
Mat srcImage, dstImage1, dstImage2, dstImage3;
int medianBlurValue = 5; //ÖÐÖµÂË²¨²ÎÊýÖµ
int bilateralFilterValue = 10; //Ë«±ßÂË²¨²Î¿¼Öµ
int gaussianBlurValue = 6; //¸ßË¹ÂË²¨ÄÚºËÖµ


// ================================== global function declaration section ==========================
//    Describe: global function
// =============================================================================================
// the callback function of TrackBar --- ¹ì¼£Ìõ»Øµ÷º¯Êý
static void onMedianBlur(int, void *);  //ÖÐÖµÂË²¨
static void onBilateralFilter(int, void *);  //Ë«±ßÂË²¨
static void onGaussianBlur(int, void *); //¸ßË¹ÂË²¨


// ================================== main() function ===================================

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    system("color 5E");
    
    // read the original image ÔØÈëÔ­Í¼
    srcImage = imread(PATH+string("1.jpg"),1);
    // exception handling Òì³£´¦Àí
    if(!srcImage.data) {printf("Errpr: we can't read the image 1.jpg!"); return false;}
    
    // ¿ËÂ¡Ô­Í¼µ½MatÀàÐÍÖÐ
    dstImage1 = srcImage.clone();
    dstImage2 = srcImage.clone();
    dstImage3 = srcImage.clone();
    
    // show the original image ÏÔÊ¾Ô­Í¼
    namedWindow("the original image");
    imshow("the original image", srcImage);
    
    // ---------------------------- Median Blur ÖÐÖµÂË²¨ --------------------------------
    // create a new window ´´½¨´°¿Ú
    namedWindow("the median blur image");
    // create a TrackBar ´´½¨¹ì¼£Ìõ
    createTrackbar("²ÎÊýÖµ", "the median blur image", &medianBlurValue, 50, onMedianBlur);
    onMedianBlur(medianBlurValue, 0);
    
    // ---------------------------- Bilateral Filter Ë«±ßÂË²¨ ---------------------------
    // create a new window ´´½¨´°¿Ú
    namedWindow("the bilateral filter image");
    // create a TrackBar ´´½¨¹ì¼£Ìõ
    createTrackbar("²ÎÊýÖµ", "the bilateral filter image", &bilateralFilterValue, 50, onBilateralFilter);
    onBilateralFilter(bilateralFilterValue, 0);
    
    // ---------------------------- Gaussian Blur ¸ßË¹ÂË²¨ ------------------------------
    // create a new window ´´½¨´°¿Ú
    namedWindow("the gaussian blur image");
    // create a TrackBar ´´½¨¹ì¼£Ìõ
    createTrackbar("ÄÚºËÖµ", "the gaussian blur image", &gaussianBlurValue, 40, onGaussianBlur);
    onGaussianBlur(gaussianBlurValue, 0);
    
    // output some helpful infomation
    cout<<endl<<"\t ok! now please change the TRACKBAR to observe the result of the image~ \n\n"
            <<"\t if you type 'q', the program will quit! \n"
            <<"\n\n\t\t\t\t by ZHHJemotion";
    while (char(waitKey(1)) != 'q') {}
    
    // ========================================================================================
    // Bilateral Filter without TrackBar ÎÞ¹ì¼£ÌõµÄË«±ßÂË²¨
    Mat image = imread(PATH+string("1.jpg"),1);
    if (!image.data) {
        printf("Error: there is a error in reading the image 1.jpg! \n");
        return false;
    }
    
    namedWindow("Ô­Í¼");
    imshow("Ô­Í¼",image);
    
    Mat output;
    namedWindow("Ð§¹ûÍ¼");
    bilateralFilter(image, output, 25, 25*2, 25/2);
    imshow("Ð§¹ûÍ¼", output);
    
    waitKey(0);
    
    
    return 0;
}



// ============================ onMedianBlur() Funciton ===============================
//    Describe: the callback of the median blur ÖÐÖµÂË²¨µÄ»Øµ÷º¯Êý
// ====================================================================================
static void onMedianBlur(int, void *)
{
    medianBlur(srcImage, dstImage1, medianBlurValue*2+1);
    imshow("the median blur image", dstImage1);
}



// =========================== onBilatereaFilter() Function ==========================
//    Describe: the callback of the bilateral filter Ë«±ßÂË²¨µÄ»Øµ÷º¯Êý
// ===================================================================================
static void onBilateralFilter(int, void *)
{
    bilateralFilter(srcImage, dstImage2, bilateralFilterValue, bilateralFilterValue*2, bilateralFilterValue/2);
    imshow("the bilateral filter image", dstImage2);
}



// =========================== onGaussianBlur() Function ============================
//    Describe: the callback of the guassian blur ¸ßË¹ÂË²¨µÄ»Øµ÷º¯Êý
// ==================================================================================
static void onGaussianBlur(int, void *)
{
    GaussianBlur(srcImage, dstImage3, Size(gaussianBlurValue*2+1, gaussianBlurValue*2+1), 0, 0);
    imshow("the gaussian blur image", dstImage3);
}












