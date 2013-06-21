#include "ADTList.h"
#include <stdlib.h>
void ADTListInit(ADTList* adtlptr)
{
	adtlptr->_init = 1;
	adtlptr->_cnt = 0;
	adtlptr->_head = (ElemSet*)malloc(sizeof(ElemSet));
	adtlptr->_head->bakptr = NULL;
	adtlptr->_head->m_value = 0;
	adtlptr->_head->preptr = NULL;
}
static void ElemSetDestory(ElemSet* els)
{
	if(els->bakptr != NULL)
		ElemSetDestory(els->bakptr);
	else{
		free(els);
		els = NULL;
	}
}
void ADTListDestory(ADTList* adtlptr)
{
	if(adtlptr->_init == 0)
		return;
	adtlptr->_cnt = 0;
	adtlptr->_init = 0;
	ElemSetDestory(adtlptr->_head);
}
static ElemSet* GetTailIndex(ElemSet *estptr,int index)
{
	if(index < 0){
		if(estptr->bakptr == NULL)
			return estptr;
		else
			return GetTailIndex(estptr->bakptr,-1);
	}
	else{
		if(index == 0)
			return estptr;
		else
			return GetTailIndex(estptr->bakptr,index-1);
	}

}
static ElemSet *GetElement(ElemSet *head,Element val)
{
	if(head->m_value == val)
		return head;
	if(head->bakptr != NULL)
		return GetElement(head->bakptr,val);
	return NULL;
}
int AddElement(ADTList* adtlptr,Element elm,int index)
{
	if(index > adtlptr->_cnt+1||adtlptr->_init == 0)
		return 0;
	ElemSet *tail = NULL;
	ElemSet *tail_next = NULL;
	ElemSet *newone = (ElemSet*)malloc(sizeof(ElemSet));
	newone->m_value = elm;
	newone->bakptr = NULL;
	newone->preptr = NULL;

	if(adtlptr->_cnt == 0||index == 1)
		tail = adtlptr->_head;
	else
		tail = GetTailIndex(adtlptr->_head,index-1);
	if(index == 0)
		tail = GetTailIndex(adtlptr->_head,adtlptr->_cnt);
	tail_next = tail->bakptr;
	tail->bakptr = newone;
	newone->preptr = tail;
	if(tail_next != NULL){
		newone->bakptr = tail_next;
		tail_next->preptr = newone;
	}
	adtlptr->_cnt += 1;
	return 1;
}
int DelElement(ADTList* adtlptr,Element elm,int index)
{
	if(index > adtlptr->_cnt||adtlptr->_init == 0)
		return 0;
	ElemSet *tail = NULL;
	ElemSet *tail_next = NULL;
	ElemSet *tail_pre = NULL;
	//删除ADTList里面的第index个元素单元
	if(index > 0){
		tail = GetTailIndex(adtlptr->_head,index);
		tail_next = tail->bakptr;
		tail_pre = tail->preptr;
		tail_pre->bakptr = tail_next;
		tail_next->preptr = tail_pre;
		adtlptr->_cnt -= 1;
	}
	else{//删除ADTList里面的第一个值等于elm的元素单元
		tail = GetElement(adtlptr->_head,elm);
		if(tail == NULL)
			return 0;
		tail_next = tail->bakptr;
		tail_pre = tail->preptr;
		if(tail_next != NULL)
			tail_next->preptr = tail_pre;	

		tail_pre->bakptr = tail_next;
		adtlptr->_cnt -= 1;
	}
	free(tail);
	tail = NULL;
	return 1;
}
int DelElementAll(ADTList *adtlptr,Element elm)
{
	if(adtlptr->_init == 0)
		return 0;
	int return_flag = 0;
	int tmp_flag;
	return_flag = DelElement(adtlptr,elm,0);
	if(return_flag){
		do{
			tmp_flag = DelElement(adtlptr,elm,0);
		}while(tmp_flag);
	}
	return return_flag;
}
int UpdElemSet(ADTList* adtlptr,Element elm_new,Element elm_old,int index)
{
	if(index > adtlptr->_cnt||adtlptr->_init == 0)
		return 0;
	ElemSet* tail;
	int return_flag=0;
	if(index > 0){
		tail = GetTailIndex(adtlptr->_head,index);
		if(tail == NULL)
			return return_flag;
		tail->m_value = elm_new;
		return_flag = 1;
	}
	else{
		tail = GetElement(adtlptr->_head,elm_old);
		if(tail == NULL)
			return return_flag;
		tail->m_value = elm_new;
		return_flag = 1;
	}
	return return_flag;
}
ElemSet* LokElemSet(ADTList* adtlptr,int index)
{
	if(index > adtlptr->_cnt||adtlptr->_init == 0)
		return NULL;
	return GetTailIndex(adtlptr->_head,index);
}

int UpdElemSetAll(ADTList *adtlptr,Element elm_new,Element elm_old)
{
	if(adtlptr->_init == 0||adtlptr->_cnt ==0)
		return 0;
	int i=1;
	int done=0;
	int tmp_flag=0;
	done = UpdElemSet(adtlptr,elm_new,elm_old,0);
	if(done){
		do{
			tmp_flag = UpdElemSet(adtlptr,elm_new,elm_old,0);
		}while(tmp_flag);
	}
	return done;
}
int SortList(ADTList *adtlptr,int sortflag)
{
	int cnt = adtlptr->_cnt;
	if(cnt==1||adtlptr->_init==0)
		return 0;
	int i,j;
	Element tmp;
	ElemSet *nu1= NULL;
	ElemSet *nu2= NULL;
	for(i=1;i<cnt;i++){
		nu1 = GetTailIndex(adtlptr->_head,i);
		nu2 = nu1->bakptr;
		for(j=i+1;j<=cnt;j++){
			if(sortflag>=0&&(nu1->m_value < nu2->m_value)){
				tmp = nu1->m_value;
				nu1->m_value = nu2->m_value;
				nu2->m_value = tmp;
			}
			if(sortflag<0&&(nu1->m_value > nu2->m_value))
			{
				tmp = nu1->m_value;
				nu1->m_value = nu2->m_value;
				nu2->m_value = tmp;
			}	
			nu2 = nu2->bakptr;
		}
	}
	return 0;
}
