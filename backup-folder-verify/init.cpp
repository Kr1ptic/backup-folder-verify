#include "init.h"
#include <filesystem>
#include <typeinfo>+
#include <vector>

void Init() {
	std::filesystem::path source = "C:/Users/krombus/Documents/_orig";
	std::filesystem::path target = "C:/Users/krombus/Documents/_new";

	std::vector<File> source_files;
	std::vector<File> target_files;

	if (debug) {
		std::cout << source;
	}

	for (const auto& entry : std::filesystem::directory_iterator(source))
	{
		if(debug){
		std::cout << entry << "\n";
		std::cout << typeid(entry).name() << "\n";
		}
		source_files.push_back(File(entry, ""));
	}

	for (const auto& entry : std::filesystem::directory_iterator(target))
	{
		if (debug) {
			std::cout << entry << "\n";
			std::cout << typeid(entry).name() << "\n";
		}
		target_files.push_back(File(entry, ""));
	}

	if (debug) {
		for (const auto& entry : source_files) {
			entry.print();
		}
		for (const auto& entry : target_files) {
			entry.print();
		}
	}
}