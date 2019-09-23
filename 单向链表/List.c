#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;			// 数据域 
	struct node *next;	// 指针域 
	
}; 

typedef struct node Node;
typedef struct node* PNode;  // 节点指针 

PNode Init(){
	
	PNode head = (PNode )malloc(sizeof(Node));
	if(!head)			// 申请内存空间失败的情况 
		return NULL;
	else{				// 申请成功的情况 
	 	head->next = NULL;			
		return head;
	} 
} 

int Insert(PNode rt,int data){
	// 申请新节点的空间 
	PNode NewNode = (PNode )malloc(sizeof(Node));
	if(!NewNode)			// 申请失败的情况 
		return 0;
	else{					// 申请成功的情况
		NewNode->data = data;		// 节点数据赋值 
		NewNode->next = rt->next;	// 令新节点的next指向表头指向的节点 
		rt->next = NewNode;			// 令表头指向新节点 
		return 1;
	} 
}

int Insert_i(PNode rt,int i,int data){
	// 申请新节点空间
	PNode NewNode = (PNode )malloc(sizeof(Node));
	if(!NewNode)					// 申请空间失败的情况 
		return 0; 
	else{							// 申请成功的情况 
		NewNode->data = data;		// 节点数据赋值 
		int index = 0;
		PNode pr = rt;				// pr的代表的是第i个节点的地址 
		while(pr->next != NULL){	//这个循环的作用是使pr获取第i个节点的地址 
			index++;
			pr = pr->next;
			if(index == i)break;
		}
		NewNode->next = pr->next;	//获取地址之后进行修改，类似于头插法的方式 
		pr->next = NewNode;
		return 1;
	}
} 

int Delete(PNode rt,int data){
	PNode pre = rt,add = rt;
    // 查找链表中是否含有此元素
	while(add->next != NULL){
		pre = add;
		add = add->next;
		if(add->data == data)break;
	}
	if(add->data != data || add == rt)return 0; // 未找到的情况
	else{										// 找到的情况
		pre->next = add->next;			// 直接让前驱指向第i个元素的后继
		free(add);						// 释放该节点空间
		return 1;
	}
} 

int Delete_i(PNode rt,int i){
	PNode pre = rt,add = rt;
	int index = 0;
	while(add->next != NULL){
		index++;
		pre = add;
		add = add->next;
		if(index == i)break;		// 找到第i个元素
	}
	if(index != i)return 0;			//i大于链表长度或者i<= 0的情况
	else{
		pre->next = add->next;		// 直接让前驱指向第i个元素的后继
		free(add);					// 释放第i个节点
		return 1;					// 删除成功
	}
}

PNode find(PNode rt,int data){
	PNode pr = rt;
	while(pr->next != NULL){
		pr = pr->next;
		if(pr->data == data)break;	// 找到的情况
	}
	if(pr->data != data || pr == rt)return NULL;	// 未找到或者链表为空的情况
	else return pr;
}

// 遍历输出链表全部元素 
void Tra(PNode rt){
	PNode pr = rt;
	while(pr->next != NULL){
		pr = pr->next;
		printf("%d ",pr->data);
	}
	printf("\n");
}

int main(){
	
	PNode L1,L2;
	// 初始化两个链表 
	L1 = Init();
	L2 = Init();
	if(L1)printf("链表一创建成功。\n");
	if(L2)printf("链表二创建成功。\n");
	
	int i ;
	printf("L1使用头插法插入1~10:\n");
	for(i = 1; i <= 10; i++)
		Insert(L1,i);
	Tra(L1);
	printf("L2使用位置插入10~19:\n");
	for(i = 10; i <= 19; i++)
		Insert_i(L2,i-9,i);
	Tra(L2);
	
	printf("删除L1元素1、2、3、4、5：\n");
	for(i = 1; i <= 5; i++)
		Delete(L1,i);
	Tra(L1);
	printf("删除L2第10个元素：\n");
	Delete_i(L2,10);
	Tra(L2);
	return 0;
}

