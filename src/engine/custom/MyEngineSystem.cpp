#include "MyEngineSystem.h"

MyEngineSystem::MyEngineSystem()
{
	if (objectData.empty()) { initData(); }
}

MyEngineSystem::~MyEngineSystem()
{
}

//Create the inital file on MyEngineSystem creation if none exists.
void MyEngineSystem::initData()
{
	ifstream file(fileLoc, ios::in);

	if (file.is_open()) {
		while (getline(file, line)) {
			row.clear();

			std::stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			objectData.push_back(row);
		}
	}

	file.close();
}

//Saves the data of given GameObject but replaces data if object exists
void MyEngineSystem::saveData(GameObject& obj)
{
	string name = obj.name;

	if (!objectData.empty()) {
		if (!checkData(name)) { writeData(obj); }
		else { replaceData(obj); }
	}
	else {
		writeData(obj);
	}

}

//prints the data of given GameObject name
void MyEngineSystem::printData(string& name)
{
	vector<vector<string>>::iterator row;

	int index = 0;

	for (row = objectData.begin(); row != objectData.end(); row++) {
		if (find(row->begin(), row->end(), name) != row->end()) {
			for (int col = 0; col < objectData[index].size(); col++) {
				std::cout << objectData[index][col] << " ";
			}
			std::cout << "\n";

			index++;
		}
		index++;
	}

}

//Returns true or false if data exists
bool MyEngineSystem::checkData(string& name)
{
	vector< vector<string>>::iterator row;

	int index = 0;

	for (row = objectData.begin(); row != objectData.end(); row++) {
		if (find(row->begin(), row->end(), name) != row->end()) {
			for (int col = 0; col < objectData[index].size(); col++) {
			}

			return true;
		}
		index++;
	}

	return false;
}

//Writes the GameObject data to the .csv file
void MyEngineSystem::writeData(GameObject& obj)
{
	ofstream file(fileLoc, ios::app);

	if (file.is_open()) {
		file << obj.name << "," << obj.posX << "," << obj.posY << "," << obj.width << "," << obj.height << "," << obj.score << std::endl;

		file.close();
	}
}

//Replaces the data of existing
void MyEngineSystem::replaceData(GameObject& obj)
{
	//should be curData and not curName
	string curName = obj.name + "," + std::to_string(obj.posX) + "," + std::to_string(obj.posY) + "," + std::to_string(obj.width) + "," + std::to_string(obj.height) + "," + std::to_string(obj.score);
	string _lineInFile;

	string tempFileLoc = "res/temp.csv";

	//Open existing file
	ifstream file;
	file.open(fileLoc);
	//Create temporary file
	ofstream tempFile;
	tempFile.open(tempFileLoc);

	if (file.is_open()) {
		while (file >> _lineInFile) {

			if (_lineInFile.find(obj.name) != string::npos) {
				_lineInFile = curName;
			}

			_lineInFile += "";

			tempFile << _lineInFile << std::endl;
		}

		tempFile.close();
		file.close();
	}

	//Hold file location in char array
	/*
	* Remove the original file and rename temp file to orignal name & location
	*/
	const char* p = fileLoc.c_str();
	remove(p);
	rename("res/temp.csv", p);
}

//Prints the data from .csv from given name and column
string MyEngineSystem::getData(string& name, int column)
{
	vector<vector<string>>::iterator row;

	int index = 0;

	for (row = objectData.begin(); row != objectData.end(); row++) {
		if (find(row->begin(), row->end(), name) != row->end()) {
			for (int col = 0; col < objectData[index].size(); col++) {
				if (col == column) {
					return objectData[index][col];
				}
			}
			std::cout << "\n";

			index++;
		}
		index++;
	}

	return "Name or Column does not exist!";
}


/*for (int row = 0; row < objectData.size(); row++) {
		for (int col = 0; col < objectData[row].size(); col++) {
			std::cout << objectData[row][col] << " ";
		}
		std::cout << "\n";
	}*/

/*
david,yes,55
georgie,female,28
dingdong,wahey,53
will,yoube,23
cor,yeah,19
emily,male,26
suck,ur,190
jessica,ginger,12

*/