/*
 * Simple Cache Implementation
 * Uses second chance replacement algorithm aka clock replacement
 * http://www.mathcs.emory.edu/~cheung/Courses/355/Syllabus/9-virtual-mem/SC-replace.html
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "cache_clock.h"
cache c;
int _hash(int key)
{
	return key % BUCKETS;
}
tuple *newTuple(int key, void *data)
{
	tuple *t = (tuple*) malloc(sizeof(tuple));
	t->key = key;
	t->data = data;
	t->second_chance = true;
	return t;
}
bool is_second_chance(cache *cptr, int bucket_pos)
{
	int state;
	tuple *t = ((tuple*)cptr->bucket[bucket_pos]);
	if (!t) return false;
	state = t->second_chance;
	return (state);
}
void unstick(cache *cptr, int bucket_pos)
{
	int state;
	tuple *t = ((tuple*)cptr->bucket[bucket_pos]);
	if (!t) return;
	t->second_chance = false;
}
void cache_init(cache *cptr, int buckets)
{
	//int i;
	//for (i = 0; i < buckets; i++) {
	//	memset(c->bucket[i], 0, sizeof(tuple));
	//}
}
int _cache_peek(cache *cptr, int key)
{
	tuple *t = (tuple*)cptr->bucket[key];
	if (!t) return (-1);
	return t->key;
}

bool is_cached(cache *cptr, int key)
{
	int pos = _hash(key);
	int altpos = pos++;
	if (_cache_peek(cptr, key) != -1) {
		return true;
	}
	do {
		tuple *t = (tuple*)cptr->bucket[altpos];
		if (t->key) {
			return true;
		}
		altpos++;
	} while (altpos != pos);
	return false;
}
void* cache_get(cache *cptr, int key)
{
	tuple *t = (tuple*)cptr->bucket[key];
	if (!t) return NULL;
	t->second_chance = true;
	return t;
}
void cache_set(cache *cptr, int key, void *val)
{
	tuple *t = newTuple(key, val);
	int firstpos = _hash(key);
	int newpos = firstpos;
	disp_cache_contents(cptr, &disp_data);

	do {
		printf("\nAttempting insert of key %u=>", key);
		if (!is_second_chance(cptr, newpos)) {
			cptr->bucket[newpos] = (void*) t;
			printf("Success!Inserted into slot %u", newpos);
			return;
		} else {
			printf("slot %u is occupied by %u and unable to accomodate key : %u", newpos, _cache_peek(&c, newpos), key);
			unstick(cptr, newpos);
			newpos++;
			newpos = newpos % BUCKETS;
		}
	} while (1);
	//} while (newpos != firstpos);
	printf("\nBailing!!! Unable to find a free pos for key %u", key);

}
void* cache_delete(cache *cptr, int key)
{
	/* iterate 
	 *
	 */ 
	return NULL;
}
void cache_free(cache *cptr)
{
	int i;
	for (i = 0; i < BUCKETS; i++) {
		free(cptr->bucket[i]);
	}
}
void cache_del(cache *c, int key)
{
}
void disp_cache_contents(cache *c, void (*disp_fn)(void *val))
{
	int i;
	for (i = 0; i < BUCKETS; i++) {
		printf("\n Bucket: %u:", i);
		tuple *t = (tuple *) c->bucket[i];
		if (t == NULL) {
			continue;
		}
		printf("\t key :%u", t->key);
		printf(" second_chance :%u", t->second_chance);
		disp_fn(t->data);
	}
	//printf("\n");
}
void disp_data(void *val)
{
	//int data = *((int *) val);
	//printf("\n\t  data :%u", data);

}

void random_workload()
{

}
int main()
{
	int vals[] = {100,200,300,400,500,600,700,800,900};
	cache_init(&c, BUCKETS);
	cache_set(&c, 10, &vals[0]);
	cache_set(&c, 20, &vals[1]);
	cache_set(&c, 30, &vals[2]);
	cache_set(&c, 40, &vals[3]);
	cache_set(&c, 50, &vals[4]);
	cache_set(&c, 60, &vals[5]);
	cache_set(&c, 70, &vals[6]);
	//cache_set(&c, 80, &vals[7]);
	//cache_set(&c, 90, &vals[8]);
	disp_cache_contents(&c, &disp_data);
	return 0;
}
