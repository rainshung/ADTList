#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ADTList.h"
/*
void ADTListInit(ADTList* adtlptr);
void ADTListDestory(ADTList* adtlptr);
int AddElement(ADTList *adtlptr,Element elm,int index);
int DelElement(ADTList *adtlptr,Element elm,int index);
int UpdElemSet(ADTList *adtlptr,Element elm,int index);
ElemSet* LokElemSet(ADTList *adtlptr,int index);
*/
void PrintList(ADTList *list)
{
	int i;
	ElemSet* elm;
	for(i=1;i<=list->_cnt;i++){
		elm = LokElemSet(list,i);
		printf("%d ",elm->m_value);
	}
	printf("\n");
}
int compare(Element a,Element b)
{
	return a-b;
}
int main(int argc,char *argv[])
{
	ADTList list;
	ADTListInit(&list);
	int i=0;
	for(i=1;i<10;i++){
		AddElement(&list,i);
	}
	PrintList(&list);

	UpdElemSetAll(&list,9,1);
	PrintList(&list);

	SortList(&list,0);
	PrintList(&list);
	SortList(&list,-1);
	PrintList(&list);

	DelElementAll(&list,9);
	PrintList(&list);
	ADTListDestory(&list);
	return 0;
}