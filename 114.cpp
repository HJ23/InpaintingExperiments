#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#define im_path "/home/joe/Desktop/defect2.jpg"
#define mask_path "/home/joe/Desktop/mask.jpg"
using namespace std;
using namespace cv;
Mat image,mask,img;
void hor(int x,int y){
    for(int kk=0;kk<image.rows;kk++){
        if(mask.at<uchar>(kk,y)>200){
            image.at<Vec3b>(kk,y)=image.at<Vec3b>(kk-1,y);
            img.at<Vec3b>(kk,y)=image.at<Vec3b>(kk-1,y);
            mask.at<uchar>(kk,y)=0;
            break;
        }
    }
     for(int kk=image.rows-1;-1<kk;kk--){

        if(mask.at<uchar>(kk,y)>200){
            image.at<Vec3b>(kk,y)=image.at<Vec3b>(kk+1,y);
            img.at<Vec3b>(kk,y)=image.at<Vec3b>(kk+1,y);
            mask.at<uchar>(kk,y)=0;
            break;
        }
    }

}
void ver(int x ,int y){
 for(int kk=0;kk<image.cols;kk++){
        if(mask.at<uchar>(x,kk)>200){
            image.at<Vec3b>(x,kk)=image.at<Vec3b>(x,kk-1);
            img.at<Vec3b>(x,kk)=image.at<Vec3b>(x,kk-1);
            mask.at<uchar>(x,kk)=0;
            break;
        }
    }
     for(int kk=image.cols-1;-1<kk;kk--){

        if(mask.at<uchar>(x,kk)>200){
            image.at<Vec3b>(x,kk)=image.at<Vec3b>(x,kk+1);
            img.at<Vec3b>(x,kk)=image.at<Vec3b>(x,kk+1);
            mask.at<uchar>(x,kk)=0;
            break;
        }
    }

}




int main(){
image=imread(im_path);
mask=imread(mask_path);
img=Mat::zeros(Size(image.cols,image.rows),CV_8UC3);
cvtColor(mask,mask,COLOR_BGR2GRAY);
threshold(mask,mask,220,255,THRESH_BINARY);
vector<bool> change(mask.rows);  // true for horizontal false for vertical
  for(int x=0;x<mask.rows;x++){
      int tt_w=0,tt_b=0;
      for(int y=0;y<mask.cols;y++){
          if(mask.at<uchar>(x,y)>200){
            tt_w++;
          }
          else{
              tt_b++;
          }
      }
      if(((tt_w/tt_b)*100)>20){
           change[x]=true;
      }
      else{
          change[x]=false;
      }
  }

 

   for(int zzz=0;zzz<1;zzz++){
for(int x=0;x<image.rows;x++){
    for(int y=0;y<image.cols;y++){

    
    if(change[x]){
        hor(x,y);
    }
    else{
        ver(x,y);
    }

    }}
   }
   GaussianBlur(image,image,Size(3,3),1);

imshow("ssss",image);
imshow("ssss1",img);
waitKey(0);



}