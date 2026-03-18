#pragma once
#include "init.h"
#include <filesystem>
#include <typeinfo>
#include <vector>

std::vector<File> ScanDirectory(std::filesystem::path path) {
	std::vector<File> source_files;

	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(path))
	{
		if (debug) {
			std::cout << entry << "\n";
			std::cout << typeid(entry).name() << "\n";
		}
		if (entry.is_directory()) {
			ScanDirectory(entry);
		}
		else {
			source_files.push_back(File(entry));
		}
	}

	return source_files;
}

void Init() {
	std::filesystem::path source = "C:/Users/krombus/Documents/_orig";
	std::filesystem::path target = "C:/Users/krombus/Documents/_new";

	std::vector<File> source_files;
	std::vector<File> target_files;

	if (debug) {
		std::cout << source;
	}

	source_files = ScanDirectory(source);
	target_files = ScanDirectory(target);

	/*
	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(source))
	{
		if(debug){
		std::cout << entry << "\n";
		std::cout << typeid(entry).name() << "\n";
		}
		source_files.push_back(File(entry));
	}

	for (std::filesystem::path entry : std::filesystem::directory_iterator(target))
	{
		if (debug) {
			std::cout << entry << "\n";
			std::cout << typeid(entry).name() << "\n";
		}
		target_files.push_back(File(entry));
	}
	*/

	if (debug) {
		for (auto& entry : source_files) {
			entry.print();
		}
		for (auto& entry : target_files) {
			entry.print();
		}
	}
}