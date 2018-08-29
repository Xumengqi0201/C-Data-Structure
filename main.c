#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _node{
    ElementType data;
    struct _node *next;
}node;

typedef struct{
    node *head;
    node *tail;
    int size;
}List;

void MakeEmpty(List *plist){
    plist->tail=plist->head=(node*)malloc(sizeof(node));//空节点就是头节点
    plist->tail->next=NULL;
    plist->size=0;
}

void Attach_Tail(List *plist,ElementType data){
    node *p=(node*)malloc(sizeof(node));
    p->data=data;p->next=NULL;

    plist->tail->next=p;
    plist->tail=p;
    plist->size++;
}

ElementType Delete_Tail(List *plist){
    ElementType result;
    if (plist->size==0){
        result=-1;
        printf("The list is Empty!\n");
    }
    else{
        result=plist->tail->data;
        plist->size++;
        if (plist->size==1){
            free(plist->tail);
            plist->tail=plist->head;;
            plist->tail->next=NULL;
        }
        else{
            node *p;
            for (p=plist->head->next;p&&p->next!=plist->tail;p=p->next);
            p->next=NULL;
            free(plist->tail);
            plist->tail=p;
        }
    }
    return result;
}

void Read_list(List *plist,int list_size){
    MakeEmpty(plist);
    printf("pls enter the list data:\n");
    while (list_size--){
        int data=0;
        scanf("%d",&data);
        Attach_Tail(plist,data);
    }
}

void Print_list(List *plist){
    if (plist->size==0)
        printf("The list is Empty!\n");
    else{
        node *p;
        for(p=plist->head->next;p;p=p->next)
            printf("%d ",p->data);
        printf("\n");
    }
}

void Reverse_list(List *plist,int K){
    if (K<0||K>plist->size)
        printf("Error:the reversed number K!\n");
    else{
        if (K==0||K==1);
        else{
            node *_new=plist->head->next;
            node *old=_new->next;
            node *tmp;
            int count=1;
            while(count<K ) {
                tmp=old->next;

                old->next=_new;
                _new=old;old=tmp;
                count++;
             }
            plist->head->next->next=old;
            if (old==NULL)
                plist->tail=plist->head->next;
            plist->head->next=_new;
        }
    }
}

int main(){

    List list;
    int list_size=5,K=0;
    Read_list(&list,list_size);
    printf("The list is:\n");
    Print_list(&list);
    while (K<6){
        printf("K=%d\n",K);
        Reverse_list(&list,K);
        Print_list(&list);
        K++;
    }


    return 0;
}
