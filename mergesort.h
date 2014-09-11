#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include"scy_test.h"
#include<cassert>
#include<algorithm>

template<typename T>
void mymerge(T& A, int p, int q, int r,T& B)
{
	int k = p;
	int i = p;
	int j = q + 1;
	for( ; i<=q && j<=r; ++k)
	{
		if(A[i] < A[j])
			B[k] = A[i++];
		else
			B[k] = A[j++];
	}
	if(i <= q)
		for(int l = 0; l <= q-i; ++l)
			B[k+l] = A[i+l];
	if(j <= r)
		for(int l = 0; l <= r-j; ++l)
			B[k+l] = A[j+l];

}

template<typename T>
void mergesort(T& A, int left, int right)
{
	static T B = T(A.size(),0);
	if(left >= right)
		return;
	int i = (left + right)/2;
	mergesort(A, left, i);
	mergesort(A, i + 1, right);
	mymerge(A, left, i, right, B);
	std::copy(B.begin() + left, B.begin() + right +1, A.begin() + left);
}
#endif
