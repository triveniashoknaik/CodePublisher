/////////////////////////////////////////////////////////////////////////////////
// Strong Component.h - Demonstrate the strongly connected components       //
//                                                                             //
// ver 2.0                                                                     //
// -----------------------------------------------------------------------     //
// copyright © Triveni Ashok Naik, 2017                                        //
// Source: Jim Fawcett, CSE687 - Object Oriented Design, Spring 2017           //
// -----------------------------------------------------------------------     //
// Language:    Visual C++, Visual Studio 2015                                 //
// Platform:    Lenovo Y40, Core i7, Windows 8.1 SP1                           //
// Application: Spring Project,CSE 687,2017                                    //
// Author:      Triveni Ashok Naik, Syracuse University                        //
//              SUID: 406461644, trnaik@syr.edu                                //
/////////////////////////////////////////////////////////////////////////////////

//Package Operation

/* This package is very important. This package uses an algorithm called as Tarjan's Algorithm which uses graph class and hence defines
  all the strong components. The strong components are the ones in which each node has a path to every another node in the graph. Hence
  here each node represents the file that is present here. Hence in this case it repesents how each file is connected to another file 
  in the package and hence are present in the same component.This is just an extension of the Dependency Analysis package which states
  that how the files that are dependent on each other and are represented in the form of component. To represent in the form of component 
  Tarjan's algorithm is used to detremine how each file is connected to each other.The strongly connected component is got through using 
  the DFS traversal.Through this package we will get to know the components that are present and how thety are related to each file. This 
  makes the strongly connected component be used efficiently to know the file structure abd its dependency.

*/
//Function Prolouges
/* SCC()       -> a function that displays the strongly connected component among he files that are present.
SCCUtil()      -> traverses through the path and hence gives the pathname of the file.

Public Interface :
== == == == == == == == =
Graph Class > ---- >

Build Process :
== == == == == == ==
Required files
- ActionandRules.h
- CppProperties.h
Build commands
- devenv Project2_OOD.sln
- cl / EHsc / DTEST_TOKENIZER tokenizer.cpp / link setargv.obj

Maintenance History :
== == == == == == == == == ==
ver 2.0 : 11 Mar 17
- second release
---------------------------- -
ver 1.0 :
-first release
------------------------------
== == == == == == == == == == */

#pragma once

// A C++ program to find strongly connected components in a given
// directed graph using Tarjan's algorithm (single DFS)
#include<iostream>
#include <list>
#include<algorithm>
#include <stack>
#define NIL -1
using namespace std;

// A class that represents an directed graph
class Graph
{
	int V;                                 // No. of vertices
	list<int> *adj;                      // A dynamic array of adjacency lists

					                         // A Recursive DFS based function used by SCC()
	void SCCUtil(int u, int disc[], int low[],
		stack<int> *st, bool stackMember[]);
public:
	Graph(int V);                          // Constructor
	void addEdge(int v, int w);          // function to add an edge to graph
	void SCC();                           // prints strongly connected components
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
	bool stackMember[])
{ static int time = 0;                // A static variable is used for simplicity, we can avoid use// of static variable by passing a pointer.
  disc[u] = low[u] = ++time; st->push(u); stackMember[u] = true;
                                                            // Go through all vertices adjacent to this
  list<int>::iterator i; for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{ int v = *i;  // v is current adjacent of 'u'
        if (disc[v] == -1)
		{ SCCUtil(v, disc, low, st, stackMember);
			low[u] = min(low[u], low[v]);}}
	// head node found, pop the stack and print an SCC
	int w = 0;  // To store stack extracted vertices
	if (low[u] == disc[u])
	{while (st->top() != u){
			w = (int)st->top();cout << w << " ";stackMember[w] = false;st->pop();}
		w = (int)st->top();cout << w << "\n";stackMember[w] = false;st->pop();	}}
// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC()
{   int *disc = new int[V]; int *low = new int[V]; bool *stackMember = new bool[V];stack<int> *st = new stack<int>();

	// Initialize disc and low, and stackMember arrays
	for (int i = 0; i < V; i++)
	{  disc[i] = NIL; low[i] = NIL; stackMember[i] = false;}
	for (int i = 0; i < V; i++)
		if (disc[i] == NIL)
			SCCUtil(i, disc, low, st, stackMember);
}