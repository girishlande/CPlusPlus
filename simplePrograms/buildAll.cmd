mkdir build
pushd build
cmake ../
cmake --build .
pushd debug
factorial.exe
pause
autotest.exe
popd
popd
