#include<iostream>
#include"stdlib.h"
#include<vector>
using namespace std;
//Inserion sort
template<typename T>
int insertionSort(T* arr, int size)
{
	T elem;
	int j;
	int swaps=0;
	for(int i=0;i<size-1;i++)
	{
		if(arr[i]> arr[i+1])
		{
			elem=arr[i+1];
			j=i;
			while(j>=0)
			{
				if(arr[j]>elem) {swap(arr[j],arr[j+1]);swaps++;}
				j--;
			}
		}
	}
	return swaps;
}
//Shell sort
template<typename T>
int shellSort(T* arr, int size)
{
	T elem;
	int j;
	int swaps=0;
	int arg;
	int k=0;
	int args[]={3,2,1};
	for(int p=0;p<=2;p++)
	{
		arg=args[p];
	for(int i=arg;i<size;i++)
	{
		if(arr[i-arg]>arr[i])
		{
			elem=arr[i];
			j=i-arg;
			while(j>=0)
			{
				if(arr[j]>elem) {swap(arr[j],arr[j+arg]);swaps++;}
				j-=arg;
			}
		}
	}
}
	return swaps;
}
//merge sort
template<typename T>
int mergeSr(T*,int, int);
int cnt=0;
template<typename T>
int mergeSort(T* arr, int size)
{
	int timesInside=0;
	if(size==1 || size==0) return timesInside;
	if(size==2)
	{
		if(arr[0]>arr[1]) {swap(arr[0],arr[1]);timesInside++;}
		return timesInside;
	}
	timesInside=timesInside+mergeSort(arr,size/2);
	timesInside=timesInside+mergeSort(arr+size/2,(size+1)/2);

	timesInside=timesInside+ mergeSr(arr,size/2,size);
	return timesInside;
}
template<typename T>
int mergeSr(T* arr, int leftSize, int size)
{
	cnt++;
	int left,right;
	vector<T> tmp;
	left=0;
	int timesInside=0;
	right=leftSize;
	while(left<leftSize || right<size)
	{
		if(left<leftSize && right<size)
		{
			if(arr[left]>arr[right])
			{
				tmp.push_back(arr[right]);
				cnt++;
				timesInside++;
				right++;
			}
			else
			{
				tmp.push_back(arr[left]);
				timesInside++;
				cnt++;
				left++;
			}
		}
		else if(left<leftSize)
		{
			tmp.push_back(arr[left]);
			left++;
			cnt++;
			timesInside++;
		}
		else
		{
			tmp.push_back(arr[right]);
			right++;
			cnt++;
			timesInside++;
		}
	}
	for(int i=0;i<size;i++)
		{arr[i]=tmp[i];cnt++;}
	return timesInside;

}
//radix sort
template<typename T>
int radixSort(T* arr, int size)
{
	int cont=0;
	int maxLen=0;
	int tmpLen=0;
	int tempo;
	int timesInside=0;
	for(int i=0;i<size;i++)
	{
		cont++;
		if(arr[i]>maxLen) maxLen=arr[i];
	}
	while(maxLen)
	{
		cont++;
		tmpLen++;
		maxLen/=10;
	}
	//Krai na namirane na duljina na element
	int divid=1;
	int pnt=0;
	vector<T> tempVect[10];
	int elemCnt[10][1];
	for(int i=0;i<10;i++)
		{elemCnt[i][0]=0;}
	for(int i=0;i<tmpLen;i++)
	{
		pnt=0;
		for(int l=0;l<10;l++)
			{elemCnt[l][0]=0;}
		for(int j=0;j<size;j++)
		{
			cont++;
			tempVect[((arr[j]/divid)%10)].push_back(arr[j]);
			timesInside++;
			elemCnt[((arr[j]/divid)%10)][0]++;
		}
		for(int k=0;k<10;k++)
		{
			for(int j=0;j<elemCnt[k][0];j++)
			{
				cnt++;
				arr[pnt]=tempVect[k][j];
				pnt++;
			}
			//CLearing the vector
			for(int j=0;j<elemCnt[k][0];j++)
			{
				cnt++;
				tempVect[k].erase(tempVect[k].begin());
			}				
		}
		divid*=10;
	}
	return timesInside;
}
//quickSort
template<typename T>
int quickSort(T* arr, int size)
{
	int cnt=0;
	if(size==1 || size==0) return cnt;
	if(size==2)
	{
		if(arr[0]>arr[1]) {swap(arr[0],arr[1]);cnt++;return cnt;}
		else return cnt;
	}
	int pivotInd=rand()%size;
	T pivotElem=arr[pivotInd];
	if(pivotInd != size-1)
		swap(arr[pivotInd],arr[size-1]);
	int left, right;
	left=0;right=size-2;
	while(left<right)
	{
		for(int i=left;i<size-1;i++)
		{
			if(arr[i]>pivotElem)
			{
				left=i;
				break;
			}
			if(i==size-2) {left=size-2;break;}
		}
		for(int j=right;j>=0;j--)
		{

			if(arr[j]<pivotElem)
			{
				right=j;
				break;
			}
			if(j==0) {right=0;break;}

		}
		if(left<right) {swap(arr[left],arr[right]);cnt++;};
	}
	if(!(left==right) || !(right==size-2))
	{
	swap(arr[left],arr[size-1]);
	cnt++;
	}
	cnt=cnt + quickSort(arr,left+1);
	cnt=cnt + quickSort(arr+left+1,size-left-1);
	return cnt;
}
//max heap
template<typename T>
int swapper(int pos,T* arr, int size)
{
	int timesInside=0;
	if(2*pos+1 <size && arr[pos]<arr[2*pos +1])
	{
		/*cout<<arr[pos]<<"    "<<arr[2*pos+1]<<"\n";  */
		{swap(arr[pos],arr[2*pos + 1]);timesInside++;}
		for(int i=0;i<size;i++)
		/*cout<<arr[i]<<"\n";
	cout<<"\n";*/
		timesInside=timesInside+swapper(2*pos + 1,arr,size);
	}
	if(2*pos + 2<size && arr[pos]<arr[2*pos +2 ])
	{
		//cout<<arr[pos]<<"    "<<arr[2*pos+1]<<"\n";
		{swap(arr[pos],arr[2*pos +2 ]);timesInside++;}
		/*for(int i=0;i<size;i++)
		cout<<arr[i]<<"\n";
	cout<<"\n";*/
		timesInside=timesInside+ swapper(2*pos + 2,arr,size);
	}
	return timesInside;
}
template<typename T>
int maxHeap(T* arr, int size)
{
	int timesInside=0;
	for(int i=size/2-1;i>=0;i--)
	{
		timesInside=timesInside+swapper(i,arr,size);
	}
	return timesInside;
}
template<typename T>
int heapSort(T* arr, int size)
{
	int timesInside=0;
	//cout<<"da";
	if(size==0) return timesInside;
	timesInside=timesInside+maxHeap(arr,size);
	swap(arr[0],arr[size-1]);
	timesInside++;
	size--;
	timesInside=timesInside+heapSort(arr,size);
	return timesInside;
}
template<typename T>
void compareSorts(T* arr, int size)
{
	cout<<"Брой вмъквания/смени на елементи за:"<<"\n";
	T* nArr=new T[size];
	for(int i=0;i<size;i++)
		nArr[i]=arr[i];
	cout<<"quickSort: "<< quickSort(nArr,size)<<"\n";
	for(int i=0;i<size;i++)
		nArr[i]=arr[i];
	cout<<"radixSort: "<<radixSort(nArr,size)<<"\n";
	for(int i=0;i<size;i++)
		nArr[i]=arr[i];
	cout<<"shellSort: "<<shellSort(nArr,size)<<"\n";
	for(int i=0;i<size;i++)
		nArr[i]=arr[i];
	cout<<"insertionSort: "<<shellSort(nArr,size)<<"\n";
	for(int i=0;i<size;i++)
		nArr[i]=arr[i];
	cout<<"heapSort: "<<heapSort(nArr,size)<<"\n";
	for(int i=0;i<size;i++)
		nArr[i]=arr[i];
	cout<<"mergeSort: "<<mergeSort(nArr,size)<<"\n";
}
int main()
{
	int arr[10];
	int sz=10;
	for(int i=0;i<sz;i++)
		{arr[i]=rand()%40000;cout<<arr[i]<<"  ";}
	cout<<"\n";
	
	compareSorts(arr,sz);
	

}