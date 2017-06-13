/////////////////////////////////////////////////////////////////////////////////
// CodePublisher.h - Demonstrates the usage of the code in the web browser     //
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

//Package Operation
/* This package is mainly about generating web pages using C++. This package is responsible for getting all
the dependencies from Dependency.h package.Once the dependency is obtained for a particular file, then it will
be very helpful for generating links for the files that are dependent on in the browser.This package is mainly 
responsible for this property. The other one thing that is being done here is that generating of web pages. Also 
the property of collapsing is also used here. This is done using the javascript and the CSS properties.
The collapsing is seen to be active for all the class bodies,global functions and the methods.
*/

//Function Prolouges
/*codepublish() => Helps in generating web pages with the dependency links shown.
  showhomepage() => This homepage is helpful in genearting a home webpage with the file links displayed.
*/

/*Public Interface :
== == == == == == == == =
CodePublisher Class > ---- >

Build Process :
== == == == == == ==
Required files
- NoSqlDb.h
- Tokenizer.h
- Utilties.h

Build commands
- devenv Project3_OOD.sln
- cl / EHsc / DTEST_TOKENIZER tokenizer.cpp / link setargv.obj

Maintenance History :
== == == == == == == == == ==
ver 1.0 :
-first release - 4/5/2017
------------------------------
== == == == == == == == == == */


#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include <iomanip>
#include "../NoSqlDb1/NoSqlDb1.h"
#include "../Tokenizer/Tokenizer.h"
#include "../Utilities/Utilities.h"
#include "../Typetable/Typetable.h"

using File = std::string;
using Files = std::vector<File>;
using namespace CodeAnalysis;

//<---------------------------------------------------
namespace CodeAnalysis
{
	class CodePublisher
	{
		//private:
			//std::string PrepareHeading(std::string& filepath);

	public:
		void codepublish(File file, ElementItem elem);
		void showhomepage(std::string k);

	};

	void CodePublisher::codepublish(File filenew, ElementItem elem)
	{
		std::string path = FileSystem::Path::getPath(filenew);
		std::string file = FileSystem::Path::getName(filenew);

		File newfile = file + ".htm";
		std::ofstream out(newfile);
        std::ifstream in(filenew);
		if (!in.is_open())
		{
			std::cout << "cant open";
		}
		else
		{
			out << "<html>\n<head>\n<script src=\"javascript.js\"></script>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n</head>\n <body>";
			out << "<h3>Dependency</h3>\n<hr/>\n<div class = \"indent\">\n<h4>Dependencies:</h4> \n";
			char c;
			out << "<pre>";
			out << "<br>";

			for (File fname : elem.childrenList)
			{
				std::string semipath = FileSystem::Path::getPath(fname);
				std::string name = FileSystem::Path::getName(fname);
                std::string fpath = name + ".htm";

				out << "<a href = \""; 
				out << fpath;
				out << "\""; 
				out << ">";
				out << name; 
				out << " ==> "; 
				out << fpath;
				out << "</a>";

				out << "<br>"; out << "<br>";

			}

			out << "<br>"; out << "<br>";
			int count = 1;
			while (in.get(c))
			{
				if (in.eof())
					break;
				else  if (c == '<')
					out << "&lt";
				else if (c == '>')
					out << "&gt";
				else if (c == '}')
				{
					out << "}";
				//	out << "<button onclick = \"myFunc" << count << "()\"" << count << ">+</button>";
			
					out << "</div><br><script>function myFunc" << count << "() {var x = document.getElementById('mydiv" << count << "');";
					out << "if(x.style.display == 'none') {x.style.display = 'block';}";
					out << "else {x.style.display = 'none';}} </script>";
					count++;
				}
				else if (c == '{')
				{
					out << "<button onclick = \"myFunc"<< count<<"()\""<<count<<"\n"">+</button>";
						out << "<div id = \"mydiv" << count << "\">";
					out << "{";
				}

				else
					out << c;
			}
			out << "\n</pre>\n</body>\n</html>";

			//out << "/pre";
			//std::string k;
			in.close();
			out.close();
			/*std::string homeLink = k + " ";
			std::wstring wHomwLink = std::wstring(homeLink.begin(), homeLink.end());
			LPCWSTR sw = wHomwLink.c_str();
			ShellExecute(0, 0, sw, 0, 0, SW_SHOW);*/

		}
		return;
	}

	void CodePublisher::showhomepage(std::string k)
	{   
		//std::ostringstream oss;
		std::ofstream as(k + " ");
		std::stringstream st;
		//FileMap fileMap = exec.getFileMap();
		//Files allfiles;
		//st << allfiles;
		
		st << "<html>\n<head>\n<script src=\"javascript.js\"></script>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n</head>\n <body>";
		st << "<h3>CodePublisher</h3>\n<hr/>\n<div class = \"indent\">\n<h4>HOMEPAGE:</h4> \n";

		std::string currentD = FileSystem::Directory::getCurrentDirectory();
		Files files = FileSystem::Directory::getFiles(currentD, "*.htm");

		st << "<ol>";
		for each (auto file in files)
		{
			if (file != "MyHtmlfiles.html")
			{
				st << "<li>";
				std::string dcdc = FileSystem::Path::getPath(file);
				std::string sq = currentD + "\\" + file;

				st << "<a href = \"" + sq + "\">" + file + "</a>";
				st << "</li>";
			}
		}
		st << "</ol>";
		st << "</body></html>";
		as << st.str();
		as.close();

		std::string homeLink = FileSystem::Directory::getCurrentDirectory() + "\\" + "MyHtmlfiles.html";
		std::wstring wHomwLink = std::wstring(homeLink.begin(), homeLink.end());
		LPCWSTR sw = wHomwLink.c_str();
		ShellExecute(0, 0, sw, 0, 0, SW_SHOW);
	}
}
