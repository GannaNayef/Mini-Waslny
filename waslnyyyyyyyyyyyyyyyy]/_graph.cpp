#include "_graph.h"
void _graph::removegraph(){

	graph.clear();
}
void _graph::createGraph(){
	int numNodes, numEdges;
	cout << "Number Of Nodes : ";
	cin >> numNodes;
	cout << "Number Of Edges : ";
	cin >> numEdges;
	string node1, node2;
	int weight;
	for (int i = 0; i < numEdges; i++)
	{
		cout << "First Node : ";
		cin >> node1;
		cout << "Second Node : ";
		cin >> node2;
		cout << "Cost : ";
		cin >> weight;
		graph[node1].push_back(make_pair(node2, weight));
		graph[node2].push_back(make_pair(node1, weight));
		cost[node1] = -1;
		cost[node2] = -1;
	}
	system("cls");

}
void _graph::displayGraph(){
	map<string, vector<pair<string, int>>>::iterator it = graph.begin();
	map<string, bool>visited;
	while (it != graph.end())
	{
		vector<pair<string, int>>temp;
		visited[it->first] = 1;
		cout << it->first;
		typedef vector<pair<string, int>>::const_iterator vecit;
		for (vecit vit = it->second.begin(); vit != it->second.end(); vit++)
		{
			if (visited[vit->first])
			{
				cout << " -> " << vit->first << "(" << vit->second << ")";
			}
		}
		for (vecit vit = it->second.begin(); vit != it->second.end(); vit++)
		{
			if (!visited[vit->first])
			{
				cout << " -> " << vit->first << "(" << vit->second << ")";
			}
		}
		cout << endl;
		
		it++;
	}

}
void _graph::updateGraph(){
	string node1, node2;
	int _cost, num;
	cout << "If You Want To Add New Node 1 : " << endl << "If You Want To Delete Edge 2 : " << endl << "If You Want To Add Edge 3 :" << endl << "If You Want To Delete Node 4 : " << endl;
	cin >> num;
	system("cls");
	if (num == 1)
	{
		cout << "The Node You Want To Add To : ";
		cin >> node1;
		cout << "The New Added Node : ";
		cin >> node2;
		cout << "The Cost : ";
		cin >> _cost;
		graph[node1].push_back({ node2, _cost });
		graph[node2].push_back({ node1, _cost });
		cost[node2] = -1;
	}
	else if (num == 2)
	{
		cout << "The First Node : ";
		cin >> node1;
		cout << "The Second Node : ";
		cin >> node2;
		for (int i = 0; i < graph[node1].size(); i++)
		{
			if (graph[node1][i].first == node2)
			{
				graph[node1].erase(graph[node1].begin() + i);
				break;
			}
		}
		swap(node1, node2);
		for (int i = 0; i < graph[node1].size(); i++)
		{
			if (graph[node1][i].first == node2)
			{
				graph[node1].erase(graph[node1].begin() + i);
				break;
			}
		}
	}
	else if (num == 3)
	{
		cout << "First Node : ";
		cin >> node1;
		cout << "Second Node : ";
		cin >> node2;
		cout << "Cost : ";
		cin >> _cost;
		graph[node1].push_back({ node2, _cost });
		graph[node2].push_back({ node1, _cost });
		cost[node1] = -1;
		cost[node2] = -1;
	}
	else{
		cout << "Enter The To Be Deleted Node : ";
		cin >> node1;
		graph.erase(node1);
		map<string, vector<pair<string, int>>>::iterator it = graph.begin();
		while (it != graph.end())
		{
			typedef vector<pair<string, int>>::const_iterator vecit;
			for (vecit vit = it->second.begin(); vit != it->second.end(); vit++)
			{
				if (vit->first == node1)
				{
					graph[it->first].erase(vit);
					break;
				}
			}
			it++;
		}
	}
	system("cls");

}
void _graph::dijkstra(string src , string des){
	priority_queue<pair<int, string>>sh;
	map<string, string> prv;
	sh.push({ 0, src });
	prv[src] = src;
	cost[src] = 0;
	while (!sh.empty())
	{
		string node = sh.top().second;
		int c = sh.top().first;
		sh.pop();
		for (int i = 0; i < graph[node].size(); i++)
		{
			if (cost[graph[node][i].first] == -1 || c + graph[node][i].second < cost[graph[node][i].first])
			{
				prv[graph[node][i].first] = node;
				cost[graph[node][i].first] = c + graph[node][i].second;
				sh.push({ cost[graph[node][i].first], graph[node][i].first });
			}
		}
	}
	stack<string>path;
	string temp = des;
	while (prv[temp] != temp)
	{
		path.push(temp);
		temp = prv[temp];
	}
	path.push(prv[temp]);
	bool found=0;
	for (int i = 0; i < graph[src].size(); i++)
	{
		if (graph[src][i].first == des)
		{
			found = 1;
			break;
		}
	}
	if (cost[des] == -1 || found == 0)
	{
		cout << "The Path Doesn't exist "<<endl;
	}
	else{
		cout << "The Minimum Cost : " << cost[des] << endl << "The Shortest Path : ";
		while (path.top() != des)
		{
			cout << path.top() << " -> ";
			path.pop();
		}
		cout << path.top() << endl;
		path.pop();
	}
	map<string, int>::iterator it;
	it = cost.begin();
	while (it != cost.end())
	{
		it->second = -1;
		it++;
	}
}



_graph::_graph()
{
}


_graph::~_graph()
{
}
