import java.util.ArrayList;
import java.util.List;

class KoleksiKendaraan {
    private int size;
    private int neff;
    private List<Kendaraan> arr;
    public KoleksiKendaraan() {
        this.size=100;
        this.neff=0;
        this.arr=new ArrayList<>(size);
    }
    public KoleksiKendaraan(int s) {
        this.size=s;
        this.neff=0;
        this.arr=new ArrayList<>(size);
    }
    public KoleksiKendaraan(KoleksiKendaraan k) {
        this.size = k.size;
        this.neff = k.neff;
        this.arr = new ArrayList<>();
        for (Kendaraan kendaraan : k.arr) {
            this.arr.add(new Kendaraan(kendaraan));
        }
    }
    public void copyFrom(KoleksiKendaraan k) {
        this.size = k.size;
        this.neff = k.neff;
        this.arr = new ArrayList<>();
        for (Kendaraan kendaraan : k.arr) {
            this.arr.add(new Kendaraan(kendaraan));
        }
    }
    // Tidak ada destruktor
    public void printAll() {
        for (Kendaraan k : arr) {
            k.printInfo();
            System.out.println();
        }
    }
    public void add(Kendaraan k) {
        if (neff < size) {
            arr.add(new Kendaraan(k));
            neff++;
        } else {
            System.out.println("Koleksi penuh. Tidak bisa menambahkan kendaraan lagi.");
        }
    }
    public void addAll(KoleksiKendaraan k) {
        for (Kendaraan kendaraan : k.arr) {
            if (neff < size) {
                arr.add(new Kendaraan(kendaraan));
                neff++;
            } else {
                System.out.println("Koleksi penuh. Tidak semua kendaraan berhasil ditambahkan.");
                break;
            }
        }
    }
}
