#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;			// ������ 
	struct node *next;	// ָ���� 
	
}; 

typedef struct node Node;
typedef struct node* PNode;  // �ڵ�ָ�� 

PNode Init(){
	
	PNode head = (PNode )malloc(sizeof(Node));
	if(!head)			// �����ڴ�ռ�ʧ�ܵ���� 
		return NULL;
	else{				// ����ɹ������ 
	 	head->next = NULL;			
		return head;
	} 
} 

int Insert(PNode rt,int data){
	// �����½ڵ�Ŀռ� 
	PNode NewNode = (PNode )malloc(sizeof(Node));
	if(!NewNode)			// ����ʧ�ܵ���� 
		return 0;
	else{					// ����ɹ������
		NewNode->data = data;		// �ڵ����ݸ�ֵ 
		NewNode->next = rt->next;	// ���½ڵ��nextָ���ͷָ��Ľڵ� 
		rt->next = NewNode;			// ���ͷָ���½ڵ� 
		return 1;
	} 
}

int Insert_i(PNode rt,int i,int data){
	// �����½ڵ�ռ�
	PNode NewNode = (PNode )malloc(sizeof(Node));
	if(!NewNode)					// ����ռ�ʧ�ܵ���� 
		return 0; 
	else{							// ����ɹ������ 
		NewNode->data = data;		// �ڵ����ݸ�ֵ 
		int index = 0;
		PNode pr = rt;				// pr�Ĵ�����ǵ�i���ڵ�ĵ�ַ 
		while(pr->next != NULL){	//���ѭ����������ʹpr��ȡ��i���ڵ�ĵ�ַ 
			index++;
			pr = pr->next;
			if(index == i)break;
		}
		NewNode->next = pr->next;	//��ȡ��ַ֮������޸ģ�������ͷ�巨�ķ�ʽ 
		pr->next = NewNode;
		return 1;
	}
} 

int Delete(PNode rt,int data){
	PNode pre = rt,add = rt;
    // �����������Ƿ��д�Ԫ��
	while(add->next != NULL){
		pre = add;
		add = add->next;
		if(add->data == data)break;
	}
	if(add->data != data || add == rt)return 0; // δ�ҵ������
	else{										// �ҵ������
		pre->next = add->next;			// ֱ����ǰ��ָ���i��Ԫ�صĺ��
		free(add);						// �ͷŸýڵ�ռ�
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
		if(index == i)break;		// �ҵ���i��Ԫ��
	}
	if(index != i)return 0;			//i���������Ȼ���i<= 0�����
	else{
		pre->next = add->next;		// ֱ����ǰ��ָ���i��Ԫ�صĺ��
		free(add);					// �ͷŵ�i���ڵ�
		return 1;					// ɾ���ɹ�
	}
}

PNode find(PNode rt,int data){
	PNode pr = rt;
	while(pr->next != NULL){
		pr = pr->next;
		if(pr->data == data)break;	// �ҵ������
	}
	if(pr->data != data || pr == rt)return NULL;	// δ�ҵ���������Ϊ�յ����
	else return pr;
}

// �����������ȫ��Ԫ�� 
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
	// ��ʼ���������� 
	L1 = Init();
	L2 = Init();
	if(L1)printf("����һ�����ɹ���\n");
	if(L2)printf("����������ɹ���\n");
	
	int i ;
	printf("L1ʹ��ͷ�巨����1~10:\n");
	for(i = 1; i <= 10; i++)
		Insert(L1,i);
	Tra(L1);
	printf("L2ʹ��λ�ò���10~19:\n");
	for(i = 10; i <= 19; i++)
		Insert_i(L2,i-9,i);
	Tra(L2);
	
	printf("ɾ��L1Ԫ��1��2��3��4��5��\n");
	for(i = 1; i <= 5; i++)
		Delete(L1,i);
	Tra(L1);
	printf("ɾ��L2��10��Ԫ�أ�\n");
	Delete_i(L2,10);
	Tra(L2);
	return 0;
}

