# Singly Link List

### Structure:



Node `linklist_node_s`

* Value `void* value`

* Next `linklist_node_s* next`

  

##### Link List `linklist_s`

* Size `size_t size`

* Head `linklist_node_s* head`

* Tail `linklist_node_s* tail`

  



### API:

* Create `linklist_s* linklist_create()`
* Add `void linklist_add(void* value)`
* Find `linklist_node_s* find(void* value)`
* Delete `void deleteNodeByValue(void* value)`
* Traverse `void linklist_traverse(linklist_node_s* node, clist* list)`
* Destroy `void linklist_destroy(linklist_s* list)`