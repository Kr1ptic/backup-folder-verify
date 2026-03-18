#pragma once
#include <iostream>
#include <filesystem>

void Init();
void ScanDirectory();
extern bool debug;

class File {
private:
	std::filesystem::directory_entry m_path;
	const char* m_hash;
	int last_change = 0;

public:
	File(std::filesystem::directory_entry path, const char* hash)
		: m_path{ path }
		, m_hash{ hash }
	{
	}

	const char* get_hash() const { return m_hash; }
	std::filesystem::directory_entry get_path() const { return m_path; }
	void print() const { std::cout << "\n Path: " << m_path << "\n Source Hash: " << m_hash; }
	//void set_sourcehash(char* hash)const { m_source_hash = hash; }
};