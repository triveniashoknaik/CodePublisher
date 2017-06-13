#pragma warning( disable : 4503)

/////////////////////////////////////////////////////////////////////////////////
// TypeTable.cpp - Demonstrate how to start developing dependency analyzer       //
//                                                                             //
// ver 3.0                                                                     //
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

#include "../Parser/ActionsAndRules.h"
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include "../Typetable/Typetable.h"

//------------------------------------------------------------Demonstration of Test Stub---------------------------------------------------->
#ifdef TEST_TYPE
	int main()
	{
		title("Testing TypeAnal class");
		if (pchild->type_ == "function")
		{
			std::map<std::string, std::string> keyValue;

			keyValue["namespace"] = pNode->name_;
			keyValue["type"] = pchild->type_;
			keyValue["file"] = pchild->package_;

			std::vector<std::map<std::string, std::string>> element = db1[pchild->name_];
			element.push_back(keyValue);
			db1[pchild->name_] = element;
		}
	}
}
#endif