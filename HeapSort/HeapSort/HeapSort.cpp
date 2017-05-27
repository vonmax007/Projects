// HeapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


void Heapfy(int A[],int idx,int max)      //建立最大堆  
{  
    int left=idx*2+1;  
    int right=left+1;  
  
    int largest=idx;  
  
    if(left<max&&A[left]>A[idx]){largest=left;}  
  
    if(right<max&&A[largest]<A[right]){largest=right;}  
  
    if(largest!=idx)  
    {  
        int temp=A[largest];   //较大的节点值将交换到其所在节点的父节点  
        A[largest]=A[idx];  
        A[idx]=temp;  
  
        Heapfy(A,largest,max); //递归遍历  
  
    }  
}  
  
void buildHeap(int A[],int ll)  
{  
    int len=ll;  
  
  
    for(int i=len/2-1;i>=0;--i)  
    {  
        Heapfy(A,i,len);     //建立最大堆，将堆中最大的值交换到根节点  
    }  
  
    for(int i=len-1;i>=1;--i)  
    {  
        int temp=A[0];   //将当前堆的根节点交换到堆尾的指定位置  
        A[0]=A[i];  
        A[i]=temp;  
  
        Heapfy(A,0,i);  //建立下一次的最大堆  
    }  
}  


int _tmain(int argc, _TCHAR* argv[])
{
	int * arr;
	int length;
	cin>>length;
	cout<<endl;
	arr = new int[length];
	for(int i = 0; i< length;++i)cin>>arr[i];
	buildHeap(arr, length);
	for(int i = 0; i< length;++i)cout<<arr[i]<<"  ";

	return 0;
}

