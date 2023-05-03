#include "stdio.h"
#include "malloc.h"
#include "bilink1.h"

/*����ǰ���������һ�Ÿ����Ķ�����*/
bintree createbintree() {
	char ch;
	bintree t;
	if ((ch = getchar()) == '#') {
		t = NULL;
	}
	else {
		t = (bintnode*)malloc(sizeof(bintnode));
		if (t) {
			t->data = ch;
			t->lchild = createbintree();
			t->rchild = createbintree();
		}
	}
	return t;
}


int numofonde(bintree t) {
	if (t == NULL) {
		return 0;
	}
	else {
		return(numofonde(t->lchild) + numofonde(t->rchild) + 1);
	}
}

int depth(bintree t) {
	int h, lh, rh;
	if (t == NULL) {
		h = 0;
	}
	else
	{
		lh = depth(t->lchild);
		rh = depth(t->rchild);
		if (lh >= rh) {
			h = lh + 1;
		}
		else {
			h = rh + 1;
		}
		return h;
	}
}

int main() {
	int h, num;
	bintree t;
	printf("�뿪ʼ������������ʹ��ǰ�������ʽ������\n");
	t = createbintree();
	h = depth(t);
	printf("��ö��������Ϊ��%d\n", h);
	num = numofonde(t);
	printf("��ö�������Ҷ�ӽ����Ϊ��%d\n", num);
}
