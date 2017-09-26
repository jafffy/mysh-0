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
  char *tmp=(char*)malloc(4*n);
  for(int i=0;i<=n;i++){
    if(command[i]==' '|| command[i]=='\n') tmp[m++]=0;
    else if(command[i]=='|'){
      tmp[m++]=0; tmp[m++]='|'; tmp[m++]=0;
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
  *argv=(char**)malloc(4*cnt);
  j=0;
  while(j<m){
    int sz=strlen(tmp+j);
    if(!sz) j++;
    else{
      (*argv)[*argc]=(char*)malloc(2*(sz+1));
      sprintf((*argv)[(*argc)++],"%s",tmp+j);
      j+=sz+1;
    }
  }
  free(tmp);
}
