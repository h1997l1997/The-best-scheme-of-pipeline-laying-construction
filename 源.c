
#define _CRT_SECURE_NO_DEPRECATE  //��vs2017�����У�����˾�ſ�ʹ��scanf����
#include <stdio.h>
#include <stdlib.h>
typedef struct Edge {
	int x, y;
	double val;
} Edge;
Edge edge[1000];
Edge ans[1000];
int compare(const void *p1, const void *p2) {		//�Ƚ�
	struct Edge *a = (struct Edge *) p1;
	struct Edge *b = (struct Edge *) p2;
	if (a->val > b->val)
		return 1;
	else if (a->val < b->val)
		return -1;
	else
		return 0;
}

int main() {
	printf("ʵ�������ܵ�����ʩ������ѷ�������\n������������\nѧ�ţ�031620316\n=========Enter��ʼ����==========\n");
	system("pause");
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		char ch1[2], ch2[2];
		double h;
		getchar();
		scanf("%s %s %lf", ch1, ch2, &h);
		edge[i].x = ch1[0] - 'A' + 1;	//��Ӣ���ַ�ת��Ϊ������������
		edge[i].y = ch2[0] - 'A' + 1;
		edge[i].val = h;				

	}
	
	qsort(edge, m, sizeof(edge[0]), compare);		//��edge����valֵ������������
	for (int i = 0; i < m; i++) {
	  printf("%d %d %f\n", edge[i].x, edge[i].y,edge[i].val);
	 }
	int cnt = 0;						//����
	//double sum = 0;						//��ֵ
	for (int i = 0; i < m; i++) {				
		int x = edge[i].x;				
		int y = edge[i].y;
		//x = find(x);
		//y = find(y);
		if (x != y) {
			//f[x] = y;
			ans[cnt++] = edge[i];
			//sum += edge[i].val;			//����С��·��val�ۼ�
		}
		if (cnt == n - 1) break;		//�������
	}
	for (int i = 0; i < cnt; i++) {
		printf("%c %c %f\n", ans[i].x + 'A' - 1, ans[i].y + 'A' - 1, ans[i].val);
	}
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);			//��ʾ����ʱ��
	timeinfo = localtime(&rawtime);
	printf("\n");
	printf("Current local time and date: %s", asctime(timeinfo));

	system("pause");
	return 0;
}
/**
9 15
A B 32.8
A C 44.6
A I 18.2
A H 12.1
B C 5.9
C D 21.3
C E 41.1
C G 56.4
D E 67.3
D F 98.7
E F 85.6
E G 10.5
F I 79.2
H G 52.5
H I 8.7
**/