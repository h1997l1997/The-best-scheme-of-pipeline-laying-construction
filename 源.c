
#define _CRT_SECURE_NO_DEPRECATE  //在vs2017环境中，加入此句才可使用scanf函数
#include <stdio.h>
#include <stdlib.h>
typedef struct Edge {
	int x, y;
	double val;
} Edge;
Edge edge[1000];
Edge ans[1000];
int compare(const void *p1, const void *p2) {		//比较
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
	printf("实验三：管道铺设施工的最佳方案问题\n姓名：张世博\n学号：031620316\n=========Enter开始程序==========\n");
	system("pause");
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		char ch1[2], ch2[2];
		double h;
		getchar();
		scanf("%s %s %lf", ch1, ch2, &h);
		edge[i].x = ch1[0] - 'A' + 1;	//讲英文字符转化为数字坐标运算
		edge[i].y = ch2[0] - 'A' + 1;
		edge[i].val = h;				

	}
	
	qsort(edge, m, sizeof(edge[0]), compare);		//将edge按照val值进行数组排序
	for (int i = 0; i < m; i++) {
	  printf("%d %d %f\n", edge[i].x, edge[i].y,edge[i].val);
	 }
	int cnt = 0;						//计数
	//double sum = 0;						//和值
	for (int i = 0; i < m; i++) {				
		int x = edge[i].x;				
		int y = edge[i].y;
		//x = find(x);
		//y = find(y);
		if (x != y) {
			//f[x] = y;
			ans[cnt++] = edge[i];
			//sum += edge[i].val;			//将最小的路径val累加
		}
		if (cnt == n - 1) break;		//排序完成
	}
	for (int i = 0; i < cnt; i++) {
		printf("%c %c %f\n", ans[i].x + 'A' - 1, ans[i].y + 'A' - 1, ans[i].val);
	}
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);			//显示运行时间
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