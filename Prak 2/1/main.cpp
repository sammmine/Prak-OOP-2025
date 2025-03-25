#include "KeyValue.cpp"

int main() {
    KeyValue<int, string> kv;
    kv.set(1, "Alice");
    kv.set(2, "Bob");
    kv.set(3, "Charlie");
    kv.display(1); // Output: "Alice"
    kv.display(2); // Output: "Bob"
    kv.display(3); // Output: "Charlie"

    KeyValue<double, string> kv2;
    kv2.set(1.03, "halo 1.03");
    kv2.set(5, "halo 5");
    kv2.set(5.02, "halo 5.02");
    kv2.set(1.033, "halo 1.033"); // "halo 1.03" akan diganti menjadi "halo 1.033"
    kv2.display(1.03);
    kv2.display(5);
    kv2.display(5.02);
    return 0;
}