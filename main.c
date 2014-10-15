#include "linkedlist.h"
#include <stdio.h>

struct node
{
    char value[20];
    char key[20];
};

int ismatch(void *in, void *key)
{
    struct node *_in = (struct node *)in;
    return strcmp(_in->key, (char *)key) == 0;
}

void freenode(void *item)
{
    free((struct node *)item);
}

char *tostring(void *item)
{
    struct node *_item = (struct node *)item;
    return _item->key;
}

void AddToLinkedList(struct linkedlist *ll, char *value, char *key)
{
    struct node thisnode;
    strcpy(thisnode.value,value);
    strcpy(thisnode.key,key);
    
    insert_to_ll(ll,&thisnode,sizeof(struct node));
}

void display(struct linkedlist *ll)
{
    struct llnode *node;
    struct node *thisitem;
    
    node = ll->head;
    while(node != NULL)
    {
	thisitem = (struct node *)node->item;
	printf("%s :%s\n", thisitem->key, thisitem->value);
	node = node->next;
    }
}

int main()
{
    struct linkedlist *newll = create_ll(ismatch,freenode,tostring);
    AddToLinkedList(newll,"Arjob","Name");
    AddToLinkedList(newll,"26","Age");
    AddToLinkedList(newll,"Kolkata","City");
    display(newll);
    
    struct node *thisnode  = search_ll(newll,"City");
    if (thisnode == NULL)
	printf("Not Found.\n");
    else
	printf("%s\n", thisnode->value);

    return 0;
}