#include "cuda_runtime.h"
#include "cudafile2.cuh"
#include <stdio.h>
#include <iostream>
#include "device_launch_parameters.h"

using namespace std;

#define N 10

void fillalldata(int ** data[N][N]) {
	
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			**data[i][j] = j * 4;
		 }
	}
}

__global__ void AddMatrix(int a[][N],int b[][N],int c[][N]) {

	int i = threadIdx.x;
	int j = threadIdx.y;
	c[i][j] = a[i][j] + b[i][j];
}


void PrintEndValue(int  a[N][N], int  b[N][N], int  c[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N;j++)
		{
			printf("%d %d %d", a[i][j], b[i][j], c[i][j]);
		}
		printf("\n");
	}
}



void RunCudaFile2()
{
	

}