
#define WIDTH 12
#define HEIGHT 8

u8 map[WIDTH*HEIGHT];
u8 cursor = 0;

int main() {
    init_video();

    load_level(1);

    while (true) {
        u8 key = read_keys();
        if (key == KEY_UP) {
            if (cursor < WIDTH) {
                cursor += WIDTH*(HEIGHT - 1);
            } else {
                cursor -= WIDTH;
            }
        } else if (key == KEY_DOWN) {
            if (cursor > WIDTH*(HEIGHT - 1)) {
                cursor -= WIDTH*(HEIGHT - 1);
            } else {
                cursor += WIDTH;
            }
        } else if (key == KEY_LEFT) {
            if (cursor % WIDTH == 0) {
                cursor += WIDTH - 1;
            } else {
                cursor -= 1;
            }
        } else if (key == KEY_RIGHT) {
            if (cursor != 0 && cursor % (WIDTH - 1) == 0) {
                cursor -= WIDTH - 1;
            } else {
                cursor += 1;
            }
        } else if (key == KEY_A) {
            click_block(cursor);
        }

        draw_map();
    }
}
