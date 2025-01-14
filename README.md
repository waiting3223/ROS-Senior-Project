# **灰階圖參數調校GUI-藍色照片轉換成OpenCV之灰階圖的參數調校GUI**

## **開發動機**
在使用ROS開發小型無人車畢業專題時，我們發現需要一個 GUI 介面來調校藍色轉換成 OpenCV 灰階圖的參數，以便更有效地知道該設定參數值。

## **開發環境**

* 作業系統環境 : Ubuntu 20.04

* CMake版本 : 3.29.5-msvc4

* ROS : Noetic Version*

* OpenCV函式庫

## **圖片呈現**

![藍色貼紙原圖](Image/Blue%20Sticker%20Original%20Image.png)

![藍色貼紙灰階圖](Image/Blue%20Sticker%20Grayscale%20Image.png)

## **備註**

* 畢業專題時間為2020/8~2021/2，當時未有Git、OO、DisignPatter、Clean Code、正確命名變數名稱、錯誤處理、適當命名變數名稱等等概念，使得videocheck.cpp之code有些雜亂，需重構。只能依當時註解理解當時所寫的內容。

* 此Git存放庫是在畢業專題後建立，故無相關過往紀錄可供查詢

* 本專案使用CMake進行編譯，請使用```cmake .```指令進行編譯

* 請安裝OpenCV函式庫 ,並確保 CMake 能夠找到 OpenCV 函式庫。可在 CMakeLists.txt 文件中使用 ```find_package(OpenCV REQUIRED)``` 指令來確認 CMake 能否找到 OpenCV。
  若無法找到，請手動配置OpenCV路徑

* 本專案使用ROS,請使用ROS的Noetic版本*

* videocheck未完成,無法使用CMake編譯
