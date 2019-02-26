#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;

//this c++ script for just vertical inpainting !


Mat image,mask,gray;

int main(){

image=imread("/home/joe/Desktop/defect2.jpg");
mask=imread("/home/joe/Desktop/mask2.jpg");
Mat img=Mat::zeros(Size(image.cols,image.rows),CV_8UC3);

cvtColor(mask,mask,COLOR_BGR2GRAY);
threshold(mask,mask,200,255,THRESH_BINARY);

for(int zzz=0;zzz<10;zzz++){
for(int x=0;x<image.rows;x++){
    for(int y=0;y<image.cols;y++){
        if(mask.at<uchar>(x,y)>150){
           image.at<Vec3b>(x,y)=image.at<Vec3b>(x,y-1);
            img.at<Vec3b>(x,y)=image.at<Vec3b>(x,y-1);
            mask.at<uchar>(x,y)=0;
            break;
        }
    }
    for(int y=mask.cols-1;y>-1;y--){
        if(mask.at<uchar>(x,y)>150){
            image.at<Vec3b>(x,y)=image.at<Vec3b>(x,y+1);
            img.at<Vec3b>(x,y)=image.at<Vec3b>(x,y+1);
            mask.at<uchar>(x,y)=0;
            break;
        }
    }

    }
}

imshow("ssss",image);
imshow("ssss1",img);
waitKey(0);



}