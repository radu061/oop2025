class Canvas
{
    char canvas[1005][1005];
    int h, w;
public:
    Canvas(int width, int height);
    void Set_pixel(int x, int y, char ch);
    void Print(); 
    void Clear(); 
    void set_pixels(int count, ...);
};