#pragma once
#pragma warning( disable : 4715)
/////////////////////////////////////////////////////////////////////////////////
// NoSqlDb.h - Demonstrates how to save data in the database                   //
// ver 2.0                                                                     //
// -----------------------------------------------------------------------     //
// copyright © Triveni Ashok Naik, 2017                                        //
// Source: Jim Fawcett, CSE687 - Object Oriented Design, Spring 2017           //                                                          //
// -----------------------------------------------------------------------     //
// Language:    Visual C++, Visual Studio 2015                                 //
// Platform:    Lenovo Y40, Core i7, Windows 8.1 SP1                           //
// Application: Spring Project,CSE 687,2017                                    //
// Author:      Triveni Ashok Naik, Syracuse University                        //
//              SUID: 406461644, trnaik@syr.edu                                //
/////////////////////////////////////////////////////////////////////////////////

/* This package is involved in storing all the contents of the dependency table in the NoSqlDb. 
This is most important because it is the place where all the contents of the database is being 
stored and hence there are certain operations that are present here. The certain operations that are present here
are the showelement , save,laases called as Dependency which plays a very important role in the project later on.
the save function that is present is involved in saving all the attributes that are present and hence storing it
safely in the database and hence can retrieve it whenever needed.The show element function is the one that is used
to to display the contents of the database.
*/

//Functional Prolougues
/* showelement() -> It is a function that is used to display an element
   showkeys()    -> It is a function that is used to display all the keys that is present
   value()       -> It is a function that is used to display all the value present in the function.


Public Interface :
== == == == == == == == =
Dependency Class > ---- >

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


#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>


using Key = std::string;
using Keys = std::vector<std::string>;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;
//<-----------------------------------A class ElementItem which has two most important components--------------------------->

class ElementItem
{
public:
	std::vector<std::string> childrenList;
	std::string showelement();

};
//--------------------------------------Function to show all the elements present here---------------------------------->

std::string ElementItem::showelement()
{
	// show children when you've implemented them

	std::ostringstream out;
	out.setf(std::ios::adjustfield, std::ios::left);

	out << "\n    " << std::setw(8) << "Children are   " << " : ";
	std::vector<std::string> c = childrenList;

	for (Key k : c)
	{
		out << "\t" << k;
	}
	out << "\n";

	return out.str();
}
//-----------------------------------------------An important Class called as the dependency that is involved in saving all the data------------------------>

class Dependency
{
public:
	Keys keys();
	ElementItem value(File key);
	size_t count();
	void showKeys(Keys list);
	inline bool save(File key, ElementItem elem)
	{
     if (store.find(key) != store.end())
			return false;
		store[key] = elem;
		return true;
	}
	
private:
	using Item = std::pair<File, ElementItem>;
	std::unordered_map<File, ElementItem> store;
};

//<------------------------------------------------Returns the keys of the DataBase------------------------------------------>


std::vector<File> Dependency::keys()
{
	Keys keys;
	for (Item item : store)
	{
		keys.push_back(item.first);
	}
	return keys;
}

//<-------------------------------------------------Returns the ElementItem of a certain key in the Database------------------------------------------>

ElementItem Dependency::value(File key)
{
	if (store.find(key) != store.end())
		return store[key];
	//return ElementItem();
}

//_-----------------------------------------------------Returns count of the DataBase------------------------------------------------------------>

size_t Dependency::count()
{
	return store.size();
}

//---------------------------------------------------------Displays all keys in the Database------------------------------------------------------->

void Dependency::showKeys(Keys list)
{
	for (Key k : list)
	{
		std::cout << "\t" << k << "\n";
	}
	return;
}




