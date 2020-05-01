This project is for Image detection library

It generates library dll. 
It is tested using main method. 

Dependencies are 

cmake
dcmtk 
visual studio 

Steps to build and run this project

1. Make sure you have cmake installed on your system 
2. open command prompt in administrator mode
3. Fire command builddcmtk.cmd
    >> this should create repos folder . Inside that it should create dcmtk. 
	It will clone dcmtk source code from internet and will build this source code. 
	It will install this library in your system at C:\program files(x86)\dcmtk
	
	If this command fails then your project won't work
	
4. Now, Fire doEverything.cmd 
  >> This command will build your project (library and main application)
  >> library will generate dll file. main will test this library functions. 
  
  