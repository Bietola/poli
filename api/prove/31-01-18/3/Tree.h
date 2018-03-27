#pragma once

namespace mtr {

/*********************************/
/* a generic Tree implementation */
/* done with pointers.           */
/*********************************/
template <typename T>
struct Node {
    private:
        // data
        T mData;

        // links
        Node* mLeft = nullptr, *mRight = nullptr;

    public:
        // constructor
        Node(const T& data):
            mData(data) {}
        
        // getters
        Node*& left() {return mLeft;}
        Node*& right() {return mRight;}
        Node* const & left() const {return mLeft;}
        Node* const & right() const {return mRight;}

        T& data() {return mData;}
        const T& data() const {return mData;}

        // utility functions
        bool isLeaf() const {return !left() && !right();}
};

};
