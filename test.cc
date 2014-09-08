#include"scy_test.h"
#include<iostream>
#include<algorithm>
using namespace std;
using namespace scy_test;


int main(int argc, const char *argv[])
{
	RandomArray<int> ranarray(1000);
	vector<int> iv = ranarray.getVector();
	sort(iv.begin(),iv.end());
//	Print(iv);
	cout<<IsSorted(iv)<<endl;
	return 0;
}
