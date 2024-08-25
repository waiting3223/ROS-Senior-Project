## **開發環境**

* 作業系統環境 : Ubuntu 20.04
* CMake版本 : 3.16.3
* ROS : Noetic Version
* OpenCV函式庫

## **備註**

* 本專案使用 ROS，請使用 ROS 的 Noetic 版本。
* 若要使用 CMake，我是利用 WSL 遠端創立 Ubuntu 環境建制的。請按照以下步驟操作：

	1. 移動到 `build` 資料夾：
	``` cd build ```
	
	2. 生成 CMake 相關文件 :
	``` cmake .. ```
	
	3. 等候CMake完成後編譯專案:
	```cmake --build .```