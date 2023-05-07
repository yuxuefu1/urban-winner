#include <iostream>
#include <string>

using namespace std;

struct Node 
{
    string key;   
    string value;
    Node* next;
    Node* prev;
    Node(const string& k, const string& v) : key(k), value(v), next(NULL), prev(NULL){}
};

class LRUCache 
{
private:
    int capacity;
    int size;
    Node* head;
    Node* tail;

public:
    LRUCache(int c) : capacity(c), size(0), head(NULL), tail(NULL) {}

    void remove(Node* node) 
    {
    
        if (node->prev) 
		{
            node->prev->next = node->next;
        }
		else
		{
            head=node->next;
        }
        if (node->next != NULL) 
		{
            node->next->prev = node->prev;
        }
		else
		{
            tail=node->prev;
        }
    
        delete node;
    }
    
    void setHead(Node* node) 
    {
        if(head==node)
		{
            return;
        }
        
        if (node->prev != NULL) 
		{
            node->prev->next = node->next;
        }
        if (node->next != NULL) 
		{
            node->next->prev = node->prev;
        }
		else
		{
            tail=node->prev;
        }
        
        node->prev=NULL;
        node->next=head;
        if(head)
		{
            head->prev=node;
        }
        
        head=node;
    }

    string get(const string& key) 
	{
        
        Node* it = find(key);
        if (it == NULL) 
		{
            
            return "-1";
        }
        setHead(it);
        return it->value;
    }

    void put(const string& key, const string& value) 
	{
        
        Node* it = find(key);
        if (it != NULL) 
		{
            it->value = value;
            setHead(it);
            return;
        }
       
        if (size == capacity) 
		{
            remove(tail);
        }
		else
		{
            size++;
        }

        Node* node = new Node(key, value);
        if(head)
		{
            head->prev=node;
        }
        node->next=head;
        head=node;
        if(!tail)
		{
            tail=head;
        }
    }
    Node* find(const string& key)
     {
        
        for (Node* curr = head; curr != NULL; curr = curr->next) 
        {
           
            if (curr->key == key) 
            {
                return curr;
            }
        }
        return NULL;
    }
 /* void print()
	{
        cout<<"content:";
        for(Node* curr=head;curr!=NULL;curr=curr->next)
		{
            cout<<curr->key;
        }
        if (head)
        {
            cout<<"  head:"<<head->key;
        }
        if (tail)
		{
            cout<<"  tail:"<<tail->key;
        }
        cout<<endl;
    }
 */
};
int main() 
{
    LRUCache cache(2);
    cache.put("1", "1");
    cache.put("2", "2");
    cout << cache.get("1") << endl; 
    cache.put("3","3");
    cout << cache.get("2") << endl; 
    cache.put("4", "4");
    cout << cache.get("1") << endl; 
    cout << cache.get("3") << endl; 
    cout << cache.get("4") << endl; 
    return 0;
}
