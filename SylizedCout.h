#ifndef STYLIZEDCOUT_H
#define STYLIZEDCOUT_H

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define RED(x) KRED x RST
#define GREEN(x) KGRN x RST
#define YELLOW(x) KYEL x RST
#define BLUE(x) KBLU x RST
#define MAGENTA(x) KMAG x RST
#define CYAN(x) KCYN x RST
#define WHITE(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDERLINE(x) "\x1B[4m" x RST


#endif