import java.util.*;

public class Mobil {
    private int harga;
    private List mirip;

    Mobil(int harga) {
        this.harga = harga;
        this.mirip = new ArrayList<>();
    }

    private void tambahMobil(String name) {
        this.mirip.add(name);
    }
}
