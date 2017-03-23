
#include <stdio.h>

int main(int argc, char** argv){

	for(int i = 1; i < argc; i++){

		printf("%s ", argv[i]);
	}
	puts(""); //new line at the end

	return 0;
}