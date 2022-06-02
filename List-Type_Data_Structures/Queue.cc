#include "Node.cpp"
#include <stdexcept>
#include <ostream>

template<typename T>
class Queue{
    int stackSize = 0;
    Node<T>* sentinel_head;
    Node<T>* sentinel_tail;

    void push(Node<T> & node){
            node.next = sentinel_head->next;
            sentinel_head->next->prev = node;
            node.prev = sentinel_head;
    }

    public:
        class const_iterator{
            protected: 
                const Queue<T> *theStack;
                Node<T> *current;

                //returns data at node pointed at
                T & retrieve() const {
                    return current->data;
                }

                //parameter constructor
                const_iterator(const Queue<T>& lst, Node<T> *p) :theStack{& lst}, current{p}{}

                //checks if iterator is valid
                void assertIsValid() const {
                    if( theStack == nullptr || current == nullptr || current == theStack->sentinel_head)
                        throw std::out_of_range("IteratorOutOfBounds!");
                }

                friend class Queue<T>;

            public:
                const_iterator(const Queue<T>& lst) : theStack{ &lst}, current{lst.sentinel_head}{}
    

                const T & operator*() const {
                    return retrieve();
                }

                const_iterator operator++(){
                    current = current->next;
                    return *this;
                }

                const_iterator operator--(){
                    current = current->prev;
                    return *this;
                }
                // const_iterator operator++(int){
                //     const_iterator old = *this;
                //     ++(*this);
                //     return old;
                // }

                const_iterator operator+(int pos) const {
                    const_iterator start = const_iterator(*theStack, sentinel_head->next);

                    for(int i=0; start!= sentinel_tail && i<=pos ;i++ ){
                        start++;
                    }

                    return start;
                }

                bool operator== (const const_iterator& rhs ) const {
                    return current == rhs.current;
                }

                bool operator!= (const const_iterator& rhs) const {
                    return !(*this == rhs);
                }

        };

        class iterator: public const_iterator {
            protected:
                iterator (const Queue<T>& lst, Node<T>* p) : const_iterator(lst, p){}

                friend class Queue<T>;

            public: 
                iterator (const Queue<T>& lst){}

                T & operator*(){
                    return const_iterator::retrieve();
                }

                const T & operator*() const {
                    return const_iterator::operator*();
                }

                iterator & operator++(){
                    this->current = this->current->next;
                    return *this;
                }

                iterator & operator--(){
                    this->current = this->current->prev;
                    return *this;
                }
        };

        void init(){
            sentinel_head = new Node<T>();
            sentinel_tail = new Node<T>();
            sentinel_head->next = sentinel_tail;
            sentinel_tail->prev = sentinel_head;
        }

        //default constructor
        Queue(){
            init();
        }

        //parameter constructor
        Queue(Node<T>* new_head){
            init();
            push(new_head);
        }

        //Copy constructor
        Queue(Queue & rhs){
            stackSize = rhs.stackSize;
            sentinel_head = new Node<T>(rhs.sentinel_head->data, rhs.sentinel_head->next);
            sentinel_tail = new Node<T>(rhs.sentinel_tail->data);
        }

        //move constructor
        Queue(Queue && rhs):stackSize{rhs.stackSize}, sentinel_head{std::move(rhs.sentinel_head)}, sentinel_tail{std::move(rhs.sentinel_tail)}{
            rhs.sentinel_head = nullptr;
            rhs.sentinel_tail = nullptr;
        }

        //copy assignment
        Queue& operator=(Queue & other_stack){
            stackSize = other_stack.stackSize;
            *sentinel_head = *other_stack.sentinel_head;
            *sentinel_tail = *other_stack.sentinel_tail;

            return *this;
        }

        //move assignment
        Queue& operator=(Queue && other_stack){
            std::swap(stackSize, other_stack.stackSize);
            std::swap(sentinel_head, other_stack.sentinel_head);
            std::swap(sentinel_tail, other_stack.sentinel_tail);
            other_stack.sentinel_head = nullptr;
            other_stack.sentinel_tail = nullptr;
            

            return *this;
        }

        iterator top(){
            return iterator(*this, sentinel_head->next);
        }

        const_iterator top() const{
            return const_iterator(*this, sentinel_head->next);
        }

        iterator end(){
            return iterator(*this, sentinel_tail);
        }

        const_iterator end() const{
            return const_iterator(*this, sentinel_tail);
        }

        void push(Node<T>* node){
           sentinel_head->next = sentinel_head->next->prev = node;
            
            stackSize++;
        }

        void enqueue(T& value){
            Node<T>* node = new Node<T>(value, sentinel_head->next, sentinel_head); 
            push(node);
        }

        void enqueue(T&& value){
            Node<T>* node = new Node<T>(std::move(value), sentinel_head->next, sentinel_head); 
            push(node);
        }        

        void enqueue(iterator& itr){
            Node<T>* node = new Node<T>(*itr, sentinel_head->next, sentinel_head); 
            push(node);

        }

        //returns sentinel_tail when empty
        Node<T>* pop(){
            Node<T>* popped =  sentinel_head->next;

            if(popped!=sentinel_tail){
                sentinel_head->next = popped->next;
                popped->next->prev = sentinel_head;
            }
            stackSize--;
            
            return popped;
        }

        //returns sentinel_head when empty
        Node<T>* dequeue(){
            Node<T>* popped = sentinel_tail->prev;

            if(popped!=sentinel_head){
                sentinel_tail->prev = popped->prev;
                popped->prev->next = sentinel_tail;
            }
            stackSize--;
            
            return popped;
        }

        int size(){
            return stackSize;
        }

        bool empty(){
            return size() == 0;
        }


        void print(){
            if(empty()){
                std::cout << "[]" << std::endl;
            }

            else{
                const_iterator itr = top();
                std::cout << "[" << *itr;

                int count = 0;
                //size()-1 because we printed a value earlier
                while( count<size()-1 ){
                    std::cout << ", " << *++itr;
                    count++;
                }

                std::cout << "]" << std::endl;
            }
        }

        ~Queue(){
            iterator itr = top();
            if(itr != end()){
                for(itr; itr!=end();++itr){
                    Node<T>* popped = pop();
                    delete popped;
                }
            }
            delete sentinel_head;
            delete sentinel_tail;
        }

};