struct dict_in{
	char word[100];
	char mean[100];
};

struct dict_out{
	char word[100];
	struct dict_out *next;
};

program DICT_PROG{
	version DICT_VERS{
		void init(dict_in)=1;
		void insert(dict_in)=2;
		dict_out search(dict_in)=3;
		int delete(dict_in)=4;
	}=1;
}=0x13451111;
