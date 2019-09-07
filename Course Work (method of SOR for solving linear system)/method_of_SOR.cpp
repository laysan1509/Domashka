
#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <omp.h>
using namespace std;

void show_matrix(double **matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(10) << matrix[i][j];
		}
		cout << endl;
	}
}
void show_vector(double *vector, int N) {
	for (int i = 0; i < N; i++) {
		cout << vector[i] << "\t";
	}
	cout << endl;
}
//умножение матрицы на число
void mult_on_num(double **matr, int n, double t, double **res_matr)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res_matr[i][j] = t * matr[i][j];
}
//Сложение матриц
void sum(double **matr_1, double **matr_2, int n, double **res_matr)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res_matr[i][j] = matr_1[i][j] + matr_2[i][j];
}
//Умножение матрицы matr на вектор vect, результат вектор - res_vect
void mult_vect(double **matr, double *vect, int n, double *res_vect)
{
	int i, j;
	omp_set_num_threads(8);
#pragma omp parallel for shared(res_vect, matr, vect) private(i, j)
	for (i = 0; i < n; i++) {
		res_vect[i] = 0;
		for (j = 0; j < n; j++) {
			res_vect[i] = res_vect[i] + matr[i][j] * vect[j];
		}
	}
}
//Умножение матрицы на матрицу
void mult_matr(double **matr_1, double **matr_2, int n, double **res_matr)
{
	int i, j, k;
	omp_set_num_threads(8);
#pragma omp parallel for shared(res_matr, matr_1, matr_2) private(i, j, k)

	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			res_matr[i][j] = 0;
			for ( k = 0; k < n; k++) {
				res_matr[i][j] = res_matr[i][j] + matr_1[i][k] * matr_2[k][j];
			}
		}
	}
}
//Модуль вектора vect - корень из суммы квадратов элементов массива.
double modul(double *vect, int n)
{
	double modul = 0;
	for (int i = 0; i < n; i++)
		modul = modul + vect[i] * vect[i];
	return sqrt(modul);
}
//Формирование из матрицы верхнетреугольной матрицы R;
void create_R(double **matr, int n, double **R_matr)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j)
				R_matr[i][j] = matr[i][j];
			else
				R_matr[i][j] = 0;
		}
	}
}
//Формирование из матрицы нижнетреугольной матрицы L      
void create_L(double **matr, int n, double **L_matr)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j)
				L_matr[i][j] = matr[i][j];
			else
				L_matr[i][j] = 0;
		}
	}
}
//Формирование из матрицы диагональной матрицы D
void create_D(double **matr, int n, double **D_matr)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				D_matr[i][j] = matr[i][j];
			else
				D_matr[i][j] = 0;
		}
	}
}
//решением методом Гаусса
int gauss(double **a, int n, double *f, double *x)
{
	int k, r;
	double c, temp, max, s, *n_f;


	n_f = new double[n];
	for (int i = 0; i < n; i++)
		n_f[i] = f[i];
	for (k = 0; k < n; k++)
	{
		max = fabs(a[k][k]);
		r = k;
		for (int i = k + 1; i < n; i++)
			if (fabs(a[i][k]) > max)
			{
				max = fabs(a[i][k]);
				r = i;
			}
		for (int j = 0; j < n; j++)
		{
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}
		c = n_f[k];
		n_f[k] = n_f[r];
		n_f[r] = c;
		for (int i = k + 1; i < n; i++)
		{
			temp = a[i][k] / a[k][k];
			for (int j = k; j < n; j++)
				a[i][j] -= temp * a[k][j];
			n_f[i] -= temp * n_f[k];
		}
	}
	if (a[n - 1][n - 1] == 0)
		if (n_f[n - 1] == 0)
			return -1;
		else return -2;
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			s = 0;
			for (int j = i + 1; j < n; j++)
				s += a[i][j] * x[j];
			x[i] = (n_f[i] - s) / a[i][i];
		}
		return 0;
	}

}
//Вычисление обратной матрицы А^(-1)
int inverse_matr(double **matr, int n, double **res_matr)
{
	int res;
	double *b, *x, **a;
	b = new double[n];
	x = new double[n];
	a = new double *[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = matr[i][j];
			}
		}
		for (int j = 0; j < n; j++)
			if (j == i)
				b[j] = 1;
			else b[j] = 0;
		res = gauss(a, n, b, x);
		if (res != 0)
			break;
		else
			for (int j = 0; j < n; j++)
				res_matr[j][i] = x[j];
	}
	delete[] x;
	delete[] b;
	if (res != 0)
		return -1;
	else return 0;
}
//метод верхней релаксации
void relax(double **A, double *f, double *x, int N, double w, double eps, double *x1) {

	int result, i, j, iter = 0;
	double **wL, **L, **R, **D, *in_Bwf, **Q, **B, **in_B, **in_Bw, **w_D, **W1,
		**wR, **in_B_, *g, mod = 1, *res, g_new=0;

	Q = new double *[N];
	in_Bw = new double *[N];
	in_B_ = new double *[N];
	B = new double *[N];
	W1 = new double *[N];
	in_B = new double *[N];
	L = new double *[N];
	R = new double*[N];
	wR = new double*[N];
	wL = new double*[N];
	D = new double *[N];
	w_D = new double *[N];
	g = new double[N];
	res = new double[N];
	in_Bwf = new double[N];
	for (i = 0; i < N; i++) {
		Q[i] = new double[N];
		in_Bw[i] = new double[N];
		in_B_[i] = new double[N];
		in_B[i] = new double[N];
		B[i] = new double[N];
		W1[i] = new double[N];
		L[i] = new double[N];
		R[i] = new double[N];
		wR[i] = new double[N];
		wL[i] = new double[N];
		D[i] = new double[N];
		w_D[i] = new double[N];
	}
	//x[i+1] =(-1)*(D+ωL)^(-1)*((ω-1)D + ωR)x[i] + (D+ωL)^(-1)* ωf,
	create_R(A, N, R);
	create_L(A, N, L);
	create_D(A, N, D);
	mult_on_num(L, N, w, wL);//wL
	sum(D, wL, N, B);//D+wL=B
	inverse_matr(B, N, in_B);//(D+wL)^(-1)=in_B   
	mult_on_num(in_B, N, w, in_Bw);//in_Bw=(D+wL)^(-1)*w  
	mult_vect(in_Bw, f, N, in_Bwf);//(D+wL)^(-1)*w*f=wf
	mult_on_num(in_B, N, -1, in_B_);//-1*(w*L+D)^(-1)
	mult_on_num(D, N, w - 1, w_D);//(w-1)*D
	mult_on_num(R, N, w, wR);//wR
	sum(w_D, wR, N, W1);//(w-1)*D+wR
	mult_matr(in_B_, W1, N, Q);//-((w - 1)*D + wR)*(D + wL)^(-1)
	omp_set_num_threads(8);
	for (i = 0; i < N; i++)//x=f
		x[i] = f[i];
	for (iter = 0; mod >= eps; iter++) {
		mult_vect(Q, x, N, g);//g=Q*x
#pragma omp parallel 
		{
#pragma omp for reduction(+:g_new) 
			for (i = 0; i < N; i++) {//x1=q+in_Bwf
				g_new = g[i];
				x1[i] = g_new +in_Bwf[i];
			}
		}
		for (i = 0; i < N; i++)//res=|x1-x|
			res[i] = fabs(x1[i] - x[i]);
		for (i = 0; i < N; i++)//x=x1
			x[i] = x1[i];
		mod = modul(res, N);
	}
	cout << "iterations =" << iter << endl; //Количество итераций
	for (i = 0; i < N; i++) {
		delete[] R[i];
		delete[] L[i];
		delete[] D[i];
		delete[] wL[i];
		delete[] wR[i];
		delete[] Q[i];
		delete[] in_Bw[i];
		delete[] B[i];
		delete[] in_B[i];
		delete[] in_B_[i];
		delete[] W1[i];
		delete[] w_D[i];
	}
	delete[] R;
	delete[] L;
	delete[] D;
	delete[] wL;
	delete[] wR;
	delete[] Q;
	delete[] in_B;
	delete[] in_Bw;
	delete[] B;
	delete[] in_B_;
	delete[] W1;
	delete[] w_D;
	delete[] x;
	delete[] g;
	delete[] res;
}
//вычитание двух векторов
void substr_vect(double *vec1, double *vec2, double *vec3, int N) {
	for (int i = 0; i < N; i++) {
		vec3[i] = vec1[i] - vec2[i];
	}
}
//нахождение нормы для матрицы
double norma(double **matr, int N) {
	double max;
	double *max_vec = new double[N];
	for (int i = 0; i < N; i++) {
		max = 0;
		for (int j = 0; j < N; j++) {
			max += matr[i][j];
		}
		max_vec[i] = max;
	}
	max = max_vec[0];
	for (int i = 1; i < N; i++) {
		if (max < max_vec[i])
			max = max_vec[i];
	}
	delete[] max_vec;
	return max;
}
//проверка на точность нахождения решения, вычисление погрешности
void check(double **A, double *x1, double *f, int N) {
	double *f1 = new double[N];
	double *f3 = new double[N];
	double **A1 = new double*[N];
	for (int i = 0; i < N; i++) {
		A1[i] = new double[N];
	}
	mult_vect(A, x1, N, f1); //A*x1=f1
	substr_vect(f, f1, f3, N); //f-f1=f3;
	inverse_matr(A, N, A1); //A1=a^(-1)
	double eps = norma(A1, N)*modul(f3, N);// norm of matr A1*norm of vect f1
	cout << "Eps = " << eps << endl;
	delete[] f1;
	delete[] f3;
	for (int i = 0; i < N; i++) {
		delete[] A1[i];
	}
	delete[] A1;

}
//генерирование симметричной положительно определённой матрицы
void generate(int N, double **matr, double *f1) {
	double **L_R, **D;
	L_R = new double*[N];
	D = new double*[N];
	for (int i = 0; i < N; i++) {
		L_R[i] = new double[N];
		D[i] = new double[N];
	}
	for (int i = 0; i < N; i++) {
		f1[i] = 0;
		f1[i] = rand() % (N + 5);
		for (int j = 0; j < N; j++) {
			matr[i][j] = 0;
			if (i != j) {
				L_R[i][j] = (double)rand() / RAND_MAX;
				L_R[j][i] = L_R[i][j];
				D[i][j] = 0;
			}
			else {
				L_R[i][j] = 0;
				D[i][j] = (N - 1) + (1 + rand() % N);
			}
		}
	}
	sum(matr, L_R, N, matr);
	sum(matr, D, N, matr);
}

int main(int argc, char *argv[])
{
	int N = 0;
	for (int i = 0; i < 5; i++) {
		N = N + 100;

		double **A, *f, *x, *x1, w = 1.6, eps = 0.001, t1, t2;
		cout << "N = " << N << endl;
		A = new double*[N];
		f = new double[N];
		x = new double[N];
		x1 = new double[N];
		for (int i = 0; i < N; i++) {
			A[i] = new double[N];
		}
		t1 = omp_get_wtime();
		generate(N, A, f);
		relax(A, f, x, N, w, eps, x1);
		check(A, x1, f, N);
		t2 = omp_get_wtime();
		printf("time is %g\n", t2 - t1);

		for (int i = 0; i < N; i++) {
			delete[] A[i];
		}
		delete[] A;
		delete[] f;
	
	}
	system("PAUSE");
	return 0;
}