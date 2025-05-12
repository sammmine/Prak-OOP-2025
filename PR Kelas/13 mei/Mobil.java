class Mobil extends Kendaraan {
    private String supir;
    public Mobil() {
        super();
        this.kategori="mobil";
        this.supir="XXX";
    }
    public Mobil(int n, int t, String m, String k, String s) {
        super(n, t, m, k);
        this.supir=s;
    }
    public Mobil(Mobil k) {
        this.nomor=k.nomor;
        this.tahun_keluaran=k.tahun_keluaran;
        this.merk=k.merk;
        this.kategori=k.kategori;
        this.supir=k.supir;
    }
    // Tidak ada operator overloading
    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Supir: " + this.supir);
    }
    @Override
    public int biayaSewa(int l) {
        int hargaSewa=500000*l;
        System.out.println("Biaya sewa kendaraan ini adalah: " + hargaSewa);
        return hargaSewa;
    }
}