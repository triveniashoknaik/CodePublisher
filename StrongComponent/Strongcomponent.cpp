/////////////////////////////////////////////////////////////////////////////////
// Strong Component.cpp - Demonstrate the strongly connected components       //
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

#include<iostream>
#include "../StrongComponent/Strongcomponent.h"

// Driver program to test the function

int main()
{
	cout << "\nSCCs in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0); g1.addEdge(0, 2); g1.addEdge(2, 1); g1.addEdge(0, 3); g1.addEdge(3, 4);
	g1.SCC();

	cout << "\nSCCs in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1); g2.addEdge(1, 2); g2.addEdge(2, 3);
	g2.SCC();

	cout << "\nSCCs in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);g3.addEdge(1, 2);g3.addEdge(2, 0);g3.addEdge(1, 3);g3.addEdge(1, 4);g3.addEdge(1, 6);g3.addEdge(3, 5);g3.addEdge(4, 5);
	g3.SCC();

	cout << "\nSCCs in fourth graph \n";
	Graph g4(11);
	g4.addEdge(0, 1); g4.addEdge(0, 3);
	g4.addEdge(1, 2); g4.addEdge(1, 4);
	g4.addEdge(2, 0); g4.addEdge(2, 6);
	g4.addEdge(3, 2);
	g4.addEdge(4, 5); g4.addEdge(4, 6);
	g4.addEdge(5, 6); g4.addEdge(5, 7); g4.addEdge(5, 8); g4.addEdge(5, 9);
	g4.addEdge(6, 4);
	g4.addEdge(7, 9);
	g4.addEdge(8, 9);
	g4.addEdge(9, 8);
	g4.SCC();

	cout << "\nSCCs in fifth graph \n";
	Graph g5(5);
	g5.addEdge(0, 1);g5.addEdge(1, 2);g5.addEdge(2, 3);g5.addEdge(2, 4);g5.addEdge(3, 0);g5.addEdge(4, 2);
	g5.SCC();

	return 0;
}
