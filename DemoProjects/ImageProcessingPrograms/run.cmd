@echo off

pushd build
pushd debug

for /r %%i in (*.exe) do (
  call %%i
)

popd
popd