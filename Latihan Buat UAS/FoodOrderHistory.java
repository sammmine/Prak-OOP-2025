// History order makanan di aplikasi pesan antar makanan , dimana setelah limit tertentu maka history
// paling lama akan dihapus pada penambahan berikutnya. Setiap item history terdiri atas nama resto,
// list makanan yang dipesan, dan total harga. Aplikasi bisa menampilkan list item-item dari resto
// tertentu. Pengguna juga bisa mengetahui jumlah total yang sudah dibelanjakan untuk membeli
// makanan. Implementasi diminta mempertimbangkan efisiensi memory.

import java.util.ArrayDeque;
import java.util.Queue;

class Order {
    String resto;
    String item;
    int total;

    Order(String resto, String item, int total) {
        this.resto = resto;
        this.item = item;
        this.total = total;
    }

    public String toString() {
        return resto + " - " + item + " - Rp" + total;
    }
}

public class FoodOrderHistory {
    public static void main(String[] args) {
        int limit = 3;
        Queue<Order> history = new ArrayDeque<>();

        // Menambahkan order
        history.add(new Order("Burger King", "Whopper", 50000));
        history.add(new Order("Sushi Tei", "Salmon Roll", 80000));
        history.add(new Order("KFC", "Chicken Bucket", 75000));

        // Tambahan baru, hapus yang paling lama
        if (history.size() >= limit) history.poll(); // hapus paling lama
        history.add(new Order("Dominos", "Pizza", 100000));

        // Tampilkan riwayat
        System.out.println("Riwayat Pesanan:");
        for (Order o : history) {
            System.out.println(o);
        }
    }
}
