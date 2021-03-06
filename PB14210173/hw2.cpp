#include "opencv2\opencv.hpp"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <ctime>

#define MY_OK 1
#define MY_FAIL 0
#define MY_PI 3.1415926
#define MY_LENGTH 30000

using namespace cv;
using namespace std;

float my_sin[] = { 0.000000, 0.017452, 0.034899, 0.052336, 0.069756, 0.087156, 0.104528, 0.121869, 0.139173, 0.156434,
0.173648, 0.190809, 0.207912, 0.224951, 0.241922, 0.258819, 0.275637, 0.292372, 0.309017, 0.325568,
0.342020, 0.358368, 0.374607, 0.390731, 0.406737, 0.422618, 0.438371, 0.453990, 0.469472, 0.484810,
0.500000, 0.515038, 0.529919, 0.544639, 0.559193, 0.573576, 0.587785, 0.601815, 0.615661, 0.629320,
0.642788, 0.656059, 0.669131, 0.681998, 0.694658, 0.707107, 0.719340, 0.731354, 0.743145, 0.754710,
0.766044, 0.777146, 0.788011, 0.798636, 0.809017, 0.819152, 0.829038, 0.838671, 0.848048, 0.857167,
0.866025, 0.874620, 0.882948, 0.891007, 0.898794, 0.906308, 0.913545, 0.920505, 0.927184, 0.933580,
0.939693, 0.945519, 0.951057, 0.956305, 0.961262, 0.965926, 0.970296, 0.974370, 0.978148, 0.981627,
0.984808, 0.987688, 0.990268, 0.992546, 0.994522, 0.996195, 0.997564, 0.998630, 0.999391, 0.999848,
1.000000, 0.999848, 0.999391, 0.998630, 0.997564, 0.996195, 0.994522, 0.992546, 0.990268, 0.987688,
0.984808, 0.981627, 0.978148, 0.974370, 0.970296, 0.965926, 0.961262, 0.956305, 0.951057, 0.945519,
0.939693, 0.933580, 0.927184, 0.920505, 0.913545, 0.906308, 0.898794, 0.891007, 0.882948, 0.874620,
0.866025, 0.857167, 0.848048, 0.838671, 0.829038, 0.819152, 0.809017, 0.798636, 0.788011, 0.777146,
0.766044, 0.754710, 0.743145, 0.731354, 0.719340, 0.707107, 0.694658, 0.681998, 0.669131, 0.656059,
0.642788, 0.629320, 0.615661, 0.601815, 0.587785, 0.573576, 0.559193, 0.544639, 0.529919, 0.515038,
0.500000, 0.484810, 0.469472, 0.453990, 0.438371, 0.422618, 0.406737, 0.390731, 0.374607, 0.358368,
0.342020, 0.325568, 0.309017, 0.292372, 0.275637, 0.258819, 0.241922, 0.224951, 0.207912, 0.190809,
0.173648, 0.156434, 0.139173, 0.121869, 0.104528, 0.087156, 0.069756, 0.052336, 0.034899, 0.017452,
0.000000, -0.017452, -0.034899, -0.052336, -0.069756, -0.087156, -0.104528, -0.121869, -0.139173, -0.156434,
-0.173648, -0.190809, -0.207912, -0.224951, -0.241922, -0.258819, -0.275637, -0.292372, -0.309017, -0.325568,
-0.342020, -0.358368, -0.374607, -0.390731, -0.406737, -0.422618, -0.438371, -0.453990, -0.469472, -0.484810,
-0.500000, -0.515038, -0.529919, -0.544639, -0.559193, -0.573576, -0.587785, -0.601815, -0.615661, -0.629320,
-0.642788, -0.656059, -0.669131, -0.681998, -0.694658, -0.707107, -0.719340, -0.731354, -0.743145, -0.754710,
-0.766044, -0.777146, -0.788011, -0.798636, -0.809017, -0.819152, -0.829038, -0.838671, -0.848048, -0.857167,
-0.866025, -0.874620, -0.882948, -0.891007, -0.898794, -0.906308, -0.913545, -0.920505, -0.927184, -0.933580,
-0.939693, -0.945519, -0.951057, -0.956305, -0.961262, -0.965926, -0.970296, -0.974370, -0.978148, -0.981627,
-0.984808, -0.987688, -0.990268, -0.992546, -0.994522, -0.996195, -0.997564, -0.998630, -0.999391, -0.999848,
-1.000000, -0.999848, -0.999391, -0.998630, -0.997564, -0.996195, -0.994522, -0.992546, -0.990268, -0.987688,
-0.984808, -0.981627, -0.978148, -0.974370, -0.970296, -0.965926, -0.961262, -0.956305, -0.951057, -0.945519,
-0.939693, -0.933580, -0.927184, -0.920505, -0.913545, -0.906308, -0.898794, -0.891007, -0.882948, -0.874620,
-0.866025, -0.857167, -0.848048, -0.838671, -0.829038, -0.819152, -0.809017, -0.798636, -0.788011, -0.777146,
-0.766044, -0.754710, -0.743145, -0.731354, -0.719340, -0.707107, -0.694658, -0.681998, -0.669131, -0.656059,
-0.642788, -0.629320, -0.615661, -0.601815, -0.587785, -0.573576, -0.559193, -0.544639, -0.529919, -0.515038,
-0.500000, -0.484810, -0.469472, -0.453990, -0.438371, -0.422618, -0.406737, -0.390731, -0.374607, -0.358368,
-0.342020, -0.325568, -0.309017, -0.292372, -0.275637, -0.258819, -0.241922, -0.224951, -0.207912, -0.190809,
-0.173648, -0.156434, -0.139173, -0.121869, -0.104528, -0.087156, -0.069756, -0.052336, -0.034899, -0.017452 };

