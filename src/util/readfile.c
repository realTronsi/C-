#include "../../include/readfile.h"

int freadf(char* path, char** b){
	FILE* file = fopen(path, "rb");

	if(file == NULL){
		// incorrect file path
		return 1;
	}

	// file size
	fseek(file, 0, SEEK_END);
	unsigned long file_size = ftell(file); // 4GB
	fseek(file, 0, SEEK_SET);

	char* buffer = calloc(file_size + 1, sizeof(*buffer));

	if(buffer == NULL){
		// allocation error
		return 2;
	}

	size_t size_read = fread(buffer, 1, file_size, file);

	if(size_read != file_size){
		// reading error
		return 3;
	}

	*b = buffer;

	fclose(file);
	return 0;
}