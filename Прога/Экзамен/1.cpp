class complex
{
    double x, y;
public:
    complex()
    {
        x = 0;
        y = 0;
    }
    complex(double a, double b)
    {
        x = a;
        y = b;
    }
};
template<class TYPE1, class TYPE2>
void swap(TYPE1& x, TYPE2& y)
{
    TYPE1 temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    complex x;
    complex y(4,3);
    swap(x,y);
}