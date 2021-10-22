#include <stdio.h>
#include <zmq.h>
#include <string.h>

int main(void)
{
	void *context = zmq_ctx_new();
	void *subscriber = zmq_socket(context, ZMQ_SUB);
	int rc = zmq_connect(subscriber, "tcp://localhost:5556");

	char filter[10] = {'K', 'a'};
	rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, filter, 2);

	char str[40];
	memset(str, 0, 40);

	for(int i = 0; i < 100; i++)
	{
		zmq_recv(subscriber, str, 40, 0);
		printf("%s\n", str);
	}

	zmq_ctx_destroy(context);
	zmq_close(subscriber);
	return 0;
}
