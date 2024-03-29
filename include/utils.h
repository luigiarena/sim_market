#define STDIN  0
#define STDOUT 1
#define STDERR 2

#define IFERROR(s,v,m) if((s)==v) {perror(m); exit(errno);}
#define IFERROR3(s,v,m,c) if((s)==v) {perror(m); c;}
#define IFERRORM1(s,m) if((s)==-1) {perror(m); exit(errno);}
#define IFERROR3C(s,m,c) if((s)==-1) {perror(m); c;}

#define WRITE(m) IFERROR(write(STDOUT,m,strlen(m)), m);
#define WRITELN(m) WRITE(m);WRITE("\n");