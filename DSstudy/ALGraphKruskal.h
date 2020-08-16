#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h" // ���� ����Ʈ ��� �׷��� ����
#include "PriorityQueue.h"
#include "ALEdge.h"

// vertex�� �̸��� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV; // ������ ��
	int numE; // ������ ��
	List* adjList; // ������ ����
	int* visitInfo; 
	PQueue pqueue; // ������ ����ġ ���� ����
} ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

// ������ ���� ���
void DFShowGraphVertex(ALGraph* pg, int startV);

// ���� �߰��� �Լ�
void ConKruskalMST(ALGraph* pg); // �ּ� ��� ���� Ʈ���� ����

// ���� �߰��� �Լ�
void ShowGraphEdgeWeightInfo(ALGraph* pg); // ����ġ ���� ���

#endif