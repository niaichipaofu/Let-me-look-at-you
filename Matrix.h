
//----------------------------------------------------------------------------
//   Matrix自用类                                                v1.0
//   作者 ： yk
//----------------------------------------------------------------------------
//
//   email:  iamabirdyk219@gmail.com
//
//
//----------------------------------------------------------------------------
//   说明：
//     该Matrix类只是本人为使用方便而进行编写。由于知识有限，所编写的程序必定存在很大问
//   题。如发现问题请联系我，互相学习交流。在此谢过。本人将不断对其优化。
//   
//
//
//   v1.0 JUN 2019
//  
//----------------------------------------------------------------------------


#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<fstream>
typedef std::vector<std::vector<double>> Matrix_;



class Matrix_tool
{
public:
	Matrix_tool() 
		:MAX(10000),MIN(-10000),Max(1000)
	{};
	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _get_RandMatrix();	
	//函数参数：   const int range=[初值范围],const int rows=[所生成矩阵的行], const int cols=[所生成矩阵的列]
	//函数功能：
	//		获取一个随机的矩阵
	//----------------------------------------------------------------------------------------------
	Matrix_  _get_RandMatrix(const int range = 10,const int rows = 3, const int cols = 3);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _get_unitMatrix();	
	//函数参数：   const int range=[初值],const int rows=[所生成矩阵的行], const int cols=[所生成矩阵的列]
	//函数功能：
	//		获取一个单位矩阵
	//----------------------------------------------------------------------------------------------
	Matrix_  _get_unitMatrix(const int number = 1, const int rows = 3, const int cols = 3);


	Matrix_  _get_zeroMatrix(const int rows = 3, const int cols = 3);
	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _get_unitMatrix();	
	//函数参数：   const int range=[初值],const int rows=[所生成矩阵的行], const int cols=[所生成矩阵的列]
	//函数功能：
	//		获取一个指定数值的矩阵
	//----------------------------------------------------------------------------------------------
	Matrix_  _get_numMatrix(const int number = 1, const int rows = 3, const int cols = 3);

	Matrix_  _get_Filematrix(const std::string File_path = "mat.txt");
	Matrix_  _get_Stringmatrix(char* Str, const int M = 3, const int N = 3, char mode = 'f');
	void     _get_appointStrmatrix(Matrix_& M_a, char* Str, const int i_rows = 0, const int i_cols = 0, const int size=0, char mode = 'f');
	//Matrix_  _get_rowsmatrix(Matrix_& M_a, int i_rows=1);
	//Matrix_  _get_colsmatrix(Matrix_& M_a, int i_cols=1);
	Matrix_  _get_appointmatrix(Matrix_& M_a, int i_rows = 0, int i_cols = 0);
	Matrix_  _add_rowsmatrix(Matrix_& M_a,  int i_rows = 1);
	Matrix_  _add_colsmatrix(Matrix_& M_a,  int i_cols = 1);

	Matrix_ _splicingvector(Matrix_& M_a, Matrix_& M_b);  //拼接向量
	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _transposeMatrix();	
	//函数参数：   Matrix_& M_a =[输入矩阵]
	//函数功能：
	//		对输入矩阵进行转置处理
	//----------------------------------------------------------------------------------------------
	Matrix_  _transposeMatrix(Matrix_& M_a);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _addmatrix();	
	//函数参数：  Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
	//函数功能：
	//		将输入的两个矩阵进行元素相加
	//----------------------------------------------------------------------------------------------
	Matrix_  _addmatrix(Matrix_ & M_a,Matrix_ & M_b);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _addmatrix();	
	//函数参数：  Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
	//函数功能：
	//		将输入的两个矩阵进行元素相减
	//----------------------------------------------------------------------------------------------
	Matrix_  _submatrix(Matrix_& M_a, Matrix_& M_b);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _zoommatrix();	
	//函数参数：  Matrix_& M_a=[输入的矩阵] const int scale=[缩放的比例]
	//函数功能：
	//		将输入的元素进行线性缩放缩放
	//----------------------------------------------------------------------------------------------
	Matrix_  _zoomlinematrix(Matrix_& M_a, const float scale = 2);

	Matrix_  _zonmnolinematrix(Matrix_& M_a, const int mode=1,  int i_rows = 0, int i_cols = 0);

	Matrix_  _zoommulmatrix(Matrix_& M_a, const int scale = 2);

	Matrix_  _summatrix(Matrix_& M_a,const int mode=0);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _multsMatrix();	
	//函数参数：   Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
	//函数功能：
	//		计算输入的矩阵的矩阵乘积
	//----------------------------------------------------------------------------------------------
	Matrix_  _multsMatrix(Matrix_& M_a, Matrix_& M_b);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _dotmulsMatrix();	
	//函数参数：   Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
	//函数功能：
	//		计算输入的矩阵的算术乘积
	//----------------------------------------------------------------------------------------------
	Matrix_  _dotmulsMatrix(Matrix_& M_a, Matrix_& M_b);

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _detmatrix();	
	//函数参数：   Matrix_ &M_a=[输入方阵] const int size=[方阵的尺寸]
	//函数功能：
	//		计算输入的方阵的行列式
	//----------------------------------------------------------------------------------------------
	double   _detmatrix(Matrix_ &M_a,const int size );

	//----------------------------------------------------------------------------------------------
	//函数声明：Matrix_ _Inversematrix();	
	//函数参数：   Matrix_ &M_a=[输入方阵]
	//函数功能：
	//		计算输入的方阵的逆矩阵
	//----------------------------------------------------------------------------------------------
	Matrix_  _Inversematrix(Matrix_& M_a);


	//----------------------------------------------------------------------------------------------
	//函数声明：void _printmatrix();	
	//函数参数：   Matrix_ &M_a=[输入矩阵]
	//函数功能：
	//		打印矩阵中的内容
	//----------------------------------------------------------------------------------------------
	void     _printmatrix(Matrix_& M_a);
	
	~Matrix_tool() {};

private:
	const int MAX;
	const int MIN;
	const int Max;
	void     _getfilesize(std::string File_path, int* rows, int* cols);
	int      _getStrNumLen(char* str);
};



#endif // !MATRIX_H

//----------------------------------------------------------------------------
//   Matrix自用类                                                v1.0
//   作者 ： yk
//----------------------------------------------------------------------------
//
//   email:  iamabirdyk219@gmail.com
//
//
//----------------------------------------------------------------------------
//   说明：
//     该Matrix类只是本人为使用方便而进行编写。由于知识有限，所编写的程序必定存在很大问
//   题。如发现问题请联系我，互相学习交流。在此谢过。本人将不断对其优化。
//   
//
//
//   v1.0 JUN 2019
//  
//----------------------------------------------------------------------------

