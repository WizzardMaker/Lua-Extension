// ENIGMA parser.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace boost::filesystem;
using namespace std;

vector<path> searchdir(string dir);
void writefunction(string dir, string function, string name);
bool checkfunction(string line);
vector<string> searchfile(string dir);
//void logger(string str);
void logger(path str);
//void logger(const char str);

int main()
{
	path pa("C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser/ENIGMA parser");
	vector<string> functions;
	vector<string> delpaths;
	delpaths.push_back("C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser/ENIGMA parser\\boost");
	path lastdir = "";
	startsearch : //
		typedef vector<path> vec;
		vec count = searchdir(pa.string());
		logger(lastdir);
		pa = "";
		logger(string("started search"));

		for (vec::const_iterator it(count.begin()); it != count.end(); ++it)
		{
			//logger("pstring init");
			path pstring = *it;
			string file = pstring.string();
			//logger("log");
			//logger(file);
			if (pstring.extension() == ".h" && find(delpaths.begin(), delpaths.end() - 1, pstring.parent_path()) == delpaths.end()){
				logger(file);
				//searchfile("test.h");
			}
			//logger("is dir");
			if (is_directory(pstring) && pa == "" && find(delpaths.begin(), delpaths.end(), pstring) == delpaths.end()){
				pa = pstring;
				lastdir = pa;
				delpaths.push_back(pstring.string());
				//logger(delpaths.back());
			}
		}
		logger("pa =");
		logger(pa);
		if (pa == lastdir.parent_path()){
			logger("pa == lastdir!");
			lastdir = lastdir.parent_path();
		}
		logger(lastdir);
		if (pa != ""){
			logger("Next folder");
			logger(pa.string());
			goto startsearch;
		}else{
			//logger(lastdir);
			lastdir = lastdir.parent_path ();
			if (lastdir != "C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser"){
				logger("No folder, head back!");
				pa = lastdir;
				logger(lastdir);
				goto startsearch;
			}
		}
	return 1;
}

void writefunction(string dir, string function, string name){
	std::ofstream file;
	file.open(dir, ios::app);
	file << "extern" << function << ";\n";
	file << "state.set( \"";
	file << name;
	file << "\" , &";
	file << name;
	file << " );\n";
	file.close();
	return;
}

vector<string> searchfile(string dir){
	vector<string> function;
	string line;
	string name;
	int count = 0;
	int lines = 0;
	bool namesp = false;

	std::ifstream file;
	file.open(dir);

	//ofstream filed;
	//filed.open("test.txt", ios::app);
	function.push_back("");

	while (std::getline(file, line)){
		lines++;
		//filed << "\n" + line;
		if (line.find("}") != string::npos && namesp == true){
			namesp = false;
			logger(string("\n Found end at line: "));
			///filed << lines;
		}
		if (namesp == true && checkfunction(line)){
			logger(string("Found function at line:"));
			//filed << ;
			string functionstr = line.substr(0,line.find(";"));
			function.push_back(functionstr);
			count++;
			name = functionstr.substr(0,line.find_first_of("("));
			string namesub = name.substr(name.find_last_of(" ") + 1);
			function.push_back(namesub);
			count++;

		}
		if (line.find("namespace enigma_user") != string::npos){
			namesp = true;
			logger(string("Found namespace at line:"));
		}
	}

	file.close();
	for (int i = 1; i < (count); i++){
		string fname = function.at(i);
		i++;
		string name = function.at(i);
		writefunction("C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser/ENIGMA parser/test.txt", fname, name);
	}

	return function;
}

bool checkfunction(string line){
	if (line.empty() == true){
		return false;
	}
	if (line.find("//") == 1){
		return false;
	}
	return true;
}

vector<path> searchdir(string dir){
	path p (dir);
	typedef vector<path> vec;             // store paths,
	vec v;
	copy(directory_iterator(p), directory_iterator(), back_inserter(v));
	logger("searchdir() started");
	for (vec::const_iterator it(v.begin()); it != v.end(); ++it)
	{
		//path pstring = *it;
		//string file = pstring.string();
		//logger(file);
	}
	return v;
}

/*void logger(string str){
	std::ofstream file;
	file.open("C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser/ENIGMA parser/log.txt", ios::app);
	file << str << "\n";
	file.close();
}
//void logger(const char str){
	std::ofstream file;
	file.open("C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser/ENIGMA parser/log.txt", ios::app);
	file << str << "\n";
	file.close();
}*/
void logger(path str){
	std::ofstream file;
	file.open("C:/Users/Jonas/Documents/Visual Studio 2013/Projects/ENIGMA parser/ENIGMA parser/log.txt", ios::app);
	file << str << "\n";
	file.close();
}