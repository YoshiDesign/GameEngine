#pragma once
#include <string>
#include <fstream>

namespace sparx {
	class FileUtils
	{
	public:
		static std::string read_file(const char* filepath)
		{
			// faster than std::ifstream
			FILE* file = fopen(filepath, "rt");
			fseek(file, 0, SEEK_END);				// To discern file length
			unsigned long length = ftell(file);		// return the length of the file in total bytes
			char *data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);

			delete[] data;
			return result;
		}

	};

}
