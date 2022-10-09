https://practice.geeksforgeeks.org/problems/move-all-zeros-to-the-front-of-the-linked-list/1#

```
void moveZeroes(struct Node **head)
{
    //Your code here
    Node* prev=*head;
    Node* find=*head;
    
    find=find->next;
    while(find!=NULL)
    {
        
        if(find->data==0)
        {
            prev->next=find->next;
            find->next=*head;
            *head=find;
            find=prev->next;
        }
        else
        {
            prev=find;
            find=find->next;
            
        }
            
    }
}
```
