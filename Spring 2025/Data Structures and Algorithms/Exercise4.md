```
//Input: An integer value to add to the stack
void myStack::push(int value) 
{
    Node* element = new Node;
    element->data = value;

    if(list == nullptr)
        element->next = list->next;
    
    list = element;
}


//Output: returns the top object of the stack
Node* myStack::pop() 
{
    if(list == nullptr)
        return nullptr;

    Node* temp = list;

    if(list->next != nullptr)
        list = list->next;
    
    return temp;
} 
//This should return the value no the node!!

```

Remember Scope operator!!
in the homework you should just be able to throw the `throw std::runtime_error`

you should throw an error because there isn't any special value that you can return for the programmer to handle the error

you need to add any exceptions you throw to the "output" section of your comments!

