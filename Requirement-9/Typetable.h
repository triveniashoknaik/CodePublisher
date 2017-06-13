#pragma once
#pragma warning( disable : 4503)

/////////////////////////////////////////////////////////////////////////////////
// TypeTable.h - Demonstrate how to start developing dependency analyzer        //
//
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

/* This is one of the most important packages. This package is involved in storing all the information about the file,
namespace and type of each filename that is present. This typetable holds all information about all the files present
in all the packages.This is one unique package that is created here and is also used for Type Analysis. This package makes use 
of other packages like the Parser, Cpp Properties.This package uses priority queue to store all the filenames that are present.
Another data structure called as the unordered_map is used to store the key/value pair.Since the value for value pair can be more than 
one, vector of value is used. Hence, the information that is used is used to display all the things that are present in the typetable.
This package uses TypeAnal as the class and also does some important operations.
*/

//Function Prolouges
/* dotypeAnal() -> scanning the AST and returns to the database that is created.
   DFS()        -> traverses through the path and hence gives the pathname of the file.
   doDisplay()  -> used to display all the files that are present here.

Public Interface :
== == == == == == == == =
 TypeAnal Class > ---- >

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


#pragma warning(disable : 4503)
#include "../Parser/ActionsAndRules.h"
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#pragma warning (disable : 4101) 
// disable warning re unused variable x, below
using typeanalysis = std::map<std::string, std::vector<std::map<std::string, std::string>>>;
//<----------------------------------------Consists of class TypeAnal-------------------------------------------------->
namespace CodeAnalysis
{
	class TypeAnal
	{
	public:
		using SPtr = std::shared_ptr<ASTNode*>;
		typeanalysis db1;
		std::priority_queue<std::string> namespaceQueue;
		TypeAnal();
		typeanalysis doTypeAnal();

	private:
		void DFS(ASTNode* pNode);
		AbstrSynTree& ASTref_; 
		ScopeStack<ASTNode*> scopeStack_;  
		Scanner::Toker& toker_;
	}; 
	 
	inline TypeAnal::TypeAnal() :
		ASTref_(Repository::getInstance()->AST()),
		scopeStack_(Repository::getInstance()->scopeStack()),
		toker_(*(Repository::getInstance()->Toker()))
	{
		std::function<void()> test = [] { int x; };         // This is here to test detection of lambdas.
	}                                                      // It doesn't do anything useful for dep anal.
//<---------------------------------Function doDisplay to display all the typenames------------------------------------>
	inline bool doDisplay(ASTNode* pNode)
	{
		static std::string toDisplay[] =
		{
			"class", "struct", "enum", "alias", "typedef"
		};

		for (std::string type : toDisplay)
		{
			if (pNode->type_ == type)
				return true;
		}
		return false;
	}
//-------------------------------------Function DFS To traverse and to get the pathname---------------------------------->

	inline void TypeAnal::DFS(ASTNode* pNode)
	{ int i = 0;i++;
		static std::string path = "";
		if (pNode->path_ != path)
		{  std::cout << "\n    -- " << "  This is the path  " << pNode->path_ << "\\ This is the package " << pNode->package_;
			path = pNode->path_;}
    if (pNode->type_ == "namespace")
		{namespaceQueue.push(pNode->name_);}
    if (doDisplay(pNode))
		{std::map<std::string, std::string> keyValue;
//-----------------------------------------Function to display teh type,namespace and the file----------------------------->
			keyValue["namespace"] = namespaceQueue.top();keyValue["type"] = pNode->type_; keyValue["file"] = pNode->package_;
			std::vector<std::map<std::string, std::string>> element = db1[pNode->name_];
			element.push_back(keyValue);db1[pNode->name_] = element;}
		if ((pNode->type_ == "namespace") && (pNode->name_ == "Global Namespace"))
		{for (auto pchild : pNode->children_) 
			{if (pchild->type_ == "function")
				{std::map<std::string, std::string> keyValue;
                  keyValue["namespace"] = pNode->name_;keyValue["type"] = pchild->type_;keyValue["file"] = pchild->package_;
std::vector<std::map<std::string, std::string>> element = db1[pchild->name_];element.push_back(keyValue);db1[pchild->name_] = element;
				}}}
     for (auto pChild : pNode->children_)
		{if (pChild->parentType_ == "namespace")
			{namespaceQueue.push(pNode->name_);}
			DFS(pChild);
			if (pChild->parentType_ == "namespace")
			{namespaceQueue.pop();}}}
//<-------------------------------------------Function to doTypeAnal()----------------------------------------------->
	inline typeanalysis TypeAnal::doTypeAnal()
	{
		std::cout << "\n  starting type analysis:\n";
		std::cout << "\n  scanning AST and displaying important things:";
		std::cout << "\n -----------------------------------------------";
		ASTNode* pRoot = ASTref_.root();
		DFS(pRoot);

		for ( auto x : db1)
		{
			std::cout << "\n\n";
			std::cout << x.first << std::endl;
			std::cout << "\n\n";
			//std::cout << x.second << std::endl;
			for (int i = 0; i < x.second.size(); i++)
				for (auto y : x.second[i])
					std::cout << y.first << "   =>  " << y.second << std::endl;
		}
		return db1;
	}
}


