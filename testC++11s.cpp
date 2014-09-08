// testC++11s.cpp : 定义控制台应用程序的入口点。
//

#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <functional>//greater 
#include <memory>
#include <unordered_map>
#include <regex> 

using namespace std;

struct A
{
	int i = 0;  //##
	int j;
	A(int m, int n) :i(m), j(n){}
	A(){}
	A(int v) :j(v){}
	~A(){ cout << j << " destructor" << endl; }
};

A operator+(int n, const A & a)
{
	return a;
}

template<class T1,class T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
	return x + y;
}

auto func(int m, int n) -> A  //##
{ 
	return{ m, n };  //## 
}

int main(int argc, const char *argv[])
{
	// 1: unify  initialize 
	int arr[3]{1, 2, 3};
	vector<int> iv{ 1, 2, 3 };
	map<int, string> mp{ { 1, "a" }, { 2, "b" } };
	string str{ "hello world" };
	int *p = new int[20]{1, 2, 3};
	A *pa = new A{ 3, 7 };

	// 2: auto decltype
	auto i = 100;      //i is int
	auto pp = new A(0);  //p is A*
	auto k = 12345LL;  //k is long long
	map<string, int, greater<string>> mp2;
	for (auto it = mp.begin(); it != mp.end(); ++it)
		cout << it->first << " ," << it->second;
	
	decltype(arr) x1;      // TODO: x1 is int  arr is int[] or int ???
	decltype((i)) ii = i;  // ii is a int&

	// 3: shared_ptr 
	shared_ptr<A> sp1(new A(2));
	shared_ptr<A> sp2(sp1);
	cout << "shared_ptr" << sp1->j << "," << sp2->j << endl;
	shared_ptr<A> sp3;
	A *ptra = sp1.get();
	sp1.reset();  //sp1 is null now
	A *q = new A(3);
	sp1.reset(q);
	shared_ptr<A> sp5;
	//sp5.reset(q); error

	// 4: nullptr
	int *p1 = nullptr;
	int *p2 = NULL;
	shared_ptr<double> p3 = nullptr;
	if (p1 == p2)
		cout << "equal 1" << endl;
	//if (p3 == p2) p3 and p2 types are different
	bool b = nullptr;  //nullptr -> false
	//int  i = nullptr; error 

	// 5: for
	int ary[]{1, 2, 3, 4, 5};
	for (int &e : ary)
	{	
		e *= 10;
	}
	for (int e : ary)
		cout << e << " ";
	cout << endl;
	vector<int> st(ary, ary + 5);
	for (auto & it : st)
		it *= 10;
	for (auto it : st)
		cout << it << " ";
	cout << endl;

	// 6: right reference
	//class A;
	class B{};
//	B & r = B();  //TODO:????
	B && rr = B();

	// 7: unordered_map
	unordered_map<string, int> turingWinner;
	turingWinner.insert(make_pair("songcy", 2018));
	turingWinner.insert(make_pair("James", 2000));
	turingWinner["songcy"] = 2020;
	turingWinner["new"] = 2001;
	for (auto it : turingWinner)
		cout << it.first << " " << it.second << " " ;
	cout << endl;

	// 8: regex
	regex reg("b.?p.*k");
	cout << regex_match("boppggk", reg) << endl;
	cout << regex_match("boopggk", reg) << endl;

	/***************************
	 * gdb 4.8.1 implement c++11 Expect regex and gc library What fuck!
	 * VS is ok
	 ***************************/
	/*
	regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1"); // \\s -> " "
	string correct = "123Hello N/A Hello";
	string incorrect = "123hello 12 Hello";
	cout << regex_match(correct, reg2) << endl;
	cout << regex_match(incorrect, reg2) << endl;
	*/

	// 9: Lambda  [=] [] [&] [x,&y] [=,&x,&y] [&,x,y]
	int x = 100, y = 200, z = 300;
	cout << [](double a, double b){return a + b; }(1.2, 2.5) << endl;
	auto ff = [=, &y, &z](int n)
	{
		cout << x << endl;
		y++, z++;
		return n*n;
	};
	cout << ff(15) << endl;
	int a[4] = { 45, 2, 1, 123 };
	sort(a, a + 4, [](int x, int y)->bool{return x % 10 < y % 10; });
	for_each(a, a + 4, [](int x){cout << x << " "; });
	function<int(int)> fib = [&fib](int n)
	{ return n <= 2 ? 1 : fib(n - 1) + fib(n - 2); };
	cout << fib(5) << endl;

	return 0;
}

