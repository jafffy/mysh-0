#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  int n=strlen(command);
  *argc=0;
  int m=0,j=0,cnt=0;
  char *tmp=(char*)malloc(sizeof(char)*3*n);
  for(int i=0;i<=n;i++){
    if(command[i]==' '|| command[i]=='\n' || command[i]=='\t') tmp[m++]=0;
    else if(command[i]=='|'||command[i]=='<' || command[i]=='>'){
      tmp[m++]=0; tmp[m++]=command[i]; tmp[m++]=0;
    }
    else tmp[m++]=command[i];
  }
  while(j<m){
    int sz=strlen(tmp+j);
    if(!sz) j++;
    else{
      cnt++;
      j+=sz+1;
    }
  }
  *argv=(char**)malloc(sizeof(char*)*(cnt+2));
  j=0;
  while(j<m){
    int sz=strlen(tmp+j);
    if(!sz) j++;
    else{
      (*argv)[*argc]=(char*)malloc(sizeof(char)*(sz+2));
      sprintf((*argv)[(*argc)++],"%s",tmp+j);
      j+=sz+1;
    }
  }
  free(tmp);

  printf("%d\n",*argc);
  for(int i =0;i<*argc;i++)
    printf("argv[%d] : %s\n",i,(*argv)[i]);
}
