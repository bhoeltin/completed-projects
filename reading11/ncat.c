
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>



int main(int argc, char *argv[]) {
  /* Lookup server address information */
  char * host = argv[1];                                                            
  char * port = argv[2];       

  struct addrinfo *results;
  struct addrinfo  hints = {
    .ai_family   = AF_UNSPEC,   /* Return IPv4 and IPv6 choices */
    .ai_socktype = SOCK_STREAM, /* Use TCP */
  };
  int status;
  if ((status = getaddrinfo(host, port, &hints, &results)) != 0) {
    fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(status));
    return EXIT_FAILURE;
  }

  /* For each server entry, allocate socket and try to connect */
  int client_fd = -1;
  for (struct addrinfo *p = results; p != NULL && client_fd < 0; p = p->ai_next) {
    /* Allocate socket */
    if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
      fprintf(stderr, "Unable to make socket: %s\n", strerror(errno));
      continue;
    }

    /* Connect to host */
    if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
      fprintf(stderr, "Unable to connect to %s:%s: %s\n", host, port, strerror(errno));
      close(client_fd);
      client_fd = -1;
      continue;
    }
  }

  /* Release allocate address information */
  freeaddrinfo(results);

  if (client_fd < 0) {
    return EXIT_FAILURE;
  }

  /* Open file stream from socket file descriptor */
  FILE *client_file = fdopen(client_fd, "w+");
  if (client_file == NULL) {
    fprintf(stderr, "Unable to fdopen: %s\n", strerror(errno));
    close(client_fd);
    return EXIT_FAILURE;
  }

  /* Read from stdin and send to server */
  char buffer[BUFSIZ];
  while (fgets(buffer, BUFSIZ, stdin)) {
    fputs(buffer, client_file);
    }

  fflush(client_file);
  
  close(client_fd);

  return EXIT_SUCCESS;
}
