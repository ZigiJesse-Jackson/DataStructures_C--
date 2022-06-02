#include <stdexcept>
#include <ostream>
template<typename Object>
class List{
    private:
        int theSize;

        struct Node{
            Object data;
            Node *prev;
            Node *next;

            Node( const Object & d = Object{}, Node * p = nullptr,
                                                Node * n = nullptr)
                                                : data{d}, prev{p}, next{n}{}
            
            Node ( Object && d, Node * p = nullptr, Node * n = nullptr)
                : data{std::move(d)}, prev{p}, next{n}{}

        };

        Node *head;
        Node *tail; 


    
    public: 
        class const_iterator{
            protected: 
                const List<Object> *theList;
                Node *current;

                Object & retrieve() const {
                    return current->data;
                }

                const_iterator(const List<Object> & lst, Node *p) :theList{ &lst}, current{p}{}

                void assertIsValid() const {
                    if( theList == nullptr || current == nullptr || current == theList.head)
                        throw std::out_of_range("IteratorOutOfBounds!");
                }

                friend class List<Object>;

            public:
                const_iterator(const List<Object> & lst) : theList{ &lst}, current{lst.head}{}

                const Object & operator*() const {
                    return retrieve();
                }

                const_iterator & operator++(){
                    if(current->next != nullptr){
                        current = current->next;
                        return *this;
                    }
                    throw std::out_of_range("IteratorOutOfBounds!");        
                }

                const_iterator operator++(int){
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }

                const_iterator operator+(int pos) const {
                    const_iterator start = const_iterator(*theList, head->next);

                    for(int i=0; start!= end() && i<=pos ;i++ ){
                        start++;
                    }

                    return start;
                }

                bool operator== (const const_iterator & rhs ) const {
                    return current == rhs.current;
                }

                bool operator!= (const const_iterator & rhs) const {
                    return !(*this == rhs);
                }

        };

        class iterator: public const_iterator {
            protected:
                iterator (const List<Object> &lst, Node* p) : const_iterator(lst, p){}

                friend class List<Object>;

            public: 
                iterator (const List<Object>  &lst){}

                Object & operator*(){
                    return const_iterator::retrieve();
                }

                const Object & operator*() const {
                    return const_iterator::operator*();
                }

                iterator & operator++(){
                    this->current = this->current->next;
                    return *this;
                }

                iterator operator++(int){
                    iterator old = *this;
                    ++(*this);
                    return old;
                }

        };

        void init(){
            theSize = 0;
            head = new Node;
            tail = new Node;

            head->next = tail;
            tail->prev = head;
        }

        iterator begin(){
            return iterator(*this,head->next);
        }

        const_iterator begin() const {
            return const_iterator(*this, head->next);
            
        }

        iterator end(){
            return iterator(*this,tail);
        }

        const_iterator end() const {
            return const_iterator(*this,tail);
        }

        int size() const {
            return theSize;
        }

        bool empty() const {
            return size()==0;
        }

        // Insert x before itr
        iterator insert(iterator itr, const Object & x){
            itr.assertIsValid();
            if(itr.theList != this){
                throw std::invalid_argument("IteratorMismatch!"); 
            }

            Node* p = itr.current;
            theSize++;
            p->prev = p->prev->next = new Node{x, p->prev, p};
            return iterator(*this, p->prev);
        }

        // Insert x before itr
        iterator insert(iterator itr, const Object && x){
            Node* p = itr.current;
            theSize++;
            p->prev = p->prev->next = new Node{std::move(x), p->prev, p};
            return iterator(*this, p->prev);
        }

        // erase item at itr
        iterator erase(iterator itr){
            
            
            if(itr.current!=this->head && itr.current!=this->tail){
                Node *p = itr.current;
                iterator retVal(*this, p->next);

                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
                theSize--;
                return retVal;
            }        
            return itr;
        }

        iterator erase(iterator from, iterator to){
            for(iterator itr = from; itr!=to;)
                itr = erase(itr);
            
            return to;
        }

        Object & front(){
            return *begin();
        }

        const Object & front() const {
            return *begin();
        }

        Object & back(){
            return *--end();
        }

        const Object & back() const {
            return *--end();
        }

        void push_front(const Object & x){
            insert(begin(), x);
        }

        void push_front(Object && x){
            insert(begin(), std::move(x));
        }

        void push_back(const Object & x){
            insert(end(), x);
        }

        void push_back(Object && x){
            insert(end(), std::move(x));
        }

        void pop_front(){
            erase(begin());
        }

        void pop_back(){
            erase(--end());
        }
        
        void clear(){
            while(!empty())
                pop_front();
        }

        List(){
            init();
        }

        ~List(){
            clear();
            delete head;
            delete tail;
        }

        List(const List & rhs){
            init();
            for(auto & x: rhs)
                push_back(x);
        }

        List & operator=( const List & rhs){
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        List(List && rhs) 
            : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}{
                rhs.theSize = 0;
                rhs.head = nullptr;
                rhs.tail = nullptr;
        }

        List & operator=( List && rhs){
            
            std::swap(theSize, rhs.theSize);
            std::swap(head, rhs.head);
            std::swap(tail, rhs.tail);

            return *this;
        }

        iterator returnIterator(int pos){
            iterator start = begin();

            for(int i=0; start!= end() && i<pos ;i++ ){
                start++;
            }

            return start;
        }

        bool swap(List<Object> &secondList, int posA, int posB){
            iterator A = returnIterator(posA);
            iterator B = secondList.returnIterator(posB);

            if(A.theList == this && B.theList == &secondList){
                Node* item1 = A.current;
                Node* item2 = B.current;

                item1->prev->next = item2;
                item2->prev->next = item1;
                item1->next->prev = item2;
                item2->next->prev = item1;

                Node* tempPrev = item1->prev;
                Node* tempNext = item1->next;

                item1->prev = item2->prev;
                item2->prev = tempPrev;
                item1->next = item2->next;
                item2->next = tempNext;

                return true;

            }

            return false;

        }

        bool splice(int position, List<Object> & lst){
            iterator pos = returnIterator(position);

            //check not needed
            if(pos.theList == this){
                iterator other_begin_iterator = lst.begin();
                iterator other_end_iterator = lst.returnIterator(lst.size()-1);
                theSize += lst.size();

                //inserting beginning nodes of lst between pos.current->prev and pos.current
                //simultaneously deletes from lst
                pos.current->prev->next = other_begin_iterator.current;
                other_begin_iterator.current->prev = pos.current->prev;

                other_end_iterator.current->next = pos.current;
                pos.current->prev = other_end_iterator.current;

                lst.head->next = lst.tail;
                lst.tail->prev = lst.head;
                lst.theSize = 0;

                return true;

            }
            return false;            
        }

        void print(){
            if(empty()){
                std::cout << "[]" << std::endl;
            }

            else{
                const_iterator itr = begin();
                std::cout << "[" << *itr++;

                int count = 0;
                //size()-1 because we printed a value earlier
                while( count<size()-1 ){
                    std::cout << ", " << *itr++;
                    count++;
                }

                std::cout << "]" << std::endl;
            }
        }
};