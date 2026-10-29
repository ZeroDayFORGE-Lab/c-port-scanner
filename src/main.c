#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "scanner.h"

#define DEFAULT_TIMEOUT 2

static void usage(const char *prog)
{
    fprintf(stderr,
        "Usage: %s <host> <start_port> <end_port> [timeout_sec]\n"
        "Example: %s 192.168.56.101 1 1024 2\n"
        "Only scan systems you own or have written permission to test.\n",
        prog, prog);
}

/* Parse a port number safely. Returns 0 on success, -1 on invalid input. */
static int parse_port(const char *s, int *out)
{
    char *end = NULL;
    errno = 0;
    long v = strtol(s, &end, 10);

    if (errno != 0 || end == s || *end != '\0') {
        return -1;
    }
    if (v < 1 || v > 65535) {
        return -1;
    }
    *out = (int)v;
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 5) {
        usage(argv[0]);
        return 1;
    }

    const char *host = argv[1];
    int start_port, end_port;
    int timeout = DEFAULT_TIMEOUT;

    if (parse_port(argv[2], &start_port) != 0 ||
        parse_port(argv[3], &end_port) != 0) {
        fprintf(stderr, "Error: ports must be numbers between 1 and 65535.\n");
        return 1;
    }
    if (start_port > end_port) {
        fprintf(stderr, "Error: start port must not be greater than end port.\n");
        return 1;
    }
    if (argc == 5) {
        char *end = NULL;
        long t = strtol(argv[4], &end, 10);
        if (end == argv[4] || *end != '\0' || t < 1 || t > 30) {
            fprintf(stderr, "Error: timeout must be between 1 and 30 seconds.\n");
            return 1;
        }
        timeout = (int)t;
    }

    printf("Scanning %s ports %d-%d (timeout %ds)\n", host, start_port, end_port, timeout);

    int open_count = 0;
    int error_count = 0;

    /* TODO 3: replace this single-threaded loop with a pthread worker pool
     *         once scan_port() works correctly. */
    for (int port = start_port; port <= end_port; port++) {
        int result = scan_port(host, port, timeout);

        if (result == PORT_OPEN) {
            printf("%5d/tcp  open\n", port);
            open_count++;
        } else if (result == SCAN_ERROR) {
            error_count++;
        }
    }

    if (error_count > 0 && open_count == 0) {
        fprintf(stderr, "Note: %d errors. scan_port() may not be implemented yet.\n", error_count);
    }

    printf("Done. %d open port(s) found.\n", open_count);
    return 0;
}
