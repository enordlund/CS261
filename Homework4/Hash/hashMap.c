#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{

  /* FIX ME */
  int i;
  ht->tableSize = tableSize;
  ht->count = 0;
  printf("initMap()\n");
  ht->table = (struct hashLink **)malloc(tableSize * sizeof(struct hashLink *));/* this could be wrong */
  
  /*
  for (i = 0; i < tableSize; ++i) {
  	printf("loop\n");
  	ht->table[i]->next = NULL;
  }
  */
  
}

void freeMap (struct hashMap * ht)
{  
	int i;
	struct hashLink *temp;
	struct hashLink *temp2;
	for(i = 0; i < ht->tableSize; i++){
		temp = ht->table[i];
		while(temp != NULL){
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
	}
	free(ht->table);
	ht->count=0;
	ht->table=0;
	ht->tableSize=0;	
}

/* Add an element to the Hash Table */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  

    /* FIX ME */
    struct hashLink * current;
    /* hashing key for index */
    int index = -1;
    printf("insertMap()\n");
    if (HASHING_FUNCTION == 1) {
    	index = stringHash1(k);
    } else if (HASHING_FUNCTION == 2) {
    	index = stringHash2(k);
    }
    if (index == -1) {
    	printf("INDEX = -1\n");
    }
    
    current = ht->table[index];
    printf("current assigned\n");
    if (ht->table[index] == NULL) {/*adding to an empty bucket*/
    	printf("adding to empty bucket\n");
    	ht->table[index] = (hashLink *)malloc(sizeof(hashLink));
    	current->key = k;
    	current->value = v;
    	current->next = NULL;
    	printf("finished adding\n");
    } else {
    	printf("adding to else\n");
    	while (current->next != NULL) {/*finding bottom of bucket*/
    		current = current->next;
    		
    		if (current->key == k) {
    			(current->value)++;
    			return;
    		}
    	}
    	/*allocating memory for next*/
    	current->next = (struct hashLink *)malloc(sizeof(struct hashLink));
    	current = current->next;
    	
    	current->key = k;
    	current->value = v;
    	current->next = NULL;
    }
    
    (ht->count)++;

}



/* Returns a pointer to the value of element with key k in the Hash Table 
   If the element is not in the Hash Table, returns NULL */ 
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 

    /* FIX ME */
	struct hashLink * current;
	ValueType * value = NULL;
	
    /*hashing for index*/
    int index = -1;
    if (HASHING_FUNCTION == 1) {
    	index = stringHash1(k);
    } else if (HASHING_FUNCTION == 2) {
    	index = stringHash2(k);
    }
    if (index == -1) {
    	printf("INDEX = -1\n");
    }
	
	current = ht->table[index];
	
	if (ht->table[index] == NULL) {
		return value;
	} else {
		while (current->next != NULL) {
			if (current->key == k) {
				value = &(current->value);
				break;
			}
			current = current->next;
		}
		return value;
	}
}

int containsKey (struct hashMap * ht, KeyType k)
{  
	if (atMap(ht,k)==0){
		return 0;
	}else{
		return 1;
	}
}

void removeKey (struct hashMap * ht, KeyType k)
{  
	int bucket = stringHash2(k)%ht->tableSize;
	struct hashLink *cur; 
	struct hashLink *prev;  
	if(ht->table[bucket] == 0){
		return;
	}else{
		cur=ht->table[bucket];
		prev=ht->table[bucket];
		while(cur!=0){
			if(strcmp(cur->key,k)==0){
				if(cur==ht->table[bucket]){
					ht->table[bucket]=cur->next;
					
				}else{
				prev->next=cur->next;
				}
				free(cur);
				ht->count--;
				return;
			}else{
				prev=cur;
				cur=cur->next;
			} 
		}
	}
}

int sizeMap (struct hashMap *ht)
{  
	return ht->count;
}

int capacityMap(struct hashMap *ht)
{  
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  
	int runner = 0;
	int i;
	for(i=0; i<ht->tableSize; i++){
		if(ht->table[i]==0){
			runner++;
		}
	}
	return runner;
}

float tableLoad(struct hashMap *ht)
{  
   return (float)sizeMap(ht)/(float)capacityMap(ht);
}
