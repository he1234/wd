#include"ls.h"
int main(int argc, char* argv[])
{

	DIR* fp_dir ;
	struct dirent* pent ;

	fp_dir = opendir(argv[1]);
	if(fp_dir == NULL)
	{
		perror("open");
		exit(1);
	}
	printf("OK!\n");
	while((pent = readdir(fp_dir)) != NULL )
	{
		printf("*********\n");
		show_info(pent ->d_name);
	}
	closedir(fp_dir);
	return 0 ;
}
