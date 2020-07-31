#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

/* 조건
- 점심시간은 1시간이고 그동안 고객은 15초에 1명씩 주문을 하는 것으로 간주
- 한 명의 고객은 하나의 버거 만을 주문
- 주문하는 메뉴에는 가중치 X, 모든 고객은 무작위로 메뉴 선택
- 햄버거를 만드는 사람은 1명, 동시에 둘이상의 버거 생산 X
- 주문한 메뉴를 받을 다음 고객은 대기실에서 나와서 대기
*/


#define CUS_COME_TERM 15 // 고객의 주문 간격 : 초 단위

#define CHE_BUR 0  // 치즈버거 상수
#define BUL_BUR 1 // 불고기버거 상수
#define DUB_BUR 2 // 더블버거 상수

#define CHE_TERM 12 // 치즈버거 제작 시간 : 초 단위
#define BUL_TERM 15 // 불고기버거 "
#define DUB_TERM 24 // 더블버거 "

int main(void)
{
	int makeProc = 0; // 햄버거 제작 진행상황
	int  cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheOrder += 1;
				break;

			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulOrder += 1;
				break;

			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}

		if (makeProc <= 0 && !QIsEmpty(&que)) // 햄버거가 다 만들어지고 주문이 있는 경우에 새로운 버거 생산!
			makeProc = Dequeue(&que); // 대기실에서 나와서 대기

		makeProc--; // 햄버거가 사이클 돌때마다 1초씩 완성됨
	}

	printf("Simulation Report! ------------------------ \n");
	printf(" - Cheese burger: %d \n", cheOrder); 
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN); // QUE_LEN의 크기를 바꾸어서 대기실의 크기조정가능
	return 0;
}