//MapArray.h

#ifndef MAPARRAY_H
#define MAPARRAY_H

#include <vector>
#include <algorithm>

template <typename Key, typename Value>
class MapArray {
	std::vector<std::pair<Key, Value>> vec;
public:
	class iterator {
    	std::pair<Key, Value>* current;
    public:
    
    	using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(pointer const ptr = nullptr) : current(ptr) { } 
        iterator& operator++() {++current; return *this;}
        iterator& operator--() {--current; return *this;}
        iterator operator++(int) {iterator temp = *this; ++current; return temp;}
        iterator operator--(int) {iterator temp = *this; --current; return temp;}
        iterator& operator+=(difference_type const d) {current += d; return *this;}
        iterator& operator-=(difference_type const d) {current -= d; return *this;}
        friend iterator operator+(iterator i, difference_type const d) {return i += d;}
        friend iterator operator+(difference_type const d, iterator i) {return i += d;}
        friend iterator operator-(iterator i, difference_type const d) {return i -= d;}
        friend iterator operator-(difference_type const d, iterator i) {return i -= d;}
        friend difference_type operator-(iterator const i, iterator const j) {return i.current - j.current;}
        auto operator <=> (iterator const& other) const = default;
        reference operator*() const {return *current;}
        pointer operator->() const {return current;}
        reference operator[](difference_type const d) const {return (*((*this) + d));}
    };
    static_assert(std::random_access_iterator<iterator>);
    using value_type = std::pair<Key, Value>;
    MapArray() {}
    iterator begin() {return iterator(vec.data());}
    iterator end() {return iterator(vec.data() + vec.size()); }
    Value& operator[](Key const& key) 
    {
        // auto found = std::find_if(vec.begin(), vec.end(), [&](const auto& p){return p.first == key;});
        // if (found != vec.end())
        // {
        //     return found-> second;
        // }
        // else
        // {
        //     iterator it = insert(std::make_pair(key, Value()));
        //     return it -> second;
            
        // }
        auto low = std::lower_bound(vec.begin(), vec.end(), key, [](std::pair<Key, Value> const & p, Key const & k){return p.first < k; });

        // for(auto i = vec.begin(); i != vec.end(); i++)
        // {
        //     if (i -> first == key)
        //         return i -> second;
        // }
        // vec.push_back(std::make_pair(key, Value()));
        // return vec.back().second;
        
        if (low == vec.end() or low -> first != key)
            low = vec.insert(low, std::pair(key, Value()));
        
        return low -> second;
    }
    // iterator insert(const value_type val)
    // {
    //     auto low = std::lower_bound(vec.begin(), vec.end(), val.first, [](const auto& p, const auto& k){return p.first < k; });
    //     return iterator(vec.insert(low, val));
    // }
    ~MapArray() {}
};

#endif