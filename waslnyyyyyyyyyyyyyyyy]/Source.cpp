#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "_graph.h"
using namespace std;


void main()
{
	_graph graph;
	int n;
	graph.createGraph();
	while (true)
	{
		cout << "Which Function Do You Like To Be Performed : " << endl;
		cout << "To Update Graph 1 :" << endl << "To Delete graph 2 : " << endl << "To Display Graph 3 : " << endl << "To Find The Shortest Path Between Two Cities 4 : " << endl;
		cin >> n;
		system("cls");
		if (n == 1)
		{
			graph.updateGraph();
		}
		else if (n == 2)
		{
			graph.removegraph();
			char c;
			cout << "Do You Want To Add Another Graph : (y/n)";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				system("cls");
				graph.createGraph();
			}
			else{
				break;
			}
		}
		else if (n == 3)
		{
			graph.displayGraph();
		}
		else{
			cout << "Enter Your Current Position : ";
			string city1, city2;
			cin >> city1;
			cout << "Enter Your Desired Destination : ";
			cin >> city2;
		graph.dijkstra(city1, city2);
		}
		char ch;
		cout << "Do You Want To Exit ?(y/n) ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			break;
		}
		system("cls");
	}
}
