
#define WIDTH 12
#define HEIGHT 8
u8 cursor = 0;

int main() {
    init_video();

    load_level(1);

    while (true) {
        u8 key = read_keys();
        if (key == KEY_UP) {
            cursor -= WIDTH;
        } else if (key == KEY_DOWN) {
            cursor += WIDTH;
        } else if (key == KEY_LEFT) {
            cursor -= 1;
        } else if (key == KEY_RIGHT) {
            cursor += 1;
        }
    }
}
