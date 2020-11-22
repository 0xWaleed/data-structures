# Stack



### Structures:

* Stack Options Structure `stack_options_s`
  * max_size
* Stack Structure `stack_s`
  * Max Size `max_size`
  * Is Full `is_full`
  * Is Empty `is_empty`
  * Data Size `size`
  * Items `items`

### API:

* Create Stack `stack_s* stack_create(stack_options_s*)`
* Push Item `void stack_push(stack_s*, void* item)`
* Pop Item ` void* stack_pop(stack_s*)`
* Peek `void* stack_peak(stack_s*)`