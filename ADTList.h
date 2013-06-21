/*
	author	:rainshung@163.com
	date	:2013-06-20
	context	:
*/
#ifndef __ADTLIST_H_
#define __ADTLIST_H_
typedef int Element;
typedef struct elemset ElemSet;
typedef struct elemset{
	Element m_value;
	ElemSet* preptr;
	ElemSet* bakptr;
}ElemSet;
typedef struct adtlist{
	ElemSet*	_head;
	int			_cnt;	
	int			_init;
}ADTList;

/*初始化list*/
void ADTListInit(ADTList* adtlptr);

/*销毁list*/
void ADTListDestory(ADTList* adtlptr);

/*
	index > 0  插入新元素elm，作为list的第index个
	index <=0  默认在最后插入新元素elm
*/
int AddElement(ADTList *adtlptr,Element elm,int index=0);

/*
	index > 0 删除list里面第index个元素
	index <= 0 默认删除list里面第一个值等于elm的元素
*/
int DelElement(ADTList *adtlptr,Element elm,int index=0);

/*删除list里面所有值等于elm的元素*/
int DelElementAll(ADTList *adtlptr,Element elm);

/*
	index > 0 更新list中第index个元素的值为elm_new，此时elm_old参数无效
	index <= 0 更新list中第一个元素值为elm_old的值为elm_new
*/
int UpdElemSet(ADTList* adtlptr,Element elm_new,Element elm_old,int index=0);

/*在list中所有的elm_old值更新为elm_new*/
int UpdElemSetAll(ADTList *adtlptr,Element elm_new,Element elm_old);

/*排序list，默认是降序排列，sorlflag<0 是升序排列*/
int SortList(ADTList *adtlptr,int sortflag=0);

/*返回list中第index个元素的地址*/
ElemSet* LokElemSet(ADTList *adtlptr,int index);
#endif