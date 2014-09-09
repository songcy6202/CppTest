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
#include<sys/time.h>
#include<climits>
#include<algorithm>
#include<string>

namespace scy_test
{
	/***************************
	*	judge wether the array is sorted
	***************************/
	template<typename T>
	bool IsSorted(std::vector<T> tv)
	{
		for(auto i = tv.begin()+1; i != tv.end(); ++i)
		{
			if(*i < *(i-1))
			{
#ifndef TEST
				std::cout<< *i <<" < " <<*(i-1)<<std::endl;
				std::cout<<" unsorted ! "<<std::endl;
#endif
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

	template<typename T>
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
	*  record function's running time
	*  example:
	*  {
	*  		timer t("quicksort");
	*  		funtion code...
	*  	}
	***************************/
	class timer
	{
	public:
		timer(const char *info_):
			starttime(0),
			endtime(0),
			info(info_)
		{
			gettimeofday(&tv,NULL);
			starttime = tv.tv_sec * 1000 + tv.tv_usec/1000;
		}
		~timer()
		{
			gettimeofday(&tv,NULL);
			endtime = tv.tv_sec * 1000 + tv.tv_usec/1000;
			std::cout<<"--------------------------"<<std::endl;
			std::cout<<"- \" "<<info<<" \""<<std::endl;
			std::cout<<"- running time : "<<endtime-starttime<<" ms "<<std::endl;
			std::cout<<"--------------------------"<<std::endl;
		}
	private:
		struct timeval tv;  //to create time in 0.001
		time_t starttime;
		time_t endtime;
		std::string info;
	};

	/***************************
	*  create 
	*  unsorted/nearsorted/sorted/rsorted
	*  array for sort functions
	***************************/

	template<typename T>
	class RandomArray
	{
	public:
		RandomArray(size_t size, int mval = INT_MAX):
			unsortedvec(std::vector<T>(size)),
			nearlysortedvec(std::vector<T>(size)),
//			tlist(list<T>(size)),
			size(size),
			max_value(mval)
		{
//			t = new T[size];
			srand((unsigned)NULL);
			createDataRandomly();
		}
		RandomArray():
			unsortedvec(std::vector<T>(defaultsize)),
			nearlysortedvec(std::vector<T>(defaultsize)),
//			tlist(list<T>(1)),
			size(defaultsize),
			max_value(INT_MAX)
		{
//			t = new T[1];
			srand((unsigned int)NULL);
			createDataRandomly();
		}
		~RandomArray() { }

		// not return & to protect datas' order in class
		std::vector<T> getUnsortedArray() {  return unsortedvec; }
		std::vector<T> getNearlysortedArray(){ return nearlysortedvec;}
		std::vector<T> getSortedArray(){ return sortedvec;}
		std::vector<T> getRsortedArray(){ return sortedvec;}

	private:
		void createDataRandomly()
		{
			for(size_t i = 0; i < size; ++i)
			{
				unsortedvec[i] = rand() % max_value;
				/*
				std::cout<<tvec[i]<<" -------log info";
				std::cout<<"\n";
				*/
			}
			sortedvec = unsortedvec;
			std::sort(sortedvec.begin(), sortedvec.end());
			rsortedvec = sortedvec;
			std::reverse(rsortedvec.begin(), rsortedvec.end());
			int extend_value = 0;
			int scope = 200;  //random in range (a ,a+200)
			for(int i = 0; i < size ; ++i)
			{
				nearlysortedvec[i] = (rand() % max_value ) % scope + extend_value;
				if( i % 30 == 0)
					extend_value += scope;
			}
		}
		RandomArray(const RandomArray &);
		RandomArray& operator=(const RandomArray &);
		std::vector<T> unsortedvec;
		std::vector<T> nearlysortedvec;
		std::vector<T> sortedvec;
		std::vector<T> rsortedvec;
//		T * t;
//		list<T> tlist;
		size_t size;
		const int max_value;
		static const int defaultsize = 10000;
//		static unsigned randseed;
	};

}

#endif
