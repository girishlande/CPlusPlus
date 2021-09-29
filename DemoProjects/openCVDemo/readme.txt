This project will show how to use openCV for simple display of image. 

It mainly focuses on how to use openCV using cmake. 

1. buildOpenCV.cmd will download openCV source code and build it. 
2. buildproject.cmd will build this current project .
	you may have to tweak paths in cmake file for finding openCV
	
3. run.cmd will run project by passing one image in data folder 


Note : To use opencv or any third party library you need to do the following

1. Download source code from their website 
2. Create folder in C:\thirdparty with library name
3. Create source folder inside this folder
4. copy source code of thirdparty library 
5. Create build folder 
6. Create install folder (for debug libraries)
7. create intallr folder(for release libraries)
8. Use some script as follows to build the library in debug and release. 
9. Install folder will have its header and libraries 

Use following code in CmakeLists.txt to refer to this third party library
set (CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" "C:/Thirdparty/opencv/build/install/x64/vc16/lib/")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( MyProject ${OpenCV_LIBS} )


Sample Script to build third party library in debug and release mode and create install folder 

@echo off

setlocal 

mkdir opencv
pushd opencv

mkdir source
mkdir install
mkdir installr

git clone https://github.com/opencv/opencv.git source

pushd source
git checkout 3.4
popd

mkdir build
pushd build
cmake -DBUILD_SHARED_LIBS:BOOL=ON -DCMAKE_INSTALL_PREFIX:PATH=C:/ThirdParty/opencv/installd ../source
cmake --build . --target ALL_BUILD --config debug
cmake --build . --target INSTALL --config debug

cmake -DBUILD_SHARED_LIBS:BOOL=ON -DCMAKE_INSTALL_PREFIX:PATH=C:/ThirdParty/opencv/installr ../source
cmake --build . --target ALL_BUILD --config release
cmake --build . --target INSTALL --config release

cmake -DBUILD_SHARED_LIBS:BOOL=ON -DCMAKE_INSTALL_PREFIX:PATH=C:/ThirdParty/opencv/install ../source
cmake --build . --target INSTALL --config debug
cmake --build . --target INSTALL --config release

popd
popd
popd

endlocal 