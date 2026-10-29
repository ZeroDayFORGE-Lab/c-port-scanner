#include <stdio.h>
#include "scanner.h"

/*
 * TODO 1: implement scan_port()
 *
 * Suggested steps (look up each function's man page):
 *   1. Resolve the host with getaddrinfo() (or inet_pton() for plain IPv4).
 *   2. Create a TCP socket with socket().
 *   3. Make it non-blocking (fcntl with O_NONBLOCK) so connect() does not hang.
 *   4. Call connect(); if it returns EINPROGRESS, wait with select() or poll()
 *      for up to timeout_sec seconds.
 *   5. After the wait, check getsockopt(SO_ERROR): 0 means the port is open.
 *   6. close() the socket on every path, including errors.
 *
 * Questions to answer in your README once it works:
 *   - Why use non-blocking connect instead of a plain blocking connect?
 *   - What is the difference between a closed and a filtered port,
 *     and why can this scanner not always tell them apart?
 */
int scan_port(const char *host, int port, int timeout_sec)
{
    (void)host;
    (void)port;
    (void)timeout_sec;

    /* Not implemented yet */
    return SCAN_ERROR;
}

/*
 * TODO 2 (after scan_port works): implement grab_banner()
 *
 *   - Connect as above, then recv() with a timeout (setsockopt SO_RCVTIMEO).
 *   - Some services (SSH, FTP, SMTP) send a banner immediately.
 *     Others (HTTP) need you to send a request first.
 *   - Never read more than buf_len-1 bytes, and always null-terminate.
 */
int grab_banner(const char *host, int port, int timeout_sec, char *buf, int buf_len)
{
    (void)host;
    (void)port;
    (void)timeout_sec;

    if (buf != NULL && buf_len > 0) {
        buf[0] = '\0';
    }

    /* Not implemented yet */
    return -1;
}
