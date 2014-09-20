##CppTest
* 打印运行调试信息
```c++
    scy_test::Print(vec);
```
* 记录比较函数运行时间
```c++
    {
      scy_test::timer t("myquicksort");
      myqsort(A);
    }
    
    /*输出
    -------------------------
    myquicksort
    running time : 2.15ms
    -------------------------
    */
```
* 快速成成随机数据
```c++
    RandomArray<int> randarry(40,1000);  // 1000以内 40个未排序数组
    vector<int> iv = randarry.getUnsortedArray(); //iv 是随生成的未排序数组
```    

