#include <opencv2/opencv.hpp>
#include <std_msgs/Int16.h>
#include <ros/ros.h>
#include <sstream>
#include <iostream>
using namespace std;
using namespace cv;

Mat frame1,frame2,frame3;
Mat Hsv,Blur,GB;
Mat ing,Ing; 
Mat element=getStructuringElement(MORPH_RECT,Size(15,15));

vector<vector<Point> > contours;      //初始化藍色向量
vector<Vec4i> hierarchy;

vector<vector<Point> > Contours;      //初始化紅色向量
vector<Vec4i> Hierarchy;

int h1=100;int h2=130;                //初始化最小與最大選取藍色範圍
int s1=90;int s2=255;
int v1=160;int v2=255;

int H1=140;int H2=180;                //初始化最小與最大選取紅色範圍
int S1=90;int S2=255;
int V1=160;int V2=255;

int main(int argc,char** argv) 
{
VideoCapture cap(0);
ros::init(argc,argv,"color_finder");
std_msgs::Int16 red_thing;
std_msgs::Int16 blue_thing;
red_thing.data=0;
blue_thing.data=0;

std_msgs::Int16 car_number;
car_number.data=0;


ros::NodeHandle n;

ros::Publisher red_thing_object=n.advertise<std_msgs::Int16>("red_staue",1);
ros::Publisher blue_thing_object=n.advertise<std_msgs::Int16>("blue_staue",1);
ros::Publisher Car=n.advertise<std_msgs::Int16>("TheMovingCar",1);
cout<<"尋找藍色中"<<endl;

while(1)
{
	
	cap>>frame1;
	morphologyEx(frame1,frame2,CV_MOP_OPEN,element);					//腐蝕膨脹運算
	morphologyEx(frame2,frame3,CV_MOP_CLOSE,element);
	GaussianBlur(frame3,GB,Size(15,15),0,0);                                                //濾波
	blur(GB,Blur,Size(15,15));
	cvtColor(Blur,Hsv,CV_BGR2HSV);
	imshow("相機",frame1);
	if(blue_thing.data==0)
		{
			inRange(Hsv,Scalar(H1,S1,V1),Scalar(H2,S2,V2),Ing);					//將紅色存入Ing
			imshow("red_finder",Ing);
			findContours(Ing,Contours,Hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
			int ss=-1;

			for ( unsigned int s = 0;  s < Contours.size();  s++)
			{
				if(contourArea(Contours[s])>50000&&red_thing.data==0)
				{
				cout<< " s= "<<s<<endl;
				cout << " Area: " << contourArea(Contours[s]) << endl;
				red_thing.data=1;
				}

				if(contourArea(Contours[s])<50000&&red_thing.data==1)
				{
					ss++;
				
					if(ss==s)
					{
						red_thing.data=0;
					}
				}	
	
			}
			red_thing_object.publish(red_thing);

			inRange(Hsv,Scalar(h1,s1,v1),Scalar(h2,s2,v2),ing);                                          //選取藍色範圍
			imshow("blue_finder",ing);
	
			findContours(ing,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);                  //計算面積	
	
			for ( unsigned int i = 0;  i < contours.size();  i++)
			{
				if(contourArea(contours[i])>50000&&blue_thing.data==0)
				{
					cout<< " i= "<<i<<endl;
					cout << " Area: " << contourArea(contours[i]) << endl;
					blue_thing.data=1;
				}
	
			}
		

			blue_thing_object.publish(blue_thing);
		
		

			if(waitKey(1)==27)
			{
				cvDestroyAllWindows();
				cap.release();
				break;
			}
		}  



	if(blue_thing.data==1)
	{
		cvDestroyWindow("blue_finder");
		blue_thing.data=2;
	}


	if(blue_thing.data==2)
	{
		cout<<"已找到藍色"<<endl;
		inRange(Hsv,Scalar(H1,S1,V1),Scalar(H2,S2,V2),Ing);					//將紅色存入Ing
		imshow("red_finder",Ing);
		findContours(Ing,Contours,Hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
		int ss=-1;
	
		for ( unsigned int s = 0;  s < Contours.size();  s++)
		{
			if(contourArea(Contours[s])>50000&&red_thing.data==0)
			{
				cout<< " s= "<<s<<endl;
				cout << " Area: " << contourArea(Contours[s]) << endl;
				red_thing.data=1;
			}

			if(contourArea(Contours[s])<50000&&red_thing.data==1)
			{
				ss++;
				
				if(ss==s)
				{
					red_thing.data=0;
				}
			}	
	
		}
		
		red_thing_object.publish(red_thing);

		blue_thing_object.publish(blue_thing);
		if(waitKey(1)==27)
		{
			cvDestroyAllWindows();
			cap.release();
			break;
		}
	}

}
	return 0;       

}