float my_cos[] = { 1.000000, 0.999848, 0.999391, 0.998630, 0.997564, 0.996195, 0.994522, 0.992546, 0.990268, 0.987688,
0.984808, 0.981627, 0.978148, 0.974370, 0.970296, 0.965926, 0.961262, 0.956305, 0.951057, 0.945519,
0.939693, 0.933580, 0.927184, 0.920505, 0.913545, 0.906308, 0.898794, 0.891007, 0.882948, 0.874620,
0.866025, 0.857167, 0.848048, 0.838671, 0.829038, 0.819152, 0.809017, 0.798636, 0.788011, 0.777146,
0.766044, 0.754710, 0.743145, 0.731354, 0.719340, 0.707107, 0.694658, 0.681998, 0.669131, 0.656059,
0.642788, 0.629320, 0.615661, 0.601815, 0.587785, 0.573576, 0.559193, 0.544639, 0.529919, 0.515038,
0.500000, 0.484810, 0.469472, 0.453990, 0.438371, 0.422618, 0.406737, 0.390731, 0.374607, 0.358368,
0.342020, 0.325568, 0.309017, 0.292372, 0.275637, 0.258819, 0.241922, 0.224951, 0.207912, 0.190809,
0.173648, 0.156434, 0.139173, 0.121869, 0.104528, 0.087156, 0.069756, 0.052336, 0.034899, 0.017452,
0.000000, -0.017452, -0.034899, -0.052336, -0.069756, -0.087156, -0.104528, -0.121869, -0.139173, -0.156434,
-0.173648, -0.190809, -0.207912, -0.224951, -0.241922, -0.258819, -0.275637, -0.292372, -0.309017, -0.325568,
-0.342020, -0.358368, -0.374607, -0.390731, -0.406737, -0.422618, -0.438371, -0.453990, -0.469472, -0.484810,
-0.500000, -0.515038, -0.529919, -0.544639, -0.559193, -0.573576, -0.587785, -0.601815, -0.615661, -0.629320,
-0.642788, -0.656059, -0.669131, -0.681998, -0.694658, -0.707107, -0.719340, -0.731354, -0.743145, -0.754710,
-0.766044, -0.777146, -0.788011, -0.798636, -0.809017, -0.819152, -0.829038, -0.838671, -0.848048, -0.857167,
-0.866025, -0.874620, -0.882948, -0.891007, -0.898794, -0.906308, -0.913545, -0.920505, -0.927184, -0.933580,
-0.939693, -0.945519, -0.951057, -0.956305, -0.961262, -0.965926, -0.970296, -0.974370, -0.978148, -0.981627,
-0.984808, -0.987688, -0.990268, -0.992546, -0.994522, -0.996195, -0.997564, -0.998630, -0.999391, -0.999848,
-1.000000, -0.999848, -0.999391, -0.998630, -0.997564, -0.996195, -0.994522, -0.992546, -0.990268, -0.987688,
-0.984808, -0.981627, -0.978148, -0.974370, -0.970296, -0.965926, -0.961262, -0.956305, -0.951057, -0.945519,
-0.939693, -0.933580, -0.927184, -0.920505, -0.913545, -0.906308, -0.898794, -0.891007, -0.882948, -0.874620,
-0.866025, -0.857167, -0.848048, -0.838671, -0.829038, -0.819152, -0.809017, -0.798636, -0.788011, -0.777146,
-0.766044, -0.754710, -0.743145, -0.731354, -0.719340, -0.707107, -0.694658, -0.681998, -0.669131, -0.656059,
-0.642788, -0.629320, -0.615661, -0.601815, -0.587785, -0.573576, -0.559193, -0.544639, -0.529919, -0.515038,
-0.500000, -0.484810, -0.469472, -0.453990, -0.438371, -0.422618, -0.406737, -0.390731, -0.374607, -0.358368,
-0.342020, -0.325568, -0.309017, -0.292372, -0.275637, -0.258819, -0.241922, -0.224951, -0.207912, -0.190809,
-0.173648, -0.156434, -0.139173, -0.121869, -0.104528, -0.087156, -0.069756, -0.052336, -0.034899, -0.017452,
-0.000000, 0.017452, 0.034899, 0.052336, 0.069756, 0.087156, 0.104528, 0.121869, 0.139173, 0.156434,
0.173648, 0.190809, 0.207912, 0.224951, 0.241922, 0.258819, 0.275637, 0.292372, 0.309017, 0.325568,
0.342020, 0.358368, 0.374607, 0.390731, 0.406737, 0.422618, 0.438371, 0.453990, 0.469472, 0.484810,
0.500000, 0.515038, 0.529919, 0.544639, 0.559193, 0.573576, 0.587785, 0.601815, 0.615661, 0.629320,
0.642788, 0.656059, 0.669131, 0.681998, 0.694658, 0.707107, 0.719340, 0.731354, 0.743145, 0.754710,
0.766044, 0.777146, 0.788011, 0.798636, 0.809017, 0.819152, 0.829038, 0.838671, 0.848048, 0.857167,
0.866025, 0.874620, 0.882948, 0.891007, 0.898794, 0.906308, 0.913545, 0.920505, 0.927184, 0.933580,
0.939693, 0.945519, 0.951057, 0.956305, 0.961262, 0.965926, 0.970296, 0.974370, 0.978148, 0.981627,
0.984808, 0.987688, 0.990268, 0.992546, 0.994522, 0.996195, 0.997564, 0.998630, 0.999391, 0.999848 };

