/////////////////////////////////////////////////////////////////////////////////
// DependencyAnalysis.cpp - Demonstrate how to start developing dependency analyzer       //
//                                                                             //
// ver 2.0                                                                     //
// -----------------------------------------------------------------------     //
// copyright � Triveni Ashok Naik, 2017                                        //
// Source: Jim Fawcett, CSE687 - Object Oriented Design, Spring 2017           //
// -----------------------------------------------------------------------     //
// Language:    Visual C++, Visual Studio 2015                                 //
// Platform:    Lenovo Y40, Core i7, Windows 8.1 SP1                           //
// Application: Spring Project,CSE 687,2017                                    //
// Author:      Triveni Ashok Naik, Syracuse University                        //
//              SUID: 406461644, trnaik@syr.edu                                //
///////////////////////////////////////////////////////////////////////////////

#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "../Tokenizer/Tokenizer.h"
#include "../NoSqlDb1/NoSqlDb1.h"
#include "../TypeTable/TypeTable.h"
#include "../Utilities/Utilities.h"
#include "../DependencyAnalysis/DependencyAnalysis.h"

using Key = std::string;
using Keys = std::vector<std::string>;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;

using Helper = Utilities::StringHelper;
using namespace Utilities;


//<----------------------------------------------------Demonstraion of TestStub-------------------------------------------------------->
#ifdef TEST_DEPANAL
	int main(int argc, char* argv[])
	{
		title("Testing Dependency class");
		Depenedency doc; std::vector<std::string> token_;
		token_ = doc.parse(argv[1], true);
		doc.maketree(token_);
		std::cout << "  " << doc.returnDocelem()->toString();
		std::cout << "\n\n";
		return 1;
}

#endif