#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <zmq.h>

int main(void)
{
	void *context = zmq_ctx_new();
	
	void *publisher = zmq_socket(context, ZMQ_PUB);
	int rc = zmq_bind(publisher, "tcp://lo:5556");
	//int rc = zmq_bind(publisher, "tcp://*:5556");
	
	char Shelldon_status[30]	= "Shelldon: Mad";
	char Kakarot_status[30]		= "Kakarot: Happy";
	char Stephen_status[30]		= "Stephen: Full of Energy";
	char Liao_status[30]		= "Liao: Frustrated";

	char send_buffer[40];
	memset(send_buffer, 0, 40);
	
	int i = 0;
	while(1)
	{
		printf("Sending Shelldon's status\n");
		sprintf(send_buffer, "%s %d", Shelldon_status, i);
		zmq_send(publisher, send_buffer, strlen(send_buffer), 0);
		sleep(1);

		printf("Sending Kakarot's status\n");
		sprintf(send_buffer, "%s %d", Kakarot_status, i);
		zmq_send(publisher, send_buffer, strlen(send_buffer), 0);
		sleep(1);

		printf("Sending Stephen's status\n");
		sprintf(send_buffer, "%s %d", Stephen_status, i);
		zmq_send(publisher, send_buffer, strlen(send_buffer), 0);
		sleep(1);

		printf("Sending Liao's status\n");
		sprintf(send_buffer, "%s %d", Liao_status, i);
		zmq_send(publisher, send_buffer, strlen(send_buffer), 0);
		sleep(1);

		i++;
	}
	
	zmq_close(publisher);
	zmq_ctx_destroy(context);
	return 0;
}
