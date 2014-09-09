#include"scy_test.h"
#include<iostream>
#include<algorithm>
using namespace std;
using namespace scy_test;


int main(int argc, const char *argv[])
{
	const int NUM = 100;
	vector<RandomArray<double> > randvec(NUM);

	{
		timer t("std::sort");
		for(int i = 0; i < NUM; ++i)
		{
			vector<double> iv = randvec[i].getUnsortedArray();
			sort(iv.begin(),iv.end());
			IsSorted(iv);
		}
	}

	{
		timer t("std::stable_sort");
		for(int i = 0; i < NUM; ++i)
		{
			vector<double> iv = randvec[i].getUnsortedArray();
			stable_sort(iv.begin(),iv.end());
			IsSorted(iv);
		}
	}
	return 0;
}
