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
    
    struct node *newnode;
    newnode = insert_to_ll(ll,&thisnode,sizeof(struct node))->item;
    printf("adding..%s\n",newnode->key);
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
    
    
    struct llnode *gnode = search_ll(newll,"Name");
    
    if (gnode != NULL){
	struct node *thisnode  = (struct node *)gnode->item;
	printf("Found value:%s\n",thisnode->value);
    }
    else
	printf("%s\n","Not found.");
    
    
    //deleting
    printf("Deleting:\n");
    
    gnode = search_ll(newll,"Name");
    if (gnode != NULL){
	remove_node(gnode,newll);
	
	display(newll);
	if (newll->head == NULL)
	    printf("Linked list is empty.\n");
    }
    else
	printf("Not found. Skipped deletion.\n");
    
    
    
   
    
    return 0;
}
