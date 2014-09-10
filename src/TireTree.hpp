#ifndef TIRETREE_HPP
#define TIRETREE_HPP

template <typename T>
class TireTree0 {
    template <typename U>
        class Node {
        };

};

// only 'A' ~ 'Z'
//
class TireTree;
namespace {
class Node {
    public:
        bool isWord_;
        Node *next[26];
        Node()
            :isWord_(false)
        {
            for(auto i=0; i<26; i++){
                next[i] = nullptr;
            }
        }
        void setWord(bool word){
            this->isWord_ = word;
        }
        bool isWord()const{
            return isWord_;
        }
        friend class TireTree;
};
}
class TireTree {
    public:
        typedef unsigned int size_t;
        TireTree()
            :root_(){}
        bool insert(const char *s, size_t len){
            Node *parent = &root_;
            for(size_t i=0; i<len; i++){
                int idx = toIndex(s[i]);
                if(idx<0)
                    return false;
                if(parent->next[idx]==nullptr)
                    parent->next[idx] = new Node();
                parent = parent->next[idx];
            }
            parent->setWord(true);
            return true;
        }
        void quickClear(const char s[], size_t len){
            Node *x = &root_;
            size_t i=0;
            for(i=0; x!=nullptr && i<len; i++){
                int idx = toIndex(s[i]);
                if(idx<0)
                    return;
                x = x->next[idx];
            }
            if(i == len && x)
                x->setWord(false);
        }
        bool isExist(const char word[], size_t len){
            Node *n = &root_;
            size_t i;
            for(i=0; i<len && n; i++){
                int idx = toIndex(word[i]);
                if(idx<0)
                    return false;
                n   = n->next[idx];
            }
            if(i==len && n)
                return n->isWord();
            return false;
        }

    private:
        static int toIndex(const char ch){
            if(ch>='A' && ch<='Z')
                return ch - 'A';
            if(ch>='a' && ch<='z')
                return ch - 'a';
            return -1;
        }
    private:
        Node root_;
};
#endif  /* TIRETREE_HPP */

