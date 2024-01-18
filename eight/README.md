# 八股文

1. explicit 关键字

**explicit** 防止隐式类型转换,典型场景：构造函数。


```cpp
class MyClass {
public:
    explicit MyClass(int value) {
        this->value = value;
    }

    int getValue() {
        return value;
    }
private:
    int value;
};

int main() {
    MyClass obj1 = 42;  // 这里会导致编译错误，因为构造函数被声明为 explicit
    MyClass obj2(42);   // 这里是正确的，使用了显式构造函数调用
    int x = obj2.getValue(); // 正常调用成员函数

    return 0;
}
```






### 智能指针

1. unique_ptr:独占所有权，超过生命周期释放资源。

```cpp
template <typename T>
class UniquePtr {
public:
    explicit UniquePtr(T* ptr = nullptr) : ptr_(ptr) {}
    
    ~UniquePtr() {
        if (ptr_) {
            delete ptr_;
        }
    }

    // 禁止拷贝构造和赋值操作
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // 移动构造
    UniquePtr(UniquePtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    // 移动赋值
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            if (ptr_) {
                delete ptr_;
            }
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T* get() const {
        return ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
};
```


### 面对对象编程

1. 面对对象编程的三大特征是啥
