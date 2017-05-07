
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	
	int i;
	int j;
	char arg[2];
	char c=0;
	char outputFileName[30];
	FILE* input = stdin;
	FILE* output = stdout;

	if(argc < 2){

		while((c = fgetc(input))!=(EOF)){

			if(c >= 65 && c <= 90)
				c += 32;
				
			fputc(c, output);
		}
	}
	else{
		arg[0] = argv[1][0];
		arg[1] = argv[1][1];

		if(argc > 2){
			for(i=1; i<argc; i++){
				
				if(strcmp(argv[i],"-i")==0){
					
					FILE* inputFile = fopen(argv[i+1], "r");

					if (inputFile == NULL) {
						fprintf(stderr, "Can't open input file %s!\n", argv[i+1]);
						return 1;
					}

					input = inputFile;
					
				}
				else if(strcmp(argv[i],"-o")==0){
					
					fprintf(output, "Enter output file:\n");
					fgets(outputFileName, 30, input);
					fprintf(output, "Enter text to encode:\n");
					FILE* outputFile = fopen(outputFileName, "w+");
					output = outputFile;

				}
				else if((argv[i][0] == '+') || (argv[i][0] == '-')){
					
					for(j=0; j<2; j++){
						arg[j] = argv[i][j];
					}
				}
			}
		}

		if(arg[0] == '+'){

			while((c = fgetc(input))!=EOF){
				
				if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){

					if(c >= 'A' && c <= 'Z')
						c += 32;
						
					if(c+(arg[1]-48) > 'z'){
						c = ((c+arg[1]-48)%122)+96;
					}
					else{
						c += (arg[1]-48);
					}
				}
				fputc(c, output);
			}

		}

		else if(arg[0] == '-'){
			
			while((c = fgetc(input))!=EOF){

				if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
					if(c >= 'A' && c <= 'Z')
						c += 32;
						
					if(c-(arg[1]-48) < 'a'){
						c = (c-(arg[1]-48))+26;
					}
					else{
						c -= (arg[1]-48);
					}
				}
				fputc(c, output);
			}
		}
	}

	fclose(input);
	fclose(output);





	return 0;
}