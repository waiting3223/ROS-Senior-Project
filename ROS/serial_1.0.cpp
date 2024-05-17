// C library headers
#include <stdio.h>
#include <string.h>

//readom headers
#include <stdlib.h>
#include <iostream>
#include <time.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

//ros headers
#include <ros/ros.h>
#include <std_msgs/Int16.h>

using namespace std;
using namespace ros;
using namespace std_msgs;



///////////////////////////////////////////////////////////////////
//////////////////////////序列扈////////////////////////////////////////////////此程式碼為未加入紅色判斷,位置判斷,車頭方向 只有藍色,超音波
///////////////////////////////////////////////////////////////////

///////////////////
/////開啟序列扈////
//////////////////
int serial_port;		//變數for void OpenSerial()
struct termios tty;
char SerialPort[]="/dev/ttyUSB0";

void OpenSerial(void){  

  serial_port = open(SerialPort, O_RDWR);

  if(tcgetattr(serial_port, &tty) != 0) {
      printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
      
  }

  tty.c_cflag &= ~PARENB; 
  tty.c_cflag &= ~CSTOPB; 
  tty.c_cflag &= ~CSIZE; 
  tty.c_cflag |= CS8; 
  tty.c_cflag &= ~CRTSCTS; 
  tty.c_cflag |= CREAD | CLOCAL; 

  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO; 
  tty.c_lflag &= ~ECHOE; 
  tty.c_lflag &= ~ECHONL; 
  tty.c_lflag &= ~ISIG; 
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); 
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); 

  tty.c_oflag &= ~OPOST; 
  tty.c_oflag &= ~ONLCR; 

  tty.c_cc[VTIME] = 90;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  
  cfsetispeed(&tty, B9600);
  cfsetospeed(&tty, B9600);

 
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  } else{cout<<"Open Serial:"<<SerialPort<<endl;}
}

///////////////////
/////讀取序列扈////
//////////////////
char read_buf [256];		//變數for void ReadSerial()
int num_bytes;
int read_arry=num_bytes-1;

void ReadSerial(void)
{
  
  num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
  if (num_bytes < 0) {
      printf("Error9 reading: %s", strerror(errno));
  }
  
  printf("Read %i bytes. Received message: %s\n", num_bytes, read_buf);
  
}


///////////////////
/////隨機給亂術////
//////////////////
unsigned int msg;
void ReadonChoice(void){
  srand((unsigned)time(NULL));
  msg=rand()%3;
  

  if(msg==1){
  write(serial_port,"1",sizeof(msg));
  cout<<endl;
  cout<<"傳送右轉指令"<<endl;
  }

  if(msg==2){
  write(serial_port,"2",sizeof(msg));
  cout<<endl;
  cout<<"傳送直走指令"<<endl;
  }

  if(msg==0){
  write(serial_port,"0",sizeof(msg));
  cout<<endl;
  cout<<"傳送左轉指令"<<endl;
  }
}



///////////////////////////
/////隨機給亂術for超音波////
///////////////////////////
unsigned int MSG;
void ReadonChoiceForUl(void){
  srand((unsigned)time(NULL));
  MSG=rand()%2;
  

  if(MSG==1){
  write(serial_port,"1",sizeof(MSG));
  cout<<endl;
  cout<<"因前方有障礙物 傳送右轉指令"<<endl;
  }

  

  if(MSG==0){
  write(serial_port,"0",sizeof(MSG));
  cout<<endl;
  cout<<"因前方有障礙物 傳送左轉指令"<<endl;
  }
}

//////////////////
/////關閉序列扈////
//////////////////
void CloseSerial(void)
{
  cout<<"CLose Serial:"<<SerialPort<<endl;
	for(int i=0;i<255;i++){read_buf[i]=' ';}
	
	
  close(serial_port);
}
///////////////////////////////////////////////////////////////////
//////////////////////////ROS//////////////////////////////////////
///////////////////////////////////////////////////////////////////
int blue=0;
void Blue_staue(const Int16& blue_number)
{
	
	
	if(blue_number.data==0)
	{
		blue=0;
	}

	if(blue_number.data==2&&blue==0)
	{
		blue++;
	}
}

int red=0;
void Red_staue(const Int16& red_number)
{
	
	
	if(red_number.data==0)
	{
		red=0;
	}

	if(red_number.data==1)
	{
		red++;
	}
}


int main(int argc,char **argv)
{
  init(argc,argv,"PI4");
  NodeHandle n;
  srand((unsigned)time(NULL));
  bool ul=0;

  Rate loop_rate(1);
  
  Subscriber blue_number_check=n.subscribe("blue_staue",1,Blue_staue);
  Subscriber red_number_check=n.subscribe("red_staue",1,Red_staue);
  int turn=0;

 
 while(1)
 {		
  spinOnce();

	if(blue==0&&turn==0)             ///////未找到藍色及超音波沒問題
	{

		cout<<"未找到藍色"<<blue<<endl;
		
		OpenSerial();
		ReadonChoice();
		//while(1)
		//{
			ReadSerial();
			cout<<"讀取中"<<endl;
			/*if(read_buf[0]=='s')	//////若收到s即超音波有問題
			{
				ReadonChoiceForUl();
				ReadSerial();
				if(read_buf[0]=='x'){

				}
			}*/

			if(read_buf[0]=='0')
			{
				cout<<"Arduino確認收到指令 指令為左轉"<<endl;
				turn=1;
				CloseSerial();
				//break;
  			}

			if(read_buf[0]=='1')
			{
				cout<<"Arduino確認收到指令 指令為右轉"<<endl;
				turn=1;
				CloseSerial();
				//break;
	  		}

			if(read_buf[0]=='2')
			{
				cout<<"Arduino確認收到指令 指令為直走"<<endl;
				CloseSerial();
				//break;
			}

			if(read_buf[0]=='2')
			{
				cout<<"Arduino確認收到指令 指令為直走"<<endl;
				CloseSerial();
				//break;
			}

              		        
		//}
	
	}

	if(blue==0&&turn==1)             ///////未找到藍色及超音波沒問題且已經轉彎
	{
	OpenSerial();
	write(serial_port,"2",sizeof(msg));
	ReadSerial();
	if(read_buf[0]=='2')
			{
				cout<<"因已經轉彎故Arduino確認收到指令 指令為直走"<<endl;
				turn=0;
				CloseSerial();
				//break;
			}
	}

	if(blue==1)		///找到藍色
	{
		int sa=2;
		
		OpenSerial();
		write(serial_port,"3",sizeof(sa));
		CloseSerial();

		cout<<"已找到藍色並傳送停車訊號"<<endl;
		blue++;
		break;
	}


	
 loop_rate.sleep();
 }

  return 0; // success
}

