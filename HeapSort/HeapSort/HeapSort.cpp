// HeapSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


void Heapfy(int A[],int idx,int max)      //��������  
{  
    int left=idx*2+1;  
    int right=left+1;  
  
    int largest=idx;  
  
    if(left<max&&A[left]>A[idx]){largest=left;}  
  
    if(right<max&&A[largest]<A[right]){largest=right;}  
  
    if(largest!=idx)  
    {  
        int temp=A[largest];   //�ϴ�Ľڵ�ֵ�������������ڽڵ�ĸ��ڵ�  
        A[largest]=A[idx];  
        A[idx]=temp;  
  
        Heapfy(A,largest,max); //�ݹ����  
  
    }  
}  
  
void buildHeap(int A[],int ll)  
{  
    int len=ll;  
  
  
    for(int i=len/2-1;i>=0;--i)  
    {  
        Heapfy(A,i,len);     //�������ѣ�����������ֵ���������ڵ�  
    }  
  
    for(int i=len-1;i>=1;--i)  
    {  
        int temp=A[0];   //����ǰ�ѵĸ��ڵ㽻������β��ָ��λ��  
        A[0]=A[i];  
        A[i]=temp;  
  
        Heapfy(A,0,i);  //������һ�ε�����  
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

