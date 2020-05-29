# 经典排序算法

## 排序算法包含
|算法名称|类名|平均时间复杂度|说明|
-|-|-|-
|冒泡排序|BubbleSort|O(n*n)|原理属于交换排序|
|快速排序|QuickSort||
|桶排序(简化版)|BucketSort(Simple)||
||||
||||

### 冒泡排序
#### 基本思想
   > 每次比较两个相邻的元素，如果他们顺序错误，就将他们交换过来



#### 冒泡排序算法实现  
   ```java
    for(int i = 0;i<array.length;i++) {
		for (int j = 0;j<array.length-i-1;j++) {
			if (array[j]>array[j+1]) {
                int temp =0;    //设置临时存储功能的变量
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
```  
   > `temp` 就是起到了这个临时变量的作用

#### 思考背景--无需额外变量变量交换两个数/变量的值
在对经典排序算法进行复习的时候，发现排序算法对数组队列等数组结构中元素的操作大几率会用到交换两个变量的值(在逻辑上表现为交换两个元素的位置)，基础操作会是在额外声明一个新变量用于辅助交换元素的临时存值空间，比如
要想做到不使用临时变量存储对两个数进行位置互换(逻辑上)，是不是可以通过数学关系上两者的运算来达到这个效果，以下对此优化，做到不使用额外的变量空间置换两个数

#### 优化方法1：   
   算数运算(加减)
   ```java
    x=x+y; //x暂存两数之和
    y=x-y; //y为两数之和减去y，即原来的x
    x=x-y; //x为两数之和减去现在的y（原来的x），变成原来的y
   ```  
    以上对纯数字的值进行操作符合数学关系

    把 `x` 看成`array[j]`,`y` 看成`array[j+1]`,将核心代码优化一下
   ```java
    array[j] = array[j]+array[j+1];
    array[j+1] = array[j] - array[j+1];
    array[j] = array[j] - array[j+1];
   ```
    **实际上可读性就可能很牵强了**
#### 优化方法2：
    逻辑运算(异或)
   ```java
    x^=y;//x先存x和y两者的信息
    y^=x;//保持x不变，利用x异或反转y的原始值使其等于x的原始值
    x^=y;//保持y不变，利用x异或反转y的原始值使其等于y的原始值
   ```
    同理将核心代码优化结果
   ```java
    array[j] ^= array[j+1];
    array[j+1] ^= array[j];
    array[j] ^= array[j+1];
   ```
    **可读性可能也是差强人意**

**以上只是对方法的探讨。**


### 快速排序
  + 基于 `二分` 的思想
  +

#### 快速排序算法实现
  + C 实现版本(数组版本)
    ```c
    void quicksort(int left,int right){
        int i,j,t,temp;

        if (left>right) // left与right擦肩而过，属于异常需要排错的情况 
            return;
        
        temp = a[left]; // 将基准数保存在 temp 中
        i = left;   //用于寻找比基准数大的左侧索引量
        j = right;  //用于寻找比基准数小的右侧索引量

        while(i!=j){ // 当i还未与j相遇时，遍历序列并比较大小的操作不会停

            // 步骤顺序很重要，先从右往左找
            while(a[j]>=temp){
                j--;
            }

            // 从右往找的步骤已经完成，再从左往又找
            while(a[i]<=temp){
                i++;
            }

            // 当前基准数下，该序列内的比较结束，进行数值交换工作
            t=a[i];
            a[i] = a[j];
            a[j] = t;
        }

        // 交换基准数和最后一次i与j汇合的位置上的数后，将序列从基准数所在的新位置分开，生成两个新序列，继续之前序列的比较操作，整体上看来是一个递归操作
        quickusort(left,i-1);   // 从数组左侧到旧基准数的前一个数
        quickusort(i+1,right);// 从旧基准数的后一个数到数组右侧

    }
    ```

### 简化版桶排序
  + 假设一组自然数，我们已知这组数的最大值和最小值
  + 我们将会设立一个长度略大于这组数最大值的数组
  + 遍历这个数组，将每个元素的数值与数组索引值相同的数组元素+1(表示个数+1)
  + 遍历结束以后，可以根绝升序还是降序的要求进行顺序或者逆序打印数组里不为0的索引值，每个数组元素的值多大，该数组元素对应的索引值就重复打印多少次

#### “简化版桶排序” 算法实现   
   + 命题  
     输入一组数(已知是0~9的自然数)：  
        > 5 3 5 2 8   

     使用简化版的桶排序将该组数降序输出
   + Java 实现版本  
     ```java
      public static void main(String[]args){

          
      }
     ```  


   + C 实现版本  

     ```C
     #include <stdio.h>

     int main(){
         int a[11],i,j,t;
         for (i =;i<=10;i++){
             a[i]=0;
         }

         // 接下来循环读入 5 个数
         for(i=1;i<=5;i++){
             scanf("%d",&t);
             a[t]++;
         }

         for(i = 0;i<10;i++){
             for (j=1;j<=a[i];j++){
                 printf("%d",i)
             }
         }
         getchar();getchar();
         // 这里的getchar();可以用来暂停程序，以便查看输出内容
         // 也可以用 system("pause");
         return 0;
     }
     ```  