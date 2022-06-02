template<typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;

    // Copy constructor with optional defaults
    Node(const T & other_data = T{}, Node * other_next = nullptr, Node * other_prev = nullptr )
    :data{other_data}, next{other_next}, prev{other_prev}{}

    // Move constructor with rvalue ref and optional defaults
    Node( T && other_data, Node * other_next = nullptr, Node * other_prev = nullptr ): data{std::move(other_data)},
        next{other_next}, prev{other_prev} {
        }
};