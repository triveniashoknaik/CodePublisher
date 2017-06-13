/////////////////////////////////////////////////////////////////////////////////
// CodePublisher.cpp - Demonstrates the usage of the code in the web browser     //
//                                                                             //
// ver 1.0                                                                     //
// -----------------------------------------------------------------------     //
// copyright © Triveni Ashok Naik, 2017                                        //
// Object Oriented Design, Spring 2017                                         //
// -----------------------------------------------------------------------     //
// Language:    Visual C++, Visual Studio 2015                                 //
// Platform:    Lenovo Y40, Core i7, Windows 8.1 SP1                           //
// Application: Spring Project,CSE 687,2017                                    //
// Author:      Triveni Ashok Naik, Syracuse University                        //
//              SUID: 406461644, trnaik@syr.edu                                //
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include "CodePublisher.h"

//<--------------------------------------Demonstration of TestStub--------------------------------------------------------------->
#ifdef TEST_CODEPUBLISHER
int main()
{
	File f1, f2;
	f1 = "CodePublisher.cpp";
	f2 = "CodePublisherNew.h";

	std::vector<std::string> v;
	v.push_back(f1);
	v.push_back(f2);

}
#endif