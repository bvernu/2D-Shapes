//SetList.h

#ifndef SETLIST_H
#define SETLIST_H

template <typename T>
class SetList {
	struct ListNode {
    	T data;
        ListNode* next;
    };
    ListNode* head;
public:
	class iterator {
    	ListNode* current;
    public:
    	using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(ListNode* const ptr = nullptr) : current(ptr) { }
        iterator& operator++() { current = current->next; return *this; }
        iterator operator++(int) { iterator cpy = *this; current = current->next; return cpy; }
        reference operator*() const { return current -> data; }
        pointer operator->() const {return current; }
        bool operator==(iterator const& other) const { return current == other.current; }
    };
    static_assert(std::forward_iterator<iterator>);
public:
	using value_type = T;

    SetList() : head(nullptr) {}
    SetList(SetList const& other) = delete;
    SetList& operator=(SetList const& other) = delete;
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
    
    iterator find(T value)
    {
    	for (ListNode* curr = head; curr != nullptr; curr = curr -> next)
        {
        	if (curr -> data == value)
            	return iterator(curr);
        }
        return end();
    }
    
    iterator insert(iterator const, T value)
    {
    	if (find(value) != end())
    	    return find(value);
    	else
        {
            ListNode* new_node = new ListNode{value, nullptr};
            if (head == nullptr)
                head = new_node;
            else
            {
                new_node -> next = head;
                head = new_node;
            }
        return iterator(new_node);
        }
    }
    
    ~SetList()
    {
    // 	for (ListNode* curr = head; curr != nullptr;)
    //     {
    //     	ListNode* temp = curr;
    //         curr = curr -> next;
    //         delete temp -> data;
    //         delete temp;
    //     }
        while (head != nullptr) 
        {
            ListNode* next_node = head->next;
            delete head;
            head = next_node;
        }
    }
};

#endif
