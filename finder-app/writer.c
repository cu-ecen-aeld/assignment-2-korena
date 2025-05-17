#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  char *file_path;
  char *content;
  if (argc < 3) {
    syslog(LOG_ERR, "file path and/or content arguments are missing.");
    return 1;
  }
  openlog(NULL, LOG_PID | LOG_CONS, LOG_USER);
  file_path = argv[1];
  content = argv[2];

  syslog(LOG_DEBUG, "Writing %s to %s\n", content, file_path);

  fp = fopen(file_path, "w");

  if (NULL == fp) {
    syslog(LOG_ERR, "Failed to open file %s (Error: %s)", file_path,
           strerror(errno));
    closelog();
    exit(1);
  }

  if (0 > fprintf(fp, "%s", content)) {
    syslog(LOG_ERR, "Failed to write to file %s", file_path);
    fclose(fp);
    closelog();
    exit(1);
  }

  fclose(fp);
  closelog();
  return 0;
}
