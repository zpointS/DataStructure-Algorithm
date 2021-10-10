//#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

const int LEN = 4;

//拉格朗日插值函数
double LIP(double* x,double* y,double x0){ //给定点坐标X、Y与任意横坐标x0
	return y[0]*(x0-x[1])*(x0-x[2])*(x0-x[3])/((x[0]-x[1])*(x[0]-x[2])*(x[0]-x[3]))+
			y[1]*(x0-x[0])*(x0-x[2])*(x0-x[3])/((x[1]-x[0])*(x[1]-x[2])*(x[1]-x[3]))+
			y[2]*(x0-x[0])*(x0-x[1])*(x0-x[3])/((x[2]-x[0])*(x[2]-x[1])*(x[2]-x[3]))+
			y[3]*(x0-x[0])*(x0-x[1])*(x0-x[2])/((x[3]-x[0])*(x[3]-x[1])*(x[3]-x[2]));
}

//三点simpson法
double simpson(double* x,double* y,double a, double b){
	double c = a + (b - a) / 2;
	return ((b-a)/6)*(LIP(x,y,a) + 4*LIP(x,y,c) + LIP(x,y,b));
}

//自适应simpson公式；其中eps要自己设定，我们取常用值1e-5
double asr(double* x,double* y,double a, double b, double eps, double A){
	double c = a + (b - a) / 2;
	double L = simpson(x, y, a, c), R = simpson(x, y, c, b);
	if(fabs(L+R-A)<=15*eps)
		return L + R + (L + R - A) / 15.0;
	return asr(x, y, a, c, eps / 2, L) + asr(x, y, c, b, eps / 2, R);
}

//double solve(const double x0[LEN],const double y0[LEN], const double x1[LEN], const double y1[LEN]){
double solve(double* x0,double* y0,double* x1,double* y1){
	double s0,s1,adv1,adv2;
	double eps = 1e-5;
	double left_bound = min(x0[0], x1[0]);
	double right_bound = max(x0[LEN-1], x1[LEN-1]);

	s0=asr(x0,y0,left_bound,right_bound,eps,simpson(x0,y0,left_bound,right_bound));
	s1=asr(x1,y1,left_bound,right_bound,eps,simpson(x1,y1,left_bound,right_bound));

	adv1=abs((s0-s1))/s0*100;
	adv2=abs((s0-s1))/s1*100;
    return (adv1+adv2)/2;
}

int main(int argc, char *argv[]){

	if(argc != LEN * 4 + 1){
		cout << argv[0] << " x00 y00 x01 y01 x02 y02 x03 y03 x10 y10 x11 y11 x12 y12 x13 y13" << endl;
		return -1;
	}

	double* x0 = new double[LEN]; 
	double* y0 = new double[LEN];
	double* x1 = new double[LEN]; 
	double* y1 = new double[LEN];
	

	int i, j = 0,k = 0, m = 0, n = 0;
	for (i = 0; i < LEN * 4; i++)  //把数据存好
	{
		if(i < LEN * 2){
			if((i & 0x01) == 0){ //判断是否是偶数，这样快
				x0[j++] = atof(argv[i + 1]);//atof是字符串转浮点数
			} else {
				y0[k++] = atof(argv[i + 1]);
			}
		} else {
			if((i & 0x01) == 0){
				x1[m++] = atof(argv[i + 1]);
			} else {
				y1[n++] = atof(argv[i + 1]);
			}
		}
	}

	cout << setiosflags(ios::fixed) << setprecision(2) << solve(x0, y0, x1, y1) << "%" << endl;
	//在遇到要计算浮点数且希望能控制其输出、精度、小数点后的位数等时，用setiosflags(ios::fixed)来控制。

	return 0;
}