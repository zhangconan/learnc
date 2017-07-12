#ifndef STRUCTLEARN_H_INCLUDED
#define STRUCTLEARN_H_INCLUDED
typedef struct
{
	char pkg_len[8];  //body length, not including header
	char cmd;    //command code
	char status; //status code for response
} TrackerHeader;
# if __WORDSIZE == 64
typedef long int  int64_t;
# else
__extension__
typedef long long int  int64_t;
# endif

struct fast_task_info;

struct fast_task_info
{
	//IOEventEntry event;  //must first
	//char client_ip[IP_ADDRESS_SIZE];
	void *arg;  //extra argument pointer
	char *data; //buffer for write or recv
	int size;   //alloc size
	int length; //data length
	int offset; //current offset
	int64_t req_count; //request count
	//TaskFinishCallback finish_callback;
	struct nio_thread_data *thread_data;
	struct fast_task_info *next;
};


int64_t buff2long(const char *buff);

struct base64_context
{
	char line_separator[16];
	int line_sep_len;

	/**
	 * max chars per line, excluding line_separator.  A multiple of 4.
	 */
	int line_length;

	/**
	 * letter of the alphabet used to encode binary values 0..63
	 */
	unsigned char valueToChar[64];

	/**
	 * binary value encoded by a given letter of the alphabet 0..63
	 */
	int charToValue[256];
	int pad_ch;
};

#endif // STRUCTLEARN_H_INCLUDED









