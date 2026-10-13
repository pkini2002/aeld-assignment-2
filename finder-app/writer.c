#include<stdio.h>
#include<stdlib.h>
#include<syslog.h>

int main(int argc, char *argv[]){
	FILE *fp;

	openlog(NULL, 0, LOG_USER);

	if (argc != 3){
		syslog(LOG_ERR, "Invalid number of arguments");
		return 1;
	}

	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

	fp = fopen(argv[1], "w");
	if (fp == NULL){
		syslog(LOG_ERR, "Failed to open file %s", argv[1]);
		closelog();
		return 1;
	}

	if (fprintf(fp, "%s", argv[2]) < 0){
		syslog(LOG_ERR, "Failed to open file %s", argv[1]);
		fclose(fp);
		closelog();
		return 1;
	}

	fclose(fp);
	closelog();

	return 0;
}
