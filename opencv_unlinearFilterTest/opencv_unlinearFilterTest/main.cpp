//
//  main.cpp
//  opencv_nonlinearFilterTest
//
//  Created by ZHHJemotion on 2016/10/12.
//  Copyright © 2016年 Lukas_Zhang. All rights reserved.
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
//    Describe: global varibales 全局变量
// ========================================================================================
Mat srcImage, dstImage1, dstImage2, dstImage3;
int medianBlurValue = 5; //中值滤波参数值
int bilateralFilterValue = 10; //双边滤波参考值
int gaussianBlurValue = 6; //高斯滤波内核值


// ================================== global function declaration section ==========================
//    Describe: global function
// =============================================================================================
// the callback function of TrackBar --- 轨迹条回调函数
static void onMedianBlur(int, void *);  //中值滤波
static void onBilateralFilter(int, void *);  //双边滤波
static void onGaussianBlur(int, void *); //高斯滤波


// ================================== main() function ===================================

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    system("color 5E");
    
    // read the original image 载入原图
    srcImage = imread(PATH+string("1.jpg"),1);
    // exception handling 异常处理
    if(!srcImage.data) {printf("Errpr: we can't read the image 1.jpg!"); return false;}
    
    // 克隆原图到Mat类型中
    dstImage1 = srcImage.clone();
    dstImage2 = srcImage.clone();
    dstImage3 = srcImage.clone();
    
    // show the original image 显示原图
    namedWindow("the original image");
    imshow("the original image", srcImage);
    
    // ---------------------------- Median Blur 中值滤波 --------------------------------
    // create a new window 创建窗口
    namedWindow("the median blur image");
    // create a TrackBar 创建轨迹条
    createTrackbar("参数值", "the median blur image", &medianBlurValue, 50, onMedianBlur);
    onMedianBlur(medianBlurValue, 0);
    
    // ---------------------------- Bilateral Filter 双边滤波 ---------------------------
    // create a new window 创建窗口
    namedWindow("the bilateral filter image");
    // create a TrackBar 创建轨迹条
    createTrackbar("参数值", "the bilateral filter image", &bilateralFilterValue, 50, onBilateralFilter);
    onBilateralFilter(bilateralFilterValue, 0);
    
    // ---------------------------- Gaussian Blur 高斯滤波 ------------------------------
    // create a new window 创建窗口
    namedWindow("the gaussian blur image");
    // create a TrackBar 创建轨迹条
    createTrackbar("内核值", "the gaussian blur image", &gaussianBlurValue, 40, onGaussianBlur);
    onGaussianBlur(gaussianBlurValue, 0);
    
    // output some helpful infomation
    cout<<endl<<"\t ok! now please change the TRACKBAR to observe the result of the image~ \n\n"
            <<"\t if you type 'q', the program will quit! \n"
            <<"\n\n\t\t\t\t by ZHHJemotion";
    while (char(waitKey(1)) != 'q') {}
    
    // ========================================================================================
    // Bilateral Filter without TrackBar 无轨迹条的双边滤波
    
    
    return 0;
}



// ============================ onMedianBlur() Funciton ===============================
//    Describe: the callback of the median blur 中值滤波的回调函数
// ====================================================================================
static void onMedianBlur(int, void *)
{
    medianBlur(srcImage, dstImage1, medianBlurValue*2+1);
    imshow("the median blur image", dstImage1);
}



// =========================== onBilatereaFilter() Function ==========================
//    Describe: the callback of the bilateral filter 双边滤波的回调函数
// ===================================================================================
static void onBilateralFilter(int, void *)
{
    bilateralFilter(srcImage, dstImage2, bilateralFilterValue, bilateralFilterValue*2, bilateralFilterValue/2);
    imshow("the bilateral filter image", dstImage2);
}



// =========================== onGaussianBlur() Function ============================
//    Describe: the callback of the guassian blur 高斯滤波的回调函数
// ==================================================================================
static void onGaussianBlur(int, void *)
{
    GaussianBlur(srcImage, dstImage3, Size(gaussianBlurValue*2+1, gaussianBlurValue*2+1), 0, 0);
    imshow("the gaussian blur image", dstImage3);
}












