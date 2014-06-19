/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include <stdio.h>
// change x's right side '1' to '0'
// eg : 0101 1000 => 0101 0000
#define R1_TO_0(x) (x)&((x)-1)

// change x's left side '0' to '1'
// eg : 1010 0111 => 1010 1111
#define L0_TO_1(x) (x)|((x)+1)

// change the right '1' string to '0'
// eg : 0101 1000 => 0100 0000
#define R1S_TO_0(x) (( x | (x-1) ) + 1) & x

#define GET_(x) (~x+1)

int getMaxInt(){
  // -x = ~x + 1;
    return (1 << 31) - 1; //2147483647， 由于优先级关系，括号不可省略
    // return ~(1 << 31);   //2147483647
    // return ((unsigned int) - 1) >> 1;  //2147483647
    // return (1 << -1) - 1;  //2147483647
}

int getMinInt(){
    return 1 << 31;     //-2147483648
    return 1 << -1;     //-2147483648
}

//计算n*2
int mulTwo(int n){
    return n << 1;
}

//负奇数的运算不可用
int divTwo(int n){
    return n >> 1;//除以2
}

int mulTwoPower(int n,int m){//计算n*(2^m)
    return n << m;
}

int divTwoPower(int n,int m){//计算n/(2^m)
    return n >> m;
}

int isOddNumber(int n){
    return (n & 1) == 1;
}

void swap(int a, int b){
  a ^= b;
  b ^= a;
  a ^= b;
}

long getMaxLong(){
    return ((unsigned long) - 1) >> 1;//2147483647
}

/*如果x<y x<y返回1，否则返回0*/
int min(int x,int y){
    return y ^ ((x ^ y) & -(x < y));
}
#define MIN(a, b) (a) > (b) ? (b) : (a)
#define MAX(a, b) (a) > (b) ? (a) : (b)

// n+1 = -~n
// n-1 = ~-n

int getAverage(int x, int y){
    return (x + y) >> 1;
    return ((x ^ y) >> 1) + (x & y);
}

int cmp(int x, int y){
  // -1 (x<y)
  //  0 (x=y)
  //  1 (x>y)
  return (x>y)-(x<y);
}

// x = x == a ? b : a;
// x = a + b - x;
// x = a ^ b ^ x;

// 最大公约数
static inline int gcd(int p, int q){
    if (p == 0) return q;
    gcd(q, p % q);
}

// 最小公倍数
// p is biger than q
static inline int gcm(int p, int q){
    return q / gcd(p,q)
}

int main(int argc, char const *argv[])
{
  unsigned int x = 23;

  printf("%d\n", R1_TO_0(x)); // (0101 0000)2

  printf("%d\n", R1S_TO_0(x));
  return 0;
}

