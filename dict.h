#define INITIAL_SIZE 1024

struct ID{
	char* name;
	char* key;

	struct ID *next;

};	

struct dict{
	int n;
	int size;

	struct ID** table;

};	

typedef struct ID ID;
typedef struct dict DICT;

DICT* IniciarDict(int size);
ID* searchDict(DICT* D,char* key);
void FreeDict(DICT** D);
void PrintDict(DICT* D);
int hashcode(DICT* D,char* key);
int InsertDict(DICT** D,char* key,char* name);
int DeleteDict(DICT* D,char* key,char* name);
int GrowDict(DICT** D);
