#ifndef NUMBERARR_H
#define NUMBERARR_H


template <typename T>
class NumberArr {
public:
    explicit NumberArr(int length);
    T *get_x() const;
    void print_value();
    void set_value(int value);
    int get_length();
private:
    int* x;
    int length_;
};


template <typename T>
void mul(T left,T right, T res);

template <typename T>
void mulX(T left,T right, T res){res=left*right;}

#endif // NUMBERARR_H