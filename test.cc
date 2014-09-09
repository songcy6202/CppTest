#include"scy_test.h"
#include"Insertsort.h"
#include<iostream>
#include<algorithm>
using namespace std;
using namespace scy_test;


int main(int argc, const char *argv[])
{
	const int NUM = 10;
	vector<RandomArray<int> > randvec(NUM);

	{
		timer t("std::sort");
		for(int i = 0; i < NUM; ++i)
		{
			vector<int> iv = randvec[i].getUnsortedArray();
			sort(iv.begin(),iv.end());
			IsSorted(iv);
		}
	}

	{
		timer t("std::stable_sort");
		for(int i = 0; i < NUM; ++i)
		{
			vector<int> iv = randvec[i].getUnsortedArray();
			stable_sort(iv.begin(),iv.end());
			IsSorted(iv);
		}
	}

	{
		timer t("insertsort");
		//RandomArray<int> arr(40,1000);
		for(int i = 0; i < NUM; ++i)
		{
			vector<int> iv = randvec[i].getUnsortedArray();
			Insertsort(iv, iv.size());
			IsSorted(iv);
		}
	}
	{
		timer t("insertsort recursious");
		for(int i = 0; i < NUM; ++i)
		{
			vector<int> iv = randvec[i].getUnsortedArray();
			InsertsortR(iv, iv.size() - 1, iv.size());
			IsSorted(iv);
		}
		/*
		RandomArray<int> arr(40,1000);
		auto iv = arr.getUnsortedArray();
		InsertsortR(iv, iv.size() - 1, iv.size());
		IsSorted(iv);
		*/
	}
	return 0;
}
