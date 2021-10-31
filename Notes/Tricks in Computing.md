# 一些算法题中的小技巧
内含一些经典的算法题模型与加速技巧。
比如快速幂、质数分解、组合数计算等。



## 经典模型
### 大数质因子分解
- 利用C++分解质因数，利用了
[**最多只有一个大于根号N的质数**](https://blog.csdn.net/qq_36770641/article/details/88853147)
的结论。
- 利用
[埃氏筛、欧拉筛](https://blog.csdn.net/dy416524/article/details/86431057)
**划去质数的倍数**进行素数的筛选。

### 卡特兰数
- 可用于
[求解给定节点数的二叉树形态数目](https://blog.csdn.net/weixin_33851177/article/details/89750513)。
思想是**动态规划**。
- 求解
[出栈顺序数](https://blog.csdn.net/duzejie/article/details/52491072)
问题。


## 加速技巧
### 快速幂与快速乘
- 讲解了
[求解a的b次方与求解a*b的快速做法](https://blog.csdn.net/liangllhahaha/article/details/82119378)。
主要思想是**将乘数分解为二进制的幂的表示**，做到O(logn)的复杂度的计算方法。
二者的区别在于快速幂中base是自乘，而快速乘为base的自加。

### 求解组合数的值
- 讲解了
[求解组合数](https://blog.csdn.net/albertsh/article/details/108691877)
的各种方法。有利用动态规划的，也有直接用一维递推的。

