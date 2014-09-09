#include"scy_test.h"
/**********************************************
*	insert sort 
***********************************************/
template<typename T>
void Insertsort(T& A, int len)
{
	if(len <= 1)
		return;
	for(int i = 1; i < len; ++i)
	{
		auto key = A[i];
		int k = i-1;  //insert A[i] into sorted queue A[0 --- j-1]
		while(k>=0 && key<=A[k])
		{
			A[k+1] = A[k];
			k--;
		}
		A[k+1] = key;
//		scy_test::Print(A);
	}
}

/**********************************************
*	insert sort recursively
***********************************************/
template<typename T>
void InsertsortR(T& A, int k, int len)
{
	if(len <= 1)
		return;
	if(k == 0)
		return;
	InsertsortR(A, k-1, len);
	auto key = A[k];
	int i = k-1;
	while(key<A[i] && i>=0)
	{
		A[i+1] = A[i];
		i--;
	}
	A[i+1] = key;
//	scy_test::Print(A);
}
