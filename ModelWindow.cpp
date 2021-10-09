#include <iostream>
using namespace std;

// Размер экрана
const int screen_border_x = 1920; 

const int screen_border_y = 1080;

enum Color { Black, White, Blue, Green, Red };

void printColor(Color c) {
    if (c == 0) cout << "Black\n";
    else if (c == 1) cout << "White\n";
    else if (c == 2) cout << "Blue\n";
    else if (c == 3) cout << "Green\n";
    else cout << "Red\n";
}

class ModelWindow {
private:
    string head;
    int x;
    int y;
    int height;
    int width;
    Color color;
    bool visible;
    bool frame; // с рамкой/ без
public:

    ModelWindow(string head, int x, int y, int height, int width, Color color = White, bool visible = true, bool frame = true) {
        this->head = head;
        this->x = x;
        this->y = y;
        this->height = height;
        this->width = width;
        this->color = color;
        this->visible = visible;
        this->frame = frame;
    }
    void MoveHorzontal(int move) {
        if (width + move <= screen_border_x && x + move >= 0) {
            x += move;
        }
        else {
            cout << "Невозможно передвинуть окно по горизонтали\n";
        }
    }

    void MoveVertically(int move) {
        if (height + move <= screen_border_x &&  y + move >= 0) {
            y += move;
        }
        else {
            cout << "Невозможно передвинуть окно по вертикали\n";
        }
    }

    void set_height(int newHeight) {
        if (newHeight < 0) {
            throw invalid_argument("Высота окна не может быть отрицательной\n");
        }
        if (y != 0) {
            if (y + newHeight - 1 <= screen_border_y) {
                this->height = newHeight;
            }
            else {
                cout << "Невозможно установить данную высоту окна\n";
            }
        }
        else {           
            if (newHeight >= screen_border_y) {
                cout << "Невозможно установить данную высоту окна\n";
            }
            else {
                this->height = newHeight;
            }
        }
    }
    void set_width(int newWidth) {
        if (newWidth < 0) {
            throw invalid_argument("Ширина окна не может быть отрицательной\n");
        }
        if (x != 0) {
             if (x + newWidth - 1 <= screen_border_x) {
                this->width = newWidth;
             }
             else {
                 cout << "Невозможно установить данную ширину окна\n";
             }
        }
        else {
             if (newWidth >= screen_border_x) {
                 cout << "Невозможно установить данную ширину окна\n";
             }
            else {
                this->width = newWidth;
            }
        }
    }

    void set_color(Color color) {
        this->color = color;
    }

    void set_visible(bool visible) {
        this->visible = visible;
    }

    bool get_visible() {
        return visible;
    }

    void set_frame(bool frame) {
        this->frame = frame;
    }

    bool get_frame() {
        return frame;
    }

    void getInfo() {
        cout << "Координаты левого верхнего угла: " << x << ", " << y << endl;
        cout << "Ширина окна: " << width << ";"; cout << "Высота окна: " << height << endl;
        cout << "Окно ";
        if (visible) cout << "видимое и ";
        else cout << "невидимое и ";

        if (frame) cout << "с рамкой\n";
        else cout << "бeз рамки\n";
        cout << "Цвет рамки: ";
        printColor(color);
    }

};
int main()
{
    setlocale(LC_ALL, "rus");
    ModelWindow md = ModelWindow("head", 0, 0, 2, 3, Black);
    md.getInfo();
    md.set_color(White);
    md.set_frame(false);
    md.set_visible(false);
    md.MoveHorzontal(500);
    md.MoveVertically(200);
    md.set_width(1079);
    md.set_height(1919);
    md.getInfo();
}
