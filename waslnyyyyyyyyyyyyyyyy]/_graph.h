#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class _graph
{
	map<string, int>cost;
	map<string, vector<pair<string, int>>>graph;

public:
	void createGraph();
	void displayGraph();
	void updateGraph();
	void dijkstra(string, string);
	void removegraph();
	_graph();
	~_graph();
};

