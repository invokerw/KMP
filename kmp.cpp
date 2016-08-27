#include "stdafx.h"


using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cassert>
#include <errno.h>
#include<vector>

void get_next(char*t, int next[ ]){
	int t_len=strlen(t);
	int i=0;         //求解每个next[i]
	next[0]=-1; //递推基本条件,然后求解next[i+1]
	int j=-1;     //向后递推位置下标
	/*
	next[i]=k =>T0...Tk-1=Ti-k...Ti-1
	求解next[i+1]
	1> 如果T0..Tk-1Tk=Ti-k...Ti-1Ti=>next[i+1]=k+1=next[i]+1;
	2>Tk<>Ti,next[k]=k', 如果Ti=Tk'=>next[i+1]=k'+1=next[k]+1=next[next[i]]+1;
	3>依次递推 最后情况next[i+1]=next[0]+1=0,即
	*/
	while(i<t_len)
	{
		if(j==-1 ||t[i]==t[j])  //j==-1证明已经与t[0]不匹配了，此时next[i+1]=0
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j]; 
		}
	}
}
int KMP(char *s,char *t){
	int s_len=strlen(s);
	int t_len=strlen(t);
	int i=0;
	int j=0;
	int *next=new int[t_len];
	get_next(t,next);
	if(t_len > s_len) 
		return -1;
	while(i < s_len && j < t_len)
	{
		if(j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}//end while
	if(j >= t_len)
		return i-j;
	else
		return -1;
}
int main(void)
{
	char *s="abcdasdefghijklmnefgh";
	char *t="efgh";
	cout<<KMP(s,t)<<endl;
	system("pause");
	return 0;
}