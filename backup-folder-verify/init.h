#pragma once
#include <iostream>
#include <filesystem>

class File {
private:
	std::filesystem::path m_path;
	std::string m_hash = "";
	int last_change = 0;

public:
	File(std::filesystem::path path, std::string hash = "")
		: m_path{ path }
		, m_hash{ hash }
	{
	}

	std::string get_hash() { return m_hash; }
	std::filesystem::path get_path() { return m_path; }
	void print() { std::cout << "\n Path: " << m_path << "\n Source Hash: " << m_hash; }
	//void set_sourcehash(char* hash)const { m_source_hash = hash; }
};

void Init();
std::vector<File> ScanDirectory(std::filesystem::path path);
extern bool debug;
