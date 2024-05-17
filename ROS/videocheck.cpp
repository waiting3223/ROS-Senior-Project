#include <iostream>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <sstream>

using namespace cv;
using namespace std;

Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
	
Mat frame1;Mat frame2,frame3;         //相機Mat
Mat Hsv,Blur,GB;                      //RGB2HSV Mat,濾波 Mat
Mat ing;                              //藍色區域Mat

int h1=100;int h2=130;                //初始化最小與最大選取藍色範圍
int s1=90;int s2=255;
int v1=60;int v2=255;




void on_Trackbar(int,void*);          //初始化回呼函數

vector<vector<Point> > contours;      //初始化向量
vector<Vec4i> hierarchy;

                                      //////////
int main(int argc,char** argv)        /*主函數*/
{                                     /////////
VideoCapture cap(0);                  //定義物件與設定相機
ros::init(argc,argv,"camera");
ros::NodeHandle n;
ros::Publisher blue_thing_object=n.advertise<std_msgs::Int16>("blue",1);
std_msgs::Int16 blue_thing;
blue_thing.data=0;
ros::Rate stoptime(1.0);


if(blue_thing.data==0){
	while(1)
	{
	cap>>frame1;                                                                           //獲得相機Mat
	imshow("相機",frame1);

	morphologyEx(frame1,frame2,CV_MOP_OPEN,element);						//腐蝕膨脹運算
	morphologyEx(frame2,frame3,CV_MOP_CLOSE,element);
	

	GaussianBlur(frame3,GB,Size(15,15),0,0);                                                        //濾波
	blur(GB,Blur,Size(15,15));
	cvtColor(GB,Hsv,CV_BGR2HSV);                                                                 //轉色彩空間
	
	cvNamedWindow(" ",1);                                                                        //建立名為" "的視窗
	createTrackbar("最小彩度"," ",&h1,255,on_Trackbar);                                          //建立各個滑軌條
	createTrackbar("最小飽和度"," ",&s1,255,on_Trackbar);
	createTrackbar("最小亮度"," ",&v1,255,on_Trackbar);
	createTrackbar("最大彩度"," ",&h2,255,on_Trackbar);
	createTrackbar("最大飽和度"," ",&s2,255,on_Trackbar);
	createTrackbar("最大亮度"," ",&v2,255,on_Trackbar);
	inRange(Hsv,Scalar(h1,s1,v1),Scalar(h2,s2,v2),ing);                                          //選取藍色範圍
	imshow(" ",ing);
	
	findContours(ing,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);                  //計算面積
	for ( unsigned int i = 0;  i < contours.size();  i++)
	{
	if(contourArea(contours[i])>50000&&blue_thing.data==0)
	{
	cout<< " i= "<<i<<endl;
	cout << " Area: " << contourArea(contours[i]) << endl;
	blue_thing.data=1;
	blue_thing_object.publish(blue_thing);
	}
	
	}
	if(waitKey(100)==27){break;}                                                                  //按Esc離開

	
	}
}
if(blue_thing.data==1){
blue_thing_object.publish(blue_thing);
stoptime.sleep();


}
return 0;
}


                                                                                      ////////////
void on_Trackbar(int,void*)                                                           /*回呼函數*/                                                   
{                                                                                     ////////////
if(h1<h2&&s1<s2&&v1<v2)
{
h1=getTrackbarPos("最小彩度"," ");                                                                   //讀取各個滑軌條數值
s1=getTrackbarPos("最小飽和度"," ");
v1=getTrackbarPos("最小亮度"," ");
h2=getTrackbarPos("最大彩度"," ");
s2=getTrackbarPos("最大飽和度"," ");
v2=getTrackbarPos("最大亮度"," ");

}


}

