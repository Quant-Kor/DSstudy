#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h" // ���� ����Ʈ ��� �׷��� ����

// vertex�� �̸��� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV; // ������ ��
	int numE; // ������ ��
	List* adjList; // ������ ����
	int* visitInfo;
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

#endif