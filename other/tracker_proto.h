typedef struct
{
	char pkg_len[8];  //body length, not including header
	char cmd;    //command code
	char status; //status code for response
} TrackerHeader;
