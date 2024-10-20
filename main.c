#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(FILE*);
int read(FILE*);

int main(void) {
	// opening the csv file, or creating it if it does not exist
	FILE *file = fopen("data.csv", "w");
	if(file == NULL) {
		perror("Error opening CSV file");
		return 1;
	}

	add(file);
        read(file);

	return 0;
}

void add(FILE* file) {
	fprintf(file, "id,name,birth_year\n");
	fprintf(file, "0,smith,1980\n");
}

int read(FILE* file) {
        // open file
	file = fopen("data.csv", "r");
	if(file == NULL) {
		perror("Error opening CSV file");
		return 1;
	}
	
	// reading the file
	char line[2048];
	while(fgets(line, sizeof(line), file)) {
		char* token = strtok(line, ",");
		while(token) {
			printf("%s ", token);
			token = strtok(NULL, ",");
		}
		printf("\n");	
	}
	fclose(file);
}
