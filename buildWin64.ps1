dir  
cd c:/
Invoke-WebRequest -Uri "https://github.com/rorywalsh/cabbage/releases/download/v2.0.00/csound-windows_x64-6.13.0.zip" -OutFile "C:\csound-windows_x64-6.12.0.zip" 
7z.exe x csound-windows_x64-6.12.0.zip -o"C:/Program Files"
cd "C:/Program Files/Csound6_x64"
dir
cd c:/
cd D:/a/1/s/

mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" ..
make 


Copy-Item "D:/a/1/s/build/Release/*" -Destination D:/a/1/a/*

