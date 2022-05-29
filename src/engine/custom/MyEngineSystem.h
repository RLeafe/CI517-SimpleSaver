#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"
#include "../custom/GameObject.h"

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using std::vector;
using std::string;
using std::fstream;
using std::ios;
using std::ofstream;
using std::ifstream;

struct Result {
	float x1;
	float x2;
};

class MyEngineSystem {
	friend class XCube2Engine;
	private:
		string fileName = "saveData.csv";
		string fileLoc = "res/" + fileName;

		vector<vector<string>> objectData;
		vector<string> row;
		string line, word;

	public:
		string name;
		string gender;
		int age;

		void initData();
		void saveData(GameObject& obj);
		void printData(string& name);

		bool checkData(string& name);
		void writeData(GameObject& obj);
		void replaceData(GameObject& obj);

		string getData(string& name, int column);

		MyEngineSystem();
		~MyEngineSystem();
};

#endif