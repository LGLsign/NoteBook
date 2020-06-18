#include <iostream>
#include <mutex>

template<class _Ty>
class my_shared_count {

private:
    std::mutex m_mtCnt;
    int m_use_count;
    int m_weak_count;
    _Ty* _Ptr;

    void _Destroy () noexcept {
        delete _Ptr;
    }
    
    void _Delete_this () noexcept {
        delete this;
    }
    
public:
    my_shared_count () 
        {
        }

    my_shared_count(_Ty* _Px)
        :_Ptr(_Px), m_use_count(1), m_weak_count(1)
        {  //construct
        }
    
    void _Incref () {
        std::lock_guard<std::mutex> lk(m_mtCnt);
        m_use_count++;
    }

    void _Incwref () {
        std::lock_guard<std::mutex> lk(m_mtCnt);
        m_weak_count++;
    }

    void _Decref () {
        {
            std::lock_guard<std::mutex> lk(m_mtCnt);
            m_use_count--;
        }
        if (m_use_count == 0) {
            _Destroy();
            _Decwref();
        }
    }

    void _Decwref () {
        {
            std::lock_guard<std::mutex> lk(m_mtCnt);
            m_weak_count--;
        }
        if (m_weak_count == 0) {
            _Delete_this();
        }
    }

    int _Use_count() const noexcept {
        return m_use_count;
    }

    bool _Expired() const noexcept {
        return (_Use_count() == 0);
    }
};

template<class _Ty>
class my_shared_ptr {

public:
    constexpr my_shared_ptr() noexcept 
        :m_Ptr(0)
        {
        }

private:
    _Ty* m_Ptr;
    my_shared_count<_Ty>* m_CntPtr;

};

template<class _Ty>
class simple_shared_ptr {
    
public:
    simple_shared_ptr () 
        :_Ptr(nullptr), _use_count(0)
        {
        }
    
    simple_shared_ptr(_Ty* _Px)
        :_Ptr(_Px), _use_count(new int(1)) 
        {
        }

    ~simple_shared_ptr() {
        {
            std::lock_guard<std::mutex> lk(_mt);
            --(*_use_count);
        }
        if (_use_count == 0) {
            delete _Ptr;
            delete _use_count;
        }
    }

    simple_shared_ptr (const simple_shared_ptr& other) {
        _Ptr = other._Ptr;
        _use_count = other._use_count;
        ++(*_use_count);
    }

    simple_shared_ptr& operator= (const simple_shared_ptr& other) {
        _Ptr = other._Ptr;
        _use_count = other._use_count;
        ++(*_use_count);
        return *this;
    }

    _Ty& operator* () {
        return *_Ptr;
    }

    _Ty* operator-> () {
        return _Ptr;
    }

    _Ty* get() {
        return _Ptr;
    }

    int use_count () {
        return *_use_count;
    }

private:
    std::mutex _mt;
    _Ty* _Ptr;
    int* _use_count;
};

int main () {
    simple_shared_ptr<int> ptrInt(new int(2));
    std::cout << *ptrInt << std::endl;
    {
        simple_shared_ptr<int> ptrInt1(ptrInt);
        std::cout << ptrInt.use_count() << std::endl;
    }
    std::cout << ptrInt.use_count() << std::endl;
    return 0; 
}

