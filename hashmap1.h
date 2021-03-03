#define SIZE 20

struct DataItem{
	int key;
	int data;

};	

int hashcode(int key);
int PrintHM(struct DataItem* HashArray[]);
int insertionHM(struct DataItem* HashArray[],int key,int data);
int deletionHM(struct DataItem* HashArrya[],struct DataItem* item);
struct DataItem* searchHM(struct DataItem* HashArray[],int key);
