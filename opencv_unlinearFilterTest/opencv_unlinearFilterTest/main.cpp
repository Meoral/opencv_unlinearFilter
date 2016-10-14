//
//  main.cpp
//  opencv_nonlinearFilterTest
//
//  Created by ZHHJemotion on 2016/10/12.
//  Copyright � 2016�� Lukas_Zhang. All rights reserved.
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
//    Describe: global varibales ȫ�ֱ���
// ========================================================================================
Mat srcImage, dstImage1, dstImage2, dstImage3;
int medianBlurValue = 5; //��ֵ�˲�����ֵ
int bilateralFilterValue = 10; //˫���˲��ο�ֵ
int gaussianBlurValue = 6; //��˹�˲��ں�ֵ


// ================================== global function declaration section ==========================
//    Describe: global function
// =============================================================================================
// the callback function of TrackBar --- �켣���ص�����
static void onMedianBlur(int, void *);  //��ֵ�˲�
static void onBilateralFilter(int, void *);  //˫���˲�
static void onGaussianBlur(int, void *); //��˹�˲�


// ================================== main() function ===================================

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    system("color 5E");
    
    // read the original image ����ԭͼ
    srcImage = imread(PATH+string("1.jpg"),1);
    // exception handling �쳣����
    if(!srcImage.data) {printf("Errpr: we can't read the image 1.jpg!"); return false;}
    
    // ��¡ԭͼ��Mat������
    dstImage1 = srcImage.clone();
    dstImage2 = srcImage.clone();
    dstImage3 = srcImage.clone();
    
    // show the original image ��ʾԭͼ
    namedWindow("the original image");
    imshow("the original image", srcImage);
    
    // ---------------------------- Median Blur ��ֵ�˲� --------------------------------
    // create a new window ��������
    namedWindow("the median blur image");
    // create a TrackBar �����켣��
    createTrackbar("����ֵ", "the median blur image", &medianBlurValue, 50, onMedianBlur);
    onMedianBlur(medianBlurValue, 0);
    
    // ---------------------------- Bilateral Filter ˫���˲� ---------------------------
    // create a new window ��������
    namedWindow("the bilateral filter image");
    // create a TrackBar �����켣��
    createTrackbar("����ֵ", "the bilateral filter image", &bilateralFilterValue, 50, onBilateralFilter);
    onBilateralFilter(bilateralFilterValue, 0);
    
    // ---------------------------- Gaussian Blur ��˹�˲� ------------------------------
    // create a new window ��������
    namedWindow("the gaussian blur image");
    // create a TrackBar �����켣��
    createTrackbar("�ں�ֵ", "the gaussian blur image", &gaussianBlurValue, 40, onGaussianBlur);
    onGaussianBlur(gaussianBlurValue, 0);
    
    // output some helpful infomation
    cout<<endl<<"\t ok! now please change the TRACKBAR to observe the result of the image~ \n\n"
            <<"\t if you type 'q', the program will quit! \n"
            <<"\n\n\t\t\t\t by ZHHJemotion";
    while (char(waitKey(1)) != 'q') {}
    
    // ========================================================================================
    // Bilateral Filter without TrackBar �޹켣����˫���˲�
    Mat image = imread(PATH+string("1.jpg"),1);
    if (!image.data) {
        printf("Error: there is a error in reading the image 1.jpg! \n");
        return false;
    }
    
    namedWindow("ԭͼ");
    imshow("ԭͼ",image);
    
    Mat output;
    namedWindow("Ч��ͼ");
    bilateralFilter(image, output, 25, 25*2, 25/2);
    imshow("Ч��ͼ", output);
    
    waitKey(0);
    
    
    return 0;
}



// ============================ onMedianBlur() Funciton ===============================
//    Describe: the callback of the median blur ��ֵ�˲��Ļص�����
// ====================================================================================
static void onMedianBlur(int, void *)
{
    medianBlur(srcImage, dstImage1, medianBlurValue*2+1);
    imshow("the median blur image", dstImage1);
}



// =========================== onBilatereaFilter() Function ==========================
//    Describe: the callback of the bilateral filter ˫���˲��Ļص�����
// ===================================================================================
static void onBilateralFilter(int, void *)
{
    bilateralFilter(srcImage, dstImage2, bilateralFilterValue, bilateralFilterValue*2, bilateralFilterValue/2);
    imshow("the bilateral filter image", dstImage2);
}



// =========================== onGaussianBlur() Function ============================
//    Describe: the callback of the guassian blur ��˹�˲��Ļص�����
// ==================================================================================
static void onGaussianBlur(int, void *)
{
    GaussianBlur(srcImage, dstImage3, Size(gaussianBlurValue*2+1, gaussianBlurValue*2+1), 0, 0);
    imshow("the gaussian blur image", dstImage3);
}












