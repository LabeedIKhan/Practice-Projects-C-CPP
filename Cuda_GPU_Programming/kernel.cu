

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cudafile2.cuh"

/**
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <device_launch_parameters.h>
#include <device_functions.h>
*/


#define SIZE 1024
#define Th 10
#define N 512
#define N1 1024
#define N2 1024


__global__ void Vectoradd(int* arr1, int* arr2, int* arr3, int n)
{

	int i = threadIdx.x;

	if(i < n) {
		arr3[i] = arr2[i] + arr1[i];
	}
}

__device__ int PrintFromDeviceFunction()
{
	printf("Hello World From Device Thread [%d , %d] \n", threadIdx, blockIdx);
	return 10;
}

__global__ void PrintFromGpu()
{
	printf("Hello World From GPU Thread [%d , %d] \n", threadIdx, blockIdx);
	printf("%d",PrintFromDeviceFunction());
}


void Excer1()
{
	int* arr1;
	int *arr2;
	int *arr3;

	cudaMallocManaged(&arr1, SIZE * sizeof(int));
	cudaMallocManaged(&arr2, SIZE * sizeof(int));
	cudaMallocManaged(&arr3, SIZE * sizeof(int));

	for (int i = 0; i < SIZE; i++) {

		arr1[i] = i;
		arr2[i] = i;
		arr3[i] = 0;
	}

	Vectoradd << <1, SIZE >> > (arr1, arr2, arr3, SIZE);

	cudaDeviceSynchronize();

	for (int i = 0; i < 1024; i++) {
		printf("C[%d] = %d\n", i, arr3[i]);
	}

	PrintFromGpu << <1, 1 >> > ();

	cudaDeviceSynchronize();

	//PrintFromDeviceFunction << <1, 1 >> > ();

	//cudaDeviceSynchronize();

	cudaFree(arr1);
	cudaFree(arr2);
	cudaFree(arr3);
}

__global__ void global_device_add(int* a, int* b, int* c)
{
	c[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
}

void fill_array(int* data)
{
	for (int i = 0; i < N; i++) {
		data[i] = i;
	}
}

void Exer2()
{
	int* arr1; 
	int* arr2; 
	int* arr3;
	int* devicearr1;
	int* devicearr2;
	int* devicearr3;

	arr1 = (int*)malloc(N * sizeof(int));
	arr2 = (int*)malloc(N * sizeof(int));
	arr3 = (int*)malloc(N * sizeof(int));
	fill_array(arr1);
	fill_array(arr2);

	cudaMalloc((void**)&devicearr1, N * sizeof(int));
	cudaMalloc((void**)&devicearr2, N * sizeof(int));
	cudaMalloc((void**)&devicearr3, N * sizeof(int));

	cudaMemcpy(devicearr1, arr1, N * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(devicearr2, arr2, N * sizeof(int), cudaMemcpyHostToDevice);

	global_device_add << <N, 1 >> > (da, db, dc);

	cudaMemcpy(arr3, devicearr3, N * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < N; i++) {
		printf(" %d %d %d", arr1[i], arr2[i], arr3[i]);
	}

	free(arr1);
	free(arr2);
	free(arr3);

	cudaFree(devicearr1);
	cudaFree(devicearr2);
	cudaFree(devicearr3);
}


__global__ void Device_Add_Thread_Block(int* a, int* b, int* c)
{
	int index = threadIdx.x + blockIdx.x * blockDim.x;
	printf("Info is %d threadIdx.x %d  blockIdx.x %d * blockDim.x \n", threadIdx.x, blockIdx.x, blockDim.x);
	c[index] = a[index] + b[index];
}

void fill_array_two(int* arr)
{
	for (int i = 0;i < N1; i++)
	{
		arr[i] = i;
	}
}


void Thread_Block()
{
	int* arr1;
	int* arr2;
	int* arr3;
	int* devicearr1;
	int* devicearr2;
	int* devicearr3;


	arr1 = (int*)malloc(N1 * sizeof(int));
	arr2 = (int*)malloc(N1 * sizeof(int));
	arr3 = (int*)malloc(N1 * sizeof(int));
	fill_array_two(arr1);
	fill_array_two(arr2);

	cudaMalloc((void**)&devicearr1, N1 * sizeof(int));
	cudaMalloc((void**)&devicearr2, N1 * sizeof(int));
	cudaMalloc((void**)&devicearr3, N1 * sizeof(int));

	cudaMemcpy(devicearr1, arr1, N1 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(devicearr2, arr2, N1 * sizeof(int), cudaMemcpyHostToDevice);

	
	int blocks = N1 / 4;

	Device_Add_Thread_Block << <blocks, 4 >> > (devicearr1, devicearr2, devicearr3);

	cudaMemcpy(arr3, devicearr3, N1 * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < N1; i++)
	{
		printf("%d %d %d", arr1[i], arr2[i], arr3[i]);
	}

	free(arr1);
	free(arr2);
	free(arr3);

	cudaFree(devicearr1);
	cudaFree(devicearr2);
	cudaFree(devicearr3);
}


__global__ void device_mul_fourth(int* a, int* b, int* c)
{
	c[threadIdx.x] = a[threadIdx.x] * b[threadIdx.x] * 100;
}

void Fill_data_Fourth(int* data)
{
	for (int i = 0; i < N2; i++)
	{
		data[i] = i;
	}
}


void RunOnlyThreads()
{
	int* arr1;
	int* arr2;
	int* arr3;
	int* devicearr1;
	int* devicearr2;
	int* devicearr3;

	arr1 = (int*)malloc(N2 * sizeof(int));
	arr2 = (int*)malloc(N2 * sizeof(int));
	arr3 = (int*)malloc(N2 * sizeof(int));
	Fill_data_Fourth(arr1);
	Fill_data_Fourth(arr2);

	cudaMalloc((void**)&devicearr1, N2 * sizeof(int));
	cudaMalloc((void**)&devicearr2, N2 * sizeof(int));
	cudaMalloc((void**)&devicearr3, N2 * sizeof(int));

	cudaMemcpy(devicearr1, arr1, N2 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(devicearr2, arr2, N2 * sizeof(int), cudaMemcpyHostToDevice);

	device_mul_fourth<<<1, 1024>>>(da, db, dc);

	cudaMemcpy(arr3, devicearr3, N2 * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < N2; i++)
	{
		printf(" %d  %d  %d  \n", arr1[i], arr2[i], arr3[i]);
	}

	free(arr1);
	free(arr2);
	free(arr3);

	cudaFree(devicearr1);
	cudaFree(devicearr2);
	cudaFree(devicearr3);

}

__shared__ int timeth;

__global__ void PrintThreadName()
{
	int i = threadIdx.x;

	printf("The Thread Number is %d \n", i);

	__syncthreads();
	timeth += 1;
	printf(" total threads were %d", timeth);
	__syncthreads();
}

__global__ void PrintTimes()
{
	printf(" total threads were %d", timeth);
}



void RunTesting()
{
	PrintThreadName << <1, 1024 >> > ();
	PrintTimes << <1, 1 >> > ();
}


int main() {

	
	Excer1();
	Exer2();
	Thread_Block();
	RunOnlyThreads();
	RunCudaFile2();
	RunTesting();

	return 0;
}


