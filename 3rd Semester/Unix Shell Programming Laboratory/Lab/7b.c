#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	struct dirent *dir;
	DIR *dp;

	int fd,n;

	dp=opendir(".");
	if(dp){
		while((dir=readdir(dp))!=NULL){
			fd=open(dir->d_name,O_RDWR,0777);
			if(fd==-1){
				perror("Error opening file");
				continue;
			}
			n=lseek(fd,0,SEEK_END);
			close(fd);
			if(!n){
				printf("Deleting empty file %s\n",dir->d_name);
				unlink(dir->d_name);
			}
		}
		closedir(dp);
	} else{
		perror("Error opening dir");
	}

}