//功能说明：找到图像中所有圆心在图像内的圆，得到中心点和半径
//colorImg：用来搜索圆形目标的彩色图像
//min_radius：需要搜索的圆的最小半径
//max_radius：需要搜索的圆的最大半径
//min_center_dist：找到的圆心之间的最小距离
//min_radius_dist：同心圆半径之间的最小差距
//max_circle_diff：阈值，圆周差分值低于此阈值，不是圆
//x：数组，存储所有的圆的中心点x坐标
//y：数组，存储所有的圆的中心点y坐标
//radius：数组，存储所有的圆的半径值
//len：圆的数目
//返回值：MY_OK或者MY_FAIL

int ustc_Find_Circles_By_Difference(
	Mat colorImg,
	int min_radius,
	int max_radius,
	int min_center_dist,
	int min_radius_dist,
	int max_circle_diff,
	int* x,
	int* y,
	int* radius,
	int* len);

int ustc_Find_Circles_By_Difference(Mat colorImg, int min_radius, int max_radius, int min_center_dist, int min_radius_dist, int max_circle_diff, int * x, int * y, int * radius, int * len)
{
	int i, j;
	uchar *img = (uchar *)colorImg.data;
	if (NULL == img)
	{
		printf("failed to open");
		return MY_FAIL;
	}

	int num_now = 0;  //当前找到圆的个数
	int MY_Rows = colorImg.rows;  //图像像素行数
	int MY_Cols = colorImg.cols;  //图像像素列数
	int channel = colorImg.channels();  //图像通道数


	int sav_x[MY_LENGTH];  //x坐标的暂存
	int sav_y[MY_LENGTH];  //y坐标的暂存
	int sav_radius[MY_LENGTH];  //圆半径的暂存
	float sav_diff[MY_LENGTH];  //圆周差分的暂存

	int MY_pixel = MY_Rows*MY_Cols;

	int* circle_diff_r = new int[MY_pixel]();  //r通道某一半径
	int* circle_diff_g = new int[MY_pixel]();  //g通道某一半径
	int* circle_diff_b = new int[MY_pixel]();  //b通道某一半径


	for (int r = min_radius; r <= max_radius; r++)
	{
		//求出某一半径下，在所有点上3个通道的“外圆像素和”与“内圆像素和”
		for (int theta = 0; theta < 360; theta++)
		{
			int dx_out = (r + 5)*my_cos[theta];
			int dy_out = (r + 5)*my_sin[theta];
			int dx_in = (r - 5)*my_cos[theta];
			int dy_in = (r - 5)*my_sin[theta];
			for (int x = r + 5; x < MY_Rows - r - 5; x++)
			{
				for (int y = r + 5; y < MY_Cols - r - 5; y++)
				{
					int index = x * MY_Cols + y;
					int index_out = channel * ((x + dx_out) * MY_Cols + (y + dy_out));
					int index_in = channel * ((x + dx_in) * MY_Cols + (y + dy_in));
					circle_diff_b[index] += (img[index_out] - img[index_in]);
					circle_diff_g[index] += (img[index_out + 1] - img[index_in + 1]);
					circle_diff_r[index] += (img[index_out + 2] - img[index_in + 2]);
				}
			}
		}

		//检查是否有当前半径大小的圆
		for (int x = r + 5; x < MY_Rows - r - 5; x++)
		{
			for (int y = r + 5; y < MY_Cols - r - 5; y++)
			{
				int index = x * MY_Cols + y;

				float diff_b = circle_diff_b[index] / 360.0f;
				if (diff_b < 0)
				{
					diff_b = -diff_b;
				}


				float diff_g = circle_diff_g[index] / 360.0f;
				if (diff_b < 0)
				{
					diff_g = -diff_g;
				}

				float diff_r = circle_diff_r[index] / 360.0f;
				if (diff_b < 0)
				{
					diff_b = -diff_r;
				}

				float diff = diff_b + diff_g + diff_r;

				if (diff_b >= max_circle_diff || diff_g >= max_circle_diff || diff_r >= max_circle_diff)
				{
					//做非极大值抑制，消除同一个圆的重复记录
					for (i = 0; i < num_now; i++)
					{
						int dist_x = sav_x[i] - x;
						int dist_y = sav_y[i] - y;
						int dist_radius = sav_radius[i] - r;
						if (dist_x*dist_x + dist_y*dist_y <= min_center_dist*min_center_dist && dist_radius*dist_radius <= min_radius_dist*min_radius_dist)
						{
							//对于同一个圆，记录差分值最大的
							if (diff > sav_diff[i])
							{
								sav_x[i] = x;
								sav_y[i] = y;
								sav_radius[i] = r;
								sav_diff[i] = diff;
							}
							break;
						}
					}
					//当前找到的圆没有重复记录，记入数组
					if (i == num_now)
					{
						sav_x[num_now] = x;
						sav_y[num_now] = y;
						sav_radius[num_now] = r;
						sav_diff[num_now] = diff;
						num_now++;
					}
				}
			}
		}

		 //“圆周差分值”数组清零，为存下一个半径做准备
		for (i = 0; i < MY_Rows; i++)
		{
			for (j = 0; j < MY_Cols; j++)
			{
				int index = i * MY_Cols + j;
				circle_diff_b[index] = 0;
				circle_diff_g[index] = 0;
				circle_diff_r[index] = 0;
			}
		}
	}

	for (int i = 0; i < num_now; i++)
	{
		x[i] = reg_x[i];
		y[i] = reg_y[i];
		radius[i] = reg_radius[i];
	}
	*len = num_now;

	return MY_OK;
}

int main()
{
	Mat colorImg = imread("D:\\twogirls.JPG");
	if (NULL == colorImg.data)
	{
		printf_s("failed to open image");
		return 0;
	}

	uchar* img = (uchar *)colorImg.data;
	int mRows = colorImg.rows;  //图像像素行数
	int mCols = colorImg.cols;  //图像像素列数
	int channel = colorImg.channels();  //图像通道数
	int min_radius = 150;
	int max_radius = 300;
	int min_center_dist = 5;
	int min_radius_dist = 5;
	int max_circle_diff = 150;
	int x[5000];
	int y[5000];
	int radius[5000];
	int len;


	if (MY_FAIL == ustc_Find_Circles_By_Difference(colorImg, min_radius, max_radius, min_center_dist, min_radius_dist, max_circle_diff, x, y, radius, &len))
	{
		printf("no circle");
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		cout << "x: " << x[i] << ", y: " << y[i] << ", radius: " << radius[i] << endl;
		int dix = channel*(x[i] * mCols + y[i]);
		img[dix] = 256 - img[dix];
		img[dix + 1] = 256 - img[dix + 1];
		img[dix + 2] = 256 - img[dix + 2];

		int px = x[i];
		int py = y[i];
		int r = radius[i];
		for (int theta = 0; theta < 360; theta++)
		{
			int dx = r*my_cos[theta];
			int dy = r*my_sin[theta];
			int circle_find = channel * ((px + dx) * mCols + (py + dy));
			img[circle_find] = 0;
			img[circle_find + 1] = 0;
			img[circle_find + 2] = 0;
		}
	}

	cout << "len: " << len << endl;

	namedWindow("colorImg", 0);
	imshow("colorImg", colorImg);
	waitKey();

	return 0;
}
