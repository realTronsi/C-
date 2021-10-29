#include <stdlib.h>
#include <stdio.h>

#include "../../include/readfile.h"

int main(){
	char* buffer = NULL;
	if(freadf("./src/main.see", &buffer) == 0){
		printf("%s", buffer);
	}

	free(buffer);

	return 0;
}