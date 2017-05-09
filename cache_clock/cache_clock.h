#define BUCKETS 4
#define MAXITEMS 256
#include <stdbool.h>
typedef struct _node {
	void *data;
	struct node *next;
} node;

node* newNode(void *data);

typedef struct _list {
	node *head;
	node *tail;
} list;
typedef struct _cache {
	void* bucket[BUCKETS];
	unsigned int items;
} cache;

typedef struct _tuple {
	int key;
	void *data;
	bool second_chance;
} tuple;

int _hash(int key);
void cache_init(cache *c, int buckets);
void cache_set(cache *c, int key, void *val);
void* cache_get(cache *c, int key);
void cache_free(cache *c);
void cache_del(cache *c, int key);
void disp_cache_contents(cache *c, void (*disp_fn)(void *val));
void (*disp_fn)(void *val);

void disp_data(void *val);
