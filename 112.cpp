#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;
Mat image,mask,gray;





int main(){
    Mat kernel=(Mat_<uchar>(3,3)<<0,1,0,1,0,1,0,1,0);
int k=0;
image=imread("/home/joe/Desktop/defect.jpg",IMREAD_COLOR);
Mat img(Size(image.rows,image.cols),CV_8UC3);

mask=imread("/home/joe/Desktop/mask.jpg");
cvtColor(mask,mask,COLOR_BGR2GRAY);
for(int zzz=0;zzz<6;zzz++){
for(int x=0;x<mask.rows;x++){
    for(int y=0;y<mask.cols;y++){
        if(mask.at<uchar>(x,y)>100){
            int sum=image.at<Vec3b>(x,y+1)[0]+image.at<Vec3b>(x+1,y)[0]+image.at<Vec3b>(x+1,y+2)[0]+image.at<Vec3b>(x+2,y+1)[0];
            int sum1=image.at<Vec3b>(x,y+1)[1]+image.at<Vec3b>(x+1,y)[1]+image.at<Vec3b>(x+1,y+2)[1]+image.at<Vec3b>(x+2,y+1)[1];
            int sum2=image.at<Vec3b>(x,y+1)[2]+image.at<Vec3b>(x+1,y)[2]+image.at<Vec3b>(x+1,y+2)[2]+image.at<Vec3b>(x+2,y+1)[2];
           image.at<Vec3b>(x,y)=Vec3b(sum/4,sum1/4,sum2/4);
            img.at<Vec3b>(x,y)=Vec3b(sum/4,sum1/4,sum2/4);
        }
    }
}
}


imshow("ssss",image);
imshow("ssss1",img);
waitKey(0);


}