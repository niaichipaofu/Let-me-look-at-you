CXX=g++
Objects=_Uart.o main.o Matrix.o
exe:$(Objects)
	g++  $(Objects) -o exe
_Uart.o:_Uart.cc 
	g++ -c _Uart.cc  -o _Uart.o 
Matrix.o:Matrix.cc 
	g++ -c Matrix.cc  -o Matrix.o 
main.o:main.cpp 
	g++ -c main.cpp -o main.o