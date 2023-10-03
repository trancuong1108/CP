namespace IO {
    const int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE + 1], *inp = buf;
    bool en = false;
    int tmp;
    char get_char() {
        if (!*inp && !en) {
            memset(buf, 0, sizeof buf);
            tmp = fread(buf, 1, BUF_SIZE, stdin);
            if (tmp != BUF_SIZE) en = true;
            inp = buf;
        }
        return *inp++;
    }
}
template<typename T>
void read (T &x) {
    x = 0;
    char c;
    bool neg = false;
    c = IO::get_char();
    if (c == '-') neg = true;
    else x = c - '0';
    for (c = IO::get_char(); (c >= '0' && c <= '9'); c = IO::get_char()) {
        x = (x << 3) + (x << 1) + (c - '0');
    }
    if (neg) x = -x;
}
template<typename T, typename ...Ts>
void read(T& x, Ts& ...args) {
    read(x), read(args...);
}
