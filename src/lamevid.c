#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define VERSION "0.1.0"
static void usage(FILE *o,const char *n){fprintf(o,"lamevid %s - terminal video player\n\nUsage: %s [mpv options] VIDEO [VIDEO ...]\n\nUses mpv's true-colour terminal output (tct). Audio depends on your mpv audio output.\n\n  -h, --help       Show help\n  -V, --version    Show version\n  --check          Check for mpv\n\nExamples:\n  lamevid movie.mp4\n  lamevid --loop-file=inf clip.mkv\n\nDependency: mpv built with the tct video output driver.\n",VERSION,n);}
int main(int argc,char **argv){
 if(argc==2&&(!strcmp(argv[1],"--help")||!strcmp(argv[1],"-h"))){usage(stdout,argv[0]);return 0;}
 if(argc==2&&(!strcmp(argv[1],"--version")||!strcmp(argv[1],"-V"))){printf("lamevid %s\n",VERSION);return 0;}
 if(argc==2&&!strcmp(argv[1],"--check")){if(access("/usr/bin/mpv",X_OK)==0||access("/usr/local/bin/mpv",X_OK)==0){puts("lamevid: mpv found; driver availability is checked at playback.");return 0;}fputs("lamevid: mpv not found. Install it with: sudo apt install mpv\n",stderr);return 1;}
 if(argc<2){usage(stderr,argv[0]);return 2;}
 if(!isatty(STDOUT_FILENO)){fputs("lamevid: stdout is not a terminal; run inside a terminal emulator.\n",stderr);return 2;}
 char **child=calloc((size_t)argc+3,sizeof(*child));if(!child){perror("lamevid: calloc");return 1;}
 child[0]=(char*)"mpv";child[1]=(char*)"--vo=tct";child[2]=(char*)"--really-quiet";
 for(int i=1;i<argc;i++) { child[i+2]=argv[i]; }
 child[argc+2]=NULL;
 execvp(child[0],child);int e=errno;fprintf(stderr,"lamevid: cannot start mpv: %s\n",strerror(e));free(child);return e==ENOENT?127:1;
}
