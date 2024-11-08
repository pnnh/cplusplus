#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <libc.h>

// 图4-3 对每个命令行参数打印文件类型
int main(int argc, char *argv[]) {
  int i;
  struct stat buf;
  char *ptr;

  for (i = 1; i < argc; i++) {
    printf("%s: ", argv[i]);
    if (lstat(argv[i], &buf) < 0) {
      fprintf(stderr, "lstat error");
      continue;
    }
    if (S_ISREG(buf.st_mode))
      ptr = "regular";
    else if (S_ISDIR(buf. st_mode))
      ptr = "directory";
    else if (S_ISCHR(buf.st_mode))
      ptr = "character special";
    else if (S_ISBLK(buf.st_mode))
      ptr = "block special";
    else if (S_ISFIFO(buf.st_mode))
      ptr = "fifo";
    else if (S_ISLNK(buf.st_mode))
      ptr = "socket";
    else ptr = "** unknown mode **";
    printf("%s\n", ptr);
  }
  exit(0);
}

// ./a.out /etc/passwd /etc /dev/log /dev/tty /var/lib/oprofile/opd_pipe /dev/sr0 /dev/cdrom