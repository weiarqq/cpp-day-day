int prinf(const char* format, ...);

int global_variable = 42;
int global_uninit_var;

void func1(int i) { prinf("%d\n", i); }

int main(void) {
    static int static_var = 100;
    static int static_var2;
    int a = 1;
    int b;
    func1(static_var + static_var2 + a + b);
    return a;
}