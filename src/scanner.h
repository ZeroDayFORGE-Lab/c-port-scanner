#ifndef SCANNER_H
#define SCANNER_H

/*
 * Result codes for scan_port()
 */
#define PORT_OPEN      1
#define PORT_CLOSED    0
#define SCAN_ERROR    -1

/*
 * Try to connect to host:port.
 *   host         IPv4 address or hostname
 *   port         1-65535
 *   timeout_sec  how long to wait for the connection
 * Returns PORT_OPEN, PORT_CLOSED (closed or filtered), or SCAN_ERROR.
 */
int scan_port(const char *host, int port, int timeout_sec);

/*
 * Try to read a short banner from an open port.
 * Writes at most buf_len-1 bytes into buf and always null-terminates.
 * Returns the number of bytes read, or -1 on error.
 */
int grab_banner(const char *host, int port, int timeout_sec, char *buf, int buf_len);

#endif
