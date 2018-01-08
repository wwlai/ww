#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include<iomanip>


#include<limits.h>
const int maxWeight = INT_MAX;
const int DeafultVertices = 30;			//������󶥵��� =n

struct Edge
{
	int dest;			//�ߵ���һ������λ��
	int cost;				//���ϵ�Ȩֵ
	Edge * link;	//��һ������ָ��
	Edge() { cost = maxWeight; }
	Edge(int num, int weight) : dest(num), cost(weight), link(NULL) {}
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

struct Vertex
{
	char data;
	Edge *adj;			//�������ͷָ��
};


class Graph
{
public:
	Graph();
	~Graph();
	bool GraphEmpty()const;
	bool GraphFull()const;
	int NumberOfVertices();		//���ص�ǰ������
	int NunberOfEdges();			//���ص�ǰ����
	virtual char getValue(int i) = 0;							//ȡ����i��ֵ
	virtual int getWeight(int v1, int v2) = 0;					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	virtual int getFirstNeighbor(int v) = 0;				//ȡ����v�ĵڸ��ڽӶ���
	virtual int getNextNeighbor(int v, int w) = 0;			//ȡ�ڽӶ���w����һ���ڽӶ���
	virtual bool insertVertex(const char vertex) = 0;			//����һ������vertex
	virtual bool insertEdge(int v1, int v2, int cost) = 0;		//�����(v1,v2),ȨΪcost
	virtual bool removeVertex(int v) = 0;					//ɾȥ����v��������v��صı�
	virtual bool removeEdge(int v1, int v2) = 0;				//ɾȥ��(v1,v2)
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	int getVertexPos(char vertex);				//��������vertex��ͼ�е�λ��
};

#endif // !GRAPH_H