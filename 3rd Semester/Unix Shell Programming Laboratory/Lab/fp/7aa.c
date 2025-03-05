#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>

void print_perms (mode_t m){
	char p[]="-rwxrwxrwx";
	p[0] = S_ISDIR(m)? 'd': '-';
	for(int i=1;i<=9;i++)
		if(!(m&(0400>>i)))
			p[i]='-';
		printf("%s",p);
}

int main(){
	struct dirent *d;
	struct stat s;
	DIR *dp = opendir(".");

	if(!dp) { perror("opendir"); return 1; }

	while((d = readdir(dp)))
		if(d->d_name[0]!='.' && !stat(d->d_name,&s)){
			char t[20];
			strftime(t,sizeof(t),"%b%d%H:%M",localtime(&s.st_mtime));
			print_perms(s.st_mode);
			printf("%2ld %6ld %s %s\n",s.st_nlink,(long)s.st_size,d->d_name,t);
		}
	closedir(dp);
}

