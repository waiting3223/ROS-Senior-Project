# **灰階圖參數調校GUI介面-藍色轉換成OpenCV之灰階圖的參數調校GUI**

## **圖片呈現**

![藍色貼紙原圖] (Image/Blue%20Sticker%20Original%20Image.png)
![藍色貼紙灰階圖] (Image/Blue%20Sticker%20Grayscale%20Image.png)

## 開發動機
在使用ROS開發小型無人車畢業專題時，我們發現需要一個 GUI 介面來調校藍色轉換成 OpenCV 灰階圖的參數，以便更有效地知道該設定多少參數。

## **開發環境**

* 作業系統環境:Ubuntu 18.04

* CMake最低版本:2.8

* OpenCV函式庫

## **備註**

* 畢業專題時間為2020/8~2021/2，當時未有Git、OO、DisignPatter、Clean Code、正確命名變數名稱、錯誤處理、適當命名變數名稱等等概念，使得videocheck.cpp之code有些雜亂，需重構。只能依當時註解理解當時所寫的內容。

* 此Git存放庫是在畢業專題後建立，故無相關過往紀錄可供查詢

* 請安裝OpenCV函式庫 ,並確保 CMake 能夠找到 OpenCV 函式庫。可在 CMakeLists.txt 文件中使用 ```find_package(OpenCV REQUIRED)``` 指令來確定 CMake 能夠找到 OpenCV。

* videocheck已經是編譯完成的可執行文件(使用CMake編譯)