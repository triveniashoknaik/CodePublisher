#pragma once
#pragma warning( disable : 4129)

/////////////////////////////////////////////////////////////////////////////////
// DependencyAnalysis.h - Demonstrate how to start developing dependency analyzer//
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
/*This package demonstrates how an dependency analyzer works.This package is responsible for getting all the files and hence noting the
dependency of each file on another.Basically this file actually demonstrates how an dependency analyzer works.It actually shows how
one file is dependent on another.The basic knowledge of how this is obtained  is to get all the tokens from the tokenizer and hence
match those tokens with the typename in the typetable. If the match is found then it takes the files that it is dependent on. This dependency
analyzer also shows all the hiddenfiles that it is dependent on. This is again a very important package as it is involved in finding
the dependencies of each file in the package.
*/

//Function Prolouges
/* show() -> shows all the files that it is dependent on.
count()   -> counts the no of files that are present
save()    -> saves all the files in the database.
value()   -> shows the multiple files that are present here.
keys()    -> find all the typenames that are present here.
Public Interface :
== == == == == == == == =
Dependency Class > ---- >

Build Process :
== == == == == == ==
Required files
- Typetable.h
- NoSqlDb.h
- Tokenizer.h
Build commands
- devenv Project2_OOD.sln
- cl / EHsc / DTEST_TOKENIZER tokenizer.cpp / link setargv.obj

Maintenance History :
== == == == == == == == == ==
ver 3.0 : 6 April 17
- third release
------------------------------
ver 2.0 : 11 Mar 17
- second release
---------------------------- -
ver 1.0 :
-first release
------------------------------
== == == == == == == == == == */
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include"../CodePublisher/CodePublisher.h"
#include "../Tokenizer/Tokenizer.h"
#include "../NoSqlDb1/NoSqlDb1.h"
#include "../TypeTable/TypeTable.h"
#include "../Utilities/Utilities.h"
//<--------------------------------------Description of class and how dependency works---------------------------------->
class workdo
{public:
Dependency taskDo(typeanalysis& db1, Dependency &db, Files allfiles);};
 Dependency workdo::taskDo(typeanalysis& db1, Dependency &db, Files allfiles)
{using databasetable = std::map<std::string, std::vector<std::map<std::string, std::string>>>;
Keys keystype;std::unordered_map<Key, Key> temp;for (auto kv : db1)              //To push all the contents of an unordered map to a database
{keystype.push_back(kv.first);for (auto x : kv.second)
{ for (auto y : x){temp[y.first] = y.second; }}}
//<-----------------------------------------Function to all the files to get and match it with the tokens---------------->
ElementItem elemitem;CodePublisher p;
   for (File f : allfiles){try
   {std::string file = FileSystem::Path::getName(f);  //to get all the files from the filesystem
	std::ifstream in(f);if (!in.good())
	{std::cout << "\n  can't open " << file << "\n\n";	}
	Scanner::Toker toker; toker.returnComments(false); toker.attach(&in);
	do{ std::string tok = toker.getTok();   //gets all the tokens and matches with the typename
	for (std::string key : keystype)
	{ if (key == tok){std::vector<std::map<std::string, std::string>> vec = db1[key];
//<-------------------------Function to get all the files and hence store it in an vector------------------------------------>
	for (std::map<std::string, std::string> cv : vec)
   {for (auto g : cv){if (g.first == "file"){  
	elemitem.childrenList.push_back(g.second);std::sort(elemitem.childrenList.begin(), elemitem.childrenList.end());
	elemitem.childrenList.erase(std::unique(elemitem.childrenList.begin(), elemitem.childrenList.end()), elemitem.childrenList.end());
	db.save(file, elemitem);p.codepublish(f, elemitem);	}}}}}} while (in.good());}
//<------------------------------------------catch statements to handle exceptions---------------------------------------------------------->
	catch (std::logic_error& ex)
			{std::cout << "\n hello  dependency"; std::cout << "\n  " << ex.what();
			}}return db; }

