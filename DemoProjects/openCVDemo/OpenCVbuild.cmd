@echo off

setlocal 

mkdir repos
pushd repos

mkdir opencv
pushd opencv

mkdir source

git clone https://github.com/opencv/opencv.git source

pushd source
git checkout 3.4
popd

mkdir build
pushd build
cmake -DBUILD_SHARED_LIBS:BOOL=ON ../source
cmake --build . --target ALL_BUILD --config debug
cmake --build . --target INSTALL --config debug

popd
popd
popd

endlocal 