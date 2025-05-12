class Minibus extends Kendaraan {
    public Minibus() {
        super();
        this.kategori="minibus";
    }
    public Minibus(int n, int t, String m, String k) {
        super(n, t, m, k);
    }
    public Minibus(Minibus k) {
        this.nomor=k.nomor;
        this.tahun_keluaran=k.tahun_keluaran;
        this.merk=k.merk;
        this.kategori=k.kategori;
    }
    // Tidak ada operator overloading
    @Override
    public void printInfo() {
        super.printInfo();
    }
    @Override
    public int biayaSewa(int l) {
        int hargaSewa=0;
        if (l <= 5) {
            hargaSewa=5000000;
        } else {
            hargaSewa=5000000+500000*(l-5);
        }
        return hargaSewa;
    }
    public void diskon(int l) {
        double hargaSewa = biayaSewa(l);
        if (l > 10) {
            hargaSewa=0.9*hargaSewa;
        }
        System.out.println("Setelah diskon, biaya sewa kendaraan ini adalah: " + hargaSewa);
    }
}
