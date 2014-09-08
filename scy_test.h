/************************************************
 * filename	:  scy_test.h
 * author	:  songcy
 * email	:  920828276@qq.com
 * last modified :  2014-09-08 22:14
 * description	:  
************************************************/
#ifndef _SCY_TEST_H_
#define _SCY_TEST_H_

#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<limits.h>

namespace scy_test
{
	/***************************
	*	judge if array is sorted
	***************************/
	template<typename T>
	bool IsSorted(std::vector<T> tv)
	{
		for(auto i = tv.begin()+1; i != tv.end(); ++i)
		{
			if(*i < *(i-1))
			{
				std::cout<< *i <<" < " <<*(i-1)<<std::endl;
				return false;
			}
		}
		return true;
	}
	/***************************
	*	print info
	***************************/
	template<typename T>
	void Print(T &t)
	{
#ifndef NOTEST
		std::cout<< t <<std::endl;
#endif
	}

	template<typename T,typename size_t>
	void Print(T t[], size_t len)
	{
#ifndef NOTEST
		for(size_t i = 0; i < len; ++i)
			std::cout<<t[i]<<" ";
		std::cout<<std::endl;
#endif
	}
	template<typename T>
	void Print(std::vector<T> iv)
	{
		for(auto i = iv.begin(); i != iv.end(); ++i)
			std::cout<<*i<<" ";
		std::cout<<std::endl;
	}

	/***************************
	*  compare two function's running time
	***************************/
	//TODO:have arg funs
	template<typename T>
	class function
	{
	public:
		function(T *f):
			function(f) {}
		void run()
		{
			function.operator();
		}
	private:
		T& function;
		time_t starttime;
		time_t endtime;
	};

	/***************************
	*  create unsorted T type array(vector or list) for sort functions
	***************************/

	template<typename T>
	class RandomArray
	{
	public:
		RandomArray(size_t size, int mval = INT_MAX):
			tvec(std::vector<T>(size)),
//			tlist(list<T>(size)),
			size(size),
			max_value(mval)
		{
			t = new T[size];
			srand((unsigned)NULL);
			createDataRandomly();
		}
		RandomArray():
			tvec(std::vector<T>(1)),
//			tlist(list<T>(1)),
			size(1),
			max_value(INT_MAX)
		{
			t = new T[1];
			srand((unsigned int)NULL);
			createDataRandomly();
		}
		~RandomArray()
		{
			if(t != nullptr)
			{
				delete [] t;
				std::cout<<"~RandomArray"<<std::endl;
			}
		}
		T* getArray() { return *t;	}
		std::vector<T>& getVector() { return tvec; }
		
	private:
		void createDataRandomly()
		{
			for(size_t i = 0; i < size; ++i)
			{
				tvec[i] = rand() % max_value;
				t[i] = rand() % max_value;
				/*
				std::cout<<tvec[i]<<" -------log info";
				std::cout<<"\n";
				*/
			}
		}
		RandomArray(const RandomArray &);
		RandomArray& operator=(const RandomArray &);
		std::vector<T> tvec;
		T * t;
//		list<T> tlist;
		size_t size;
		const int max_value;
	};

}

#endif
