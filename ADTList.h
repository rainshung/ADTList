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

/*��ʼ��list*/
void ADTListInit(ADTList* adtlptr);

/*����list*/
void ADTListDestory(ADTList* adtlptr);

/*
	index > 0  ������Ԫ��elm����Ϊlist�ĵ�index��
	index <=0  Ĭ������������Ԫ��elm
*/
int AddElement(ADTList *adtlptr,Element elm,int index=0);

/*
	index > 0 ɾ��list�����index��Ԫ��
	index <= 0 Ĭ��ɾ��list�����һ��ֵ����elm��Ԫ��
*/
int DelElement(ADTList *adtlptr,Element elm,int index=0);

/*ɾ��list��������ֵ����elm��Ԫ��*/
int DelElementAll(ADTList *adtlptr,Element elm);

/*
	index > 0 ����list�е�index��Ԫ�ص�ֵΪelm_new����ʱelm_old������Ч
	index <= 0 ����list�е�һ��Ԫ��ֵΪelm_old��ֵΪelm_new
*/
int UpdElemSet(ADTList* adtlptr,Element elm_new,Element elm_old,int index=0);

/*��list�����е�elm_oldֵ����Ϊelm_new*/
int UpdElemSetAll(ADTList *adtlptr,Element elm_new,Element elm_old);

/*����list��Ĭ���ǽ������У�sorlflag<0 ����������*/
int SortList(ADTList *adtlptr,int sortflag=0);

/*����list�е�index��Ԫ�صĵ�ַ*/
ElemSet* LokElemSet(ADTList *adtlptr,int index);
#endif