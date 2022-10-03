#include <stdio.h>
#include <dirent.h>
#include <string.h>

int listing_files(void)
{
	struct dirent *de; 
	DIR *dr = opendir(".");

	if (dr == NULL) 
	{
		printf("Could not open current directory" );
		return 0;
	}
	while ((de = readdir(dr)) != NULL)
			printf("%s\n", de->d_name);

	closedir(dr);	
	return 0;
}

int listing_files_dir(char* folder)
{
	DIR *d;
    struct dirent *dir;
    d = opendir(folder);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return(0);
}

long int findSize(void)
{
	struct dirent *de; 
	int thre = 1024;
	DIR *dr = opendir(".");
	while ((de = readdir(dr)) != NULL){
		printf("%s\n", de->d_name);
		FILE* f = fopen(de->d_name, "r");		
    	fseek(f, 0, SEEK_END);
    	long int res = ftell(f);
		if (res > thre)
			printf("Size is : %ld \n", res);
		fseek(f, 0, SEEK_SET);

	}
    return (0);
}

int finding_jpg(void)
{
	struct dirent *de; 
	DIR *dr = opendir(".");
	if (dr == NULL) 
	{
		printf("Could not open current directory" );
		return 0;
	}
	while ((de = readdir(dr)) != NULL){
		const size_t len = strlen(de->d_name);
		if (len > 4  && de->d_name[len - 4] == '.' && de->d_name[len - 3] == 'j' && de->d_name[len - 2] == 'p' &&  de->d_name[len - 1] == 'g'){
			printf("%s\n", de->d_name);
		}
	}
	closedir(dr);	
	return 0;
}


int main () {
	
	printf("Chose option");
	int option;
	printf("1- list of all file in current dir, 2- input a dir to list all file, 3- size of files, 4- find jgp files");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		listing_files();
		break;
	case 2:
	;
		char *folder;
		printf("please enter the dir name: ");
		scanf("%s", folder);
		listing_files_dir(folder);
	case 3:
		findSize();
		break;
	case 4:
		finding_jpg();
		break;
	default:
		break;
	}
   return 0;
}