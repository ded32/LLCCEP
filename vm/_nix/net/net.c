#include <sys/types.h>
#include <sys/sochet.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <list.h>

#define FATAL(type, fmt, ...) {fprintf(stderr, "Error!\n" fmt, ##__VA_ARGS__); return ((type)0);}
struct __net_socket_data__ {
	int sock_fd;
	int new_sock_fd;

	socklen_t client_len;
	struct sockaddr_in serv, client;
};

struct undirected_list *__net_sockets_data_list__ = 0;
int __net_atexit_set__ = 0;

void __net_clean__(void)
{
	undirected_list_delete(__net_sockets_data_list__);
}

void net_create_srv(int portno) 
{
	if (!__net_atexit_set__) {
		atexit(__net_clean__);
		__net_atexit_set__ = 1;
	}

	struct __net_socket_data__ *data = (struct __net_socket_data__ *)calloc(1, sizeof(*data));

	if (!data) {
		FATAL(void, "Can't alloc mem for socket data: %s!",
		      strerror(errno))
	}

	data->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (data->sock_fd < 0) {
		FATAL(void, "Can't start socket: %s!",
		      strerror(errno))
	}

	bzero(&(data->serv), sizeof(data->serv));

	data->serv.sin_family = AF_INET;
	data->serv.sin_addr.s_addr = INADDR_ANY;
	data->serv.sin_port = htons(portno);

	if (bind(data->sock_fd, (struct sockaddr *)&data->serv,
	         sizeof(data->serv)) < 0)
		FATAL(void, "Can't bind: %s!", strerror(errno))

	__net_sockets_data_list__ = undirected_list_insert_head(
		__net_sockets_data_list__, data);

	__net_start_listening__(__net_sockets_data_list__);
}
