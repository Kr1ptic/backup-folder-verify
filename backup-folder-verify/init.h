#pragma once
#include <iostream>

void Init();

class File {
private:
	const char* m_path;
	const char* m_source_hash;
	const int last_change = 0;

public:
	File(const char* path, const char* source_hash)
		: m_path{ path }
		, m_source_hash{ source_hash }
	{
	}

	const char* get_hash() const { return m_source_hash; }
	const char* get_path() const { return m_path; }
	void print() const { std::cout << "\n Path: " << m_path << "\n Source Hash: " << m_source_hash; }
};