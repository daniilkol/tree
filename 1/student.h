class student
{
private:
    char*name;
    int value;
public:
    student(const char*in=0,int iv=0);
    student(const student&i);
    ~student();
    student& operator=(const student&rhs);
    int get_value()const{return value;}
     const char* get_name()const {return (const char*)name;}
    int operator<(const student&b)const;
    bool operator==(const student&b)const;
    void swaps(student&b);
    int init(const char*in=0,int iv=0);
};
