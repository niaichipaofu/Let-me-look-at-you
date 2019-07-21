#include "Matrix.h"


//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _get_RandMatrix();	
//函数参数：   const int range=[初值范围],const int rows=[所生成矩阵的行], const int cols=[所生成矩阵的列]
//函数功能：
//		获取一个随机的矩阵
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_get_RandMatrix(const int range,const int rows, const int cols)
{
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < rows; i++)
	{
		j_result.clear();
		for (j = 0; j < cols; j++)
		{
			j_result.push_back(rand() % range);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _get_unitMatrix();	
//函数参数：   const int range=[初值],const int rows=[所生成矩阵的行], const int cols=[所生成矩阵的列]
//函数功能：
//		获取一个单位矩阵
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_get_unitMatrix(const int number, const int rows, const int cols)
{
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < rows; i++)
	{
		j_result.clear();
		for (j = 0; j < cols; j++)
		{
			if (i == j)
				j_result.push_back(number);
			else
				j_result.push_back(0);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

Matrix_ Matrix_tool::_get_zeroMatrix(const int rows, const int cols)
{
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < rows; i++)
	{
		j_result.clear();
		for (j = 0; j < cols; j++)
		{
			j_result.push_back(0);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}


//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _get_unitMatrix();	
//函数参数：   const int range=[初值],const int rows=[所生成矩阵的行], const int cols=[所生成矩阵的列]
//函数功能：
//		获取一个指定数值的矩阵
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_get_numMatrix(const int number, const int rows, const int cols)
{
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < rows; i++)
	{
		j_result.clear();
		for (j = 0; j < cols; j++)
		{
			j_result.push_back(number);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

Matrix_ Matrix_tool::_get_Filematrix(const std::string File_path)
{
	int rows = 0, cols = 0,i=0,j=0;
	this->_getfilesize(File_path, &rows, &cols);
	std::ifstream infile(File_path.c_str());
	double num=0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	if (!infile)
	{
		return this->_get_unitMatrix();
	}
	else
	{
		
		for(i=0;i<rows;i++)
		{
			j_result.clear();
			for (j = 0; j < cols; j++)
			{
				infile >> num;
				j_result.push_back(num);
			}
			i_result.push_back(j_result);
			
		}
		
	}
	return i_result;
}

Matrix_ Matrix_tool::_get_Stringmatrix(char* Str, const int M, const int N, char mode)
{
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	switch (mode)
	{
	case 'f':
	{
		float* swap=NULL;
		swap = (float*)malloc(sizeof(float) * M * N+5);
		if (swap == NULL)
			return this->_get_unitMatrix();
		memcpy(swap, Str, M*N*sizeof(float));
		int y = 0;
		for (i = 0; i < M; i++)
		{
			j_result.clear();
			for (j = 0; j < N; j++)
			{
				j_result.push_back(swap[y]);
				//*swap++;
				y++;
				
			}
			i_result.push_back(j_result);
		}

		free(swap);

	}break;
	case 'i':
	{
		int* swap = NULL;
		swap = (int*)malloc(sizeof(int) * M * N+5);
		if (swap == NULL)
			return this->_get_unitMatrix();
		memcpy(swap, Str, M * N * sizeof(int));
		int y = 0;
		for (i = 0; i < M; i++)
		{
			j_result.clear();
			for (j = 0; j < N; j++)
			{
				j_result.push_back(swap[y]);
				y++;

			}
			i_result.push_back(j_result);
		}

		free(swap);
	}break;
	case 'd':
	{
		double* swap = NULL;
		swap = (double*)malloc(sizeof(double) * M * N+5);
		if (swap == NULL)
			return this->_get_unitMatrix();
		else 
			memcpy(swap, Str, M * N * sizeof(double));
		int y = 0;
		for (i = 0; i < M; i++)
		{
			j_result.clear();
			for (j = 0; j < N; j++)
			{
				j_result.push_back(swap[y]);
				y++;

			}
			i_result.push_back(j_result);
		}

		free(swap);
	}break;
	default:
		break;
	}
	return i_result;
}
void Matrix_tool::_get_appointStrmatrix(Matrix_& M_a, char* Str, const int i_rows, const int i_cols,const int size, char mode)
{
	int i = 0, j = 0;
	int m = M_a.size(), n = M_a[0].size();
	if (!Str)
	{
		printf("string error!!\n");
		return;
	}
	if (!M_a.size())
	{
		printf("Matrix error!!\n");
		return;
	}
	if (!size)
		return;
	switch (mode)
	{
	case 'f':
	{
		float* swap = NULL;
		swap = (float*)malloc(sizeof(float)*size + 5);
		if (swap == NULL)
		{
			printf("malloc error\n");
			return;
		}
		else 
			memcpy(swap, Str, size * sizeof(float));
	
		int y = 0;
		if ((i_rows == 0) && (i_cols == 0))
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					M_a[i][j] = swap[y];
					y++;
				}
			}
		}
		else if ((i_rows != 0) && (i_cols == 0))
		{
			for (j = 0; j < n; j++)
			{
				M_a[i_rows-1][j] = swap[y];
				y++;
			}

		}
		else if ((i_rows == 0) && (i_cols != 0))
		{
			for (i = 0; i < m; i++)
			{
				M_a[i][i_cols-1] = swap[y];
				y++;
			}
		}
		else
		{
			M_a[i_rows-1][i_cols-1] = swap[0];
		}
		free(swap);
	}break;
	case 'i':
	{
		int* swap = NULL;
		swap = (int*)malloc(sizeof(int) * size + 5);
		if (swap == NULL)
		{
			printf("malloc error\n");
			return;
		}
		else 
			memcpy(swap, Str, size * sizeof(int));

		int y = 0;
		if ((i_rows == 0) && (i_cols == 0))
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					M_a[i][j] = swap[y];
					y++;
				}
			}
		}
		else if ((i_rows != 0) && (i_cols == 0))
		{
			for (j = 0; j < n; j++)
			{
				M_a[i_rows][j] = swap[y];
				y++;
			}

		}
		else if ((i_rows == 0) && (i_cols != 0))
		{
			for (i = 0; i < m; i++)
			{
				M_a[i][i_cols] = swap[y];
				y++;
			}
		}
		else
		{
			M_a[i_rows][i_cols] = swap[0];
		}
		free(swap);
	}break;
	case 'd':
	{
		double* swap = NULL;
		swap = (double*)malloc(sizeof(double) * size + 5);
		if (swap == NULL)
		{
			printf("malloc error\n");
			return;
		}
		else
			memcpy(swap, Str, size * sizeof(double));

		int y = 0;
		if ((i_rows == 0) && (i_cols == 0))
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					M_a[i][j] = swap[y];
					y++;
				}
			}
		}
		else if ((i_rows != 0) && (i_cols == 0))
		{
			for (j = 0; j < n; j++)
			{
				M_a[i_rows][j] = swap[y];
				y++;
			}

		}
		else if ((i_rows == 0) && (i_cols != 0))
		{
			for (i = 0; i < m; i++)
			{
				M_a[i][i_cols] = swap[y];
				y++;
			}
		}
		else
		{
			M_a[i_rows][i_cols] = swap[0];
		}
		free(swap);
	
	}break;
	case 'u':
	{
		uint32_t* swap = NULL;
		swap = (uint32_t*)malloc(sizeof(uint32_t) * size + 5);
		if (swap == NULL)
		{
			printf("malloc error\n");
			return;
		}
		else
			memcpy(swap, Str, size * sizeof(uint32_t));

		int y = 0;
		if ((i_rows == 0) && (i_cols == 0))
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					M_a[i][j] = swap[y];
					y++;
				}
			}
		}
		else if ((i_rows != 0) && (i_cols == 0))
		{
			for (j = 0; j < n; j++)
			{
				M_a[i_rows - 1][j] = swap[y];
				y++;
			}

		}
		else if ((i_rows == 0) && (i_cols != 0))
		{
			for (i = 0; i < m; i++)
			{
				M_a[i][i_cols - 1] = swap[y];
				y++;
			}
		}
		else
		{
			M_a[i_rows - 1][i_cols - 1] = swap[0];
		}
		free(swap);
	}break;
	default:
		break;
	}
}

/*
Matrix_ Matrix_tool::_get_rowsmatrix(Matrix_& M_a, int i_rows)
{
	Matrix_ i_result;
	std::vector<double> j_result;
	int i = 0;
	if (i_rows > M_a.size())
		i_rows = M_a.size();
	else if (i_rows < 1)
		i_rows = 1;
	i_result.clear();
	j_result.clear();
	for (i = 0; i < M_a[0].size(); i++)
	{
		j_result.push_back(M_a[i_rows-1][i]);
	}
	i_result.push_back(j_result);
	return i_result;
}

Matrix_ Matrix_tool::_get_colsmatrix(Matrix_& M_a,  int i_cols)
{
	Matrix_ i_result;
	std::vector<double> j_result;
	int i = 0;
	if (i_cols > M_a[0].size())
		i_cols = M_a[0].size();
	else if (i_cols < 1)
		i_cols = 1;
	i_result.clear();
	
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		j_result.push_back(M_a[i][i_cols-1]);
		i_result.push_back(j_result);
	}
	
	return i_result;
}
*/

Matrix_ Matrix_tool::_get_appointmatrix(Matrix_& M_a, int i_rows, int i_cols)
{
	if (!M_a.size())
	{
		printf("[Matrix  Error ！]");
		return this->_get_unitMatrix();
	}
	int i = 0, j = 0;
	int m = M_a.size(), n = M_a[0].size();
	if (i_rows < 0)
		i_rows = 0;
	if (i_cols < 0)
		i_cols = 0;
	if (i_rows > m)
		i_rows = m;
	if (i_cols > n)
		i_cols = n;

	if ((i_cols == 0) && (i_rows == 0))
	{
		return M_a;
	}
	
	Matrix_ i_result;
	std::vector<double> j_result;
	

	i_result.clear();
	if (i_cols == 0&&i_rows!=0)
	{
		
			j_result.clear();
			for (j = 0; j < n; j++)
			{
				j_result.push_back(M_a[i_rows-1][j]);
			}
			i_result.push_back(j_result);

	}
	else if (i_rows == 0 && i_cols != 0)
	{
		
		for (i = 0; i < m; i++)
		{
			j_result.clear();
			j_result.push_back(M_a[i][i_cols-1]);
			i_result.push_back(j_result);
		}
	}
	else if (i_rows != 0 && i_cols != 0)
	{
		j_result.clear();
		j_result.push_back(M_a[i_rows-1][i_cols-1]);
		i_result.push_back(j_result);
	}

	return i_result;
}

Matrix_ Matrix_tool::_add_rowsmatrix(Matrix_& M_a,  int i_rows)
{
	Matrix_ i_result;
	std::vector<double> j_result;
	int i = 0, j = 0;
	int m = M_a.size() + 1,n= M_a[0].size();
	if (i_rows > (m - 1))
		i_rows = m;
	if (i_rows < 1)
		i_rows = 1;
	i_result.clear();
	for (i = 0; i <m; i++)
	{
		j_result.clear();
		for (j = 0; j < n; j++)
		{
			if (i == (i_rows-1))
			{
				j_result.push_back(1);
			}
			else
			{
				if (i < (i_rows-1))
				{
					j_result.push_back(M_a[i][j]);
				}
				else if (i > (i_rows-1))
				{
					j_result.push_back(M_a[i-1][j]);
				}
			}
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

Matrix_ Matrix_tool::_add_colsmatrix(Matrix_& M_a,  int i_cols)
{
	Matrix_ i_result;
	std::vector<double> j_result;
	int i = 0, j = 0;
	int m = M_a.size(), n = M_a[0].size()+1;
	if (i_cols > (n-1))
		i_cols = n;
	if (i_cols < 1)
		i_cols = 1;
	i_result.clear();
	for (i = 0; i < m; i++)
	{
		j_result.clear();
		for (j = 0; j < n; j++)
		{
			if (j == (i_cols - 1))
			{
				j_result.push_back(1);
			}
			else
			{
				if (j < (i_cols - 1))
				{
					j_result.push_back(M_a[i][j]);
				}
				else if (j > (i_cols-1))
				{
					j_result.push_back(M_a[i][j-1]);
				}
			}
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

Matrix_ Matrix_tool::_splicingvector(Matrix_& M_a, Matrix_& M_b)
{
	if ((M_a.size() != M_b.size()) && (M_a.size() != M_b.size()))
	{
		return this->_get_unitMatrix();
	}
	Matrix_ i_result;
	std::vector<double> j_result;
	int i = 0, j = 0;
	int m = M_a.size(), n = M_a[0].size();
	i_result.clear();
	for (i = 0; i < m; i++)
	{
		j_result.clear();
		for (j = 0; j < n; j++)
		{
			j_result.push_back(M_a[i][j]);
			j_result.push_back(M_b[i][j]);
		}
		i_result.push_back(j_result);
	}

	return i_result;
}

//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _transposeMatrix();	
//函数参数：   Matrix_& M_a =[输入矩阵]
//函数功能：
//		对输入矩阵进行转置处理
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_transposeMatrix(Matrix_& M_a)
{
	if (!M_a.size())
		return this->_get_unitMatrix();
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a[0].size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_a.size(); j++)
		{
			j_result.push_back(M_a[j][i]);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}


//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _addmatrix();	
//函数参数：  Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
//函数功能：
//		将输入的两个矩阵进行元素相加
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_addmatrix(Matrix_& M_a, Matrix_& M_b)
{
	if ((M_a.size()*M_a[0].size())!=(M_b.size() * M_b[0].size()))
	{
		printf("[Matrix dimension isdifferent ！]");
		return this->_get_unitMatrix();
	}
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_a[0].size(); j++)
		{
			j_result.push_back(M_a[i][j] + M_b[i][j]);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _submatrix();	
//函数参数：  Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
//函数功能：
//		将输入的两个矩阵进行元素相减
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_submatrix(Matrix_& M_a, Matrix_& M_b)
{
	if ((M_a.size() * M_a[0].size()) != (M_b.size() * M_b[0].size()))
	{
		printf("[Matrix dimension isdifferent ！]");
		return this->_get_unitMatrix();
	}
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_a[0].size(); j++)
		{
			j_result.push_back(M_a[i][j] - M_b[i][j]);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _zoommatrix();	
//函数参数：  Matrix_& M_a=[输入的矩阵] const int scale=[缩放的比例]
//函数功能：
//		将输入的元素进行线性缩放缩放
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_zoomlinematrix(Matrix_& M_a, const float scale)
{
	if (!M_a.size())
		return this->_get_unitMatrix();
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_a[0].size(); j++)
		{
			j_result.push_back(M_a[i][j]*scale);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}


Matrix_ Matrix_tool::_zonmnolinematrix(Matrix_& M_a,const int mode,  int i_rows, int i_cols)
{
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	int m = M_a.size(), n = M_a[0].size();
	if (i_rows > m)
		i_rows = m;
	else if (i_rows < 0)
		i_rows = 0;
	if (i_cols > n)
		i_cols = n;
	else if (i_cols < 0)
		i_cols = 0;
	switch (mode)
	{
	case 1:  //sin
	{
		if (i_rows == 0 && i_cols == 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					j_result.push_back(sin(M_a[i][j]));
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows != 0 && i_cols == 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (i == i_rows)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows == 0 && i_cols != 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (j == i_cols)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows != 0 && i_cols != 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (i == i_rows&&j==i_cols)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
	}break;
	case 2:  //cos
	{
		if (i_rows == 0 && i_cols == 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					j_result.push_back(sin(M_a[i][j]));
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows != 0 && i_cols == 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (i == i_rows)
					{
						j_result.push_back(cos(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows == 0 && i_cols != 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (j == i_cols)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows != 0 && i_cols != 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (i == i_rows && j == i_cols)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
	}break;
	case 3:  //exp
	{
		if (i_rows == 0 && i_cols == 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					j_result.push_back(sin(M_a[i][j]));
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows != 0 && i_cols == 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (i == i_rows)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows == 0 && i_cols != 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (j == i_cols)
					{
						j_result.push_back(sin(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
		else if (i_rows != 0 && i_cols != 0)
		{
			for (i = 0; i < m; i++)
			{
				j_result.clear();
				for (j = 0; j < n; j++)
				{
					if (i == i_rows && j == i_cols)
					{
						j_result.push_back(exp(M_a[i][j]));
					}
					else
					{
						j_result.push_back(M_a[i][j]);
					}
				}
				i_result.push_back(j_result);
			}
		}
	}break;
	default:
		break;
	}

	return i_result;
}

Matrix_ Matrix_tool::_zoommulmatrix(Matrix_& M_a, const int scale)
{
	if (!M_a.size())
		return this->_get_unitMatrix();
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_a[0].size(); j++)
		{
			j_result.push_back(pow(M_a[i][j], scale));
		}
		i_result.push_back(j_result);
	}
	return i_result;
}

Matrix_ Matrix_tool::_summatrix(Matrix_& M_a,const int mode)
{
	int i = 0, j = 0, rows = M_a.size(), cols = M_a[0].size();
	double sum_ = 0.0;
	Matrix_ i_result;
	std::vector<double> j_result;
	if (mode == 0)
	{
		sum_ = 0.0;
		i_result.clear();
		j_result.clear();
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				sum_ += M_a[i][j];
			}

		}
		j_result.push_back(sum_);
		i_result.push_back(j_result);
		return i_result;
	}
	else if(mode==1)
	{
		sum_ = 0.0;
		i_result.clear();
		
		for (i = 0; i < rows; i++)
		{
			j_result.clear();
			for (j = 0; j < cols; j++)
			{
				sum_ += M_a[i][j];
			}
			j_result.push_back(sum_);
			sum_ = 0.0;
			i_result.push_back(j_result);
		}
		return i_result;
	}
	else if (mode == 2)
	{
		sum_ = 0.0;
		i_result.clear();

		for (j = 0; j < cols; j++)
		{
			
			for (i = 0; i < rows; i++)
			{
				sum_ += M_a[i][j];
			}
			j_result.push_back(sum_);
			sum_ = 0.0;
			
		}
		i_result.push_back(j_result);
		return i_result;
	}
}

//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _multsMatrix();	
//函数参数：   Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
//函数功能：
//		计算输入的矩阵的矩阵乘积
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_multsMatrix(Matrix_& M_a, Matrix_& M_b)
{
	if (M_a[0].size()!=M_b.size())
	{
		printf("[Matrix dimension isdifferent ！]");
		return this->_get_unitMatrix();
	}
	int i = 0, j = 0,k=0;
	double sum = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_b[0].size(); j++)
		{
			for (k = 0; k < M_a[0].size(); k++)
				sum += M_a[i][k] * M_b[k][j];
			j_result.push_back(sum);
			sum = 0;
		}
		i_result.push_back(j_result);
	}
	return i_result;
}


//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _dotmulsMatrix();	
//函数参数：   Matrix_& M_a, Matrix_& M_b ==[输入的矩阵]
//函数功能：
//		计算输入的矩阵的算术乘积
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_dotmulsMatrix(Matrix_& M_a, Matrix_& M_b)
{
	if((M_a.size()!=M_b.size())||(M_a[0].size() != M_b[0].size()))
	{
		printf("[Matrix dimension isdifferent ！]");
		return this->_get_unitMatrix();
	}
	int i = 0, j = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	for (i = 0; i < M_a.size(); i++)
	{
		j_result.clear();
		for (j = 0; j < M_a[0].size(); j++)
		{
			j_result.push_back(M_a[i][j]*M_b[i][j]);
		}
		i_result.push_back(j_result);
	}
	return i_result;
}


//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _detmatrix();	
//函数参数：   Matrix_ &M_a=[输入方阵] const int size=[方阵的尺寸]
//函数功能：
//		计算输入的方阵的行列式
//----------------------------------------------------------------------------------------------
double Matrix_tool::_detmatrix(Matrix_ &M_a, const int size)
{
	double temp = 0.0;
	int i = 0, j = 0, l = 0;
	Matrix_ i_result;
	std::vector<double> j_result;
	i_result.clear();
	if (size == 2)return M_a[0][0] * M_a[1][1] - M_a[0][1] * M_a[1][0];
	for (i = 0; i < size; i++)
	{
		i_result.clear();
		for (j = 0; j < size - 1; j++)
		{
			j_result.clear();
			for (l = 0; l < size - 1; l++)
			{
				if (l < i)
				{
					j_result.push_back(M_a[j + 1][l]);
				}
				else 
					j_result.push_back(M_a[j + 1][l + 1]);

			}
			i_result.push_back(j_result);

		}
		if (i % 2 == 0) temp += M_a[0][i] * this->_detmatrix(i_result, size - 1);
		else if (i % 2 == 1) temp -= M_a[0][i] * this->_detmatrix(i_result, size - 1);
	}

	return temp;
}

//----------------------------------------------------------------------------------------------
//函数声明：Matrix_ _Inversematrix();	
//函数参数：   Matrix_ &M_a=[输入方阵]
//函数功能：
//		计算输入的方阵的逆矩阵
//----------------------------------------------------------------------------------------------
Matrix_ Matrix_tool::_Inversematrix(Matrix_& M_a)
{
	int i, j, k;
	int n = M_a.size();
	double max, temp;
	              
	Matrix_ swap = this->_get_unitMatrix(1,n,n);							  //将 A 矩阵存放在临时矩阵 t [ n ] [ n ] 中  
	Matrix_ result = this->_get_unitMatrix(1, n, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			swap[i][j] = M_a[i][j];
		}
	}
	//初始化 B 矩阵为单位阵  
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			result[i][j] = (i == j) ? (double)1 : 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		//寻找主元  
		max = swap[i][i];
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (fabs(swap[j][i]) > fabs(max))
			{
				max = swap[j][i];
				k = j;
			}
		}
		//如果主元所在行不是第 i 行，进行行交换  
		if (k != i)
		{
			for (j = 0; j < n; j++)
			{
				temp = swap[i][j];
				swap[i][j] = swap[k][j];
				swap[k][j] = temp;
				//result伴随交换  
				temp = result[i][j];
				result[i][j] = result[k][j];
				result[k][j] = temp;
			}
		}
		//判断主元是否为 0 , 若是, 则矩阵 A 不是满秩矩阵,不存在逆矩阵  
		if (swap[i][i] == 0)
		{
			printf("There is no inverse matrix!\n");
			return this->_get_unitMatrix();
		}
		//消去A的第i列除去i行以外的各行元素  
		temp = swap[i][i];
		for (j = 0; j < n; j++)
		{
			swap[i][j] = swap[i][j] / temp;        //主对角线上的元素变为1  
			result[i][j] = result[i][j] / temp;        //伴随计算  
		}
		for (j = 0; j < n; j++)        //第 0 行 - > 第 n 行  
		{
			if (j != i)                //不是第 i 行  
			{
				temp = swap[j][i];
				for (k = 0; k < n; k++)        //第 j 行元素  -  i 行元素 * j 列 i 行元素  
				{
					swap[j][k] = swap[j][k] - swap[i][k] * temp;
					result[j][k] = result[j][k] - result[i][k] * temp;
				}
			}
		}
	}
	return result;
}

//----------------------------------------------------------------------------------------------
//函数声明：void _printmatrix();	
//函数参数：   Matrix_ &M_a=[输入矩阵]
//函数功能：
//		打印矩阵中的内容
//----------------------------------------------------------------------------------------------
void Matrix_tool::_printmatrix(Matrix_& M_a)
{
	int i = 0, j = 0,m=M_a.size(),n=M_a[0].size();
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("[%lf] ", M_a[i][j]);
		}
		printf("\n");
	}
}

void Matrix_tool::_getfilesize(std::string File_path, int* rows, int* cols)
{
	std::ifstream infile(File_path.c_str());
	double num = 0;
	int i = 0;
	std::string a;
	char str[100];
	if (!infile)
	{
		printf("[open file fail!]\n");
		return;
	}
	else
	{
		while (!infile.eof())
		{
			infile.getline(str, 100);
			i++;
		}
		*rows=i;
		*cols = this->_getStrNumLen(str);
	}
}

int Matrix_tool::_getStrNumLen(char* str)
{
	int i_num = 0;
	while (*str++)
	{
		if (*str == ' ')
			i_num++;
	}
	
	if (*str== ' ')
		return i_num;
	else
		return i_num + 1;
}

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

