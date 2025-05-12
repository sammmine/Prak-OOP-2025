class Bus extends Kendaraan {
    private int kapasitas;
    public Bus() {
        super();
        this.kategori="bus";
        this.kapasitas=0;
    }
    public Bus(int n, int t, String m, String k, int ka) {
        super(n, t, m, k);
        this.kapasitas=ka;
    }
    public Bus(Bus k) {
        this.nomor=k.nomor;
        this.tahun_keluaran=k.tahun_keluaran;
        this.merk=k.merk;
        this.kategori=k.kategori;
        this.kapasitas=k.kapasitas;
    }
    // Tidak ada operator overloading
    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Kapasitas: " + this.kapasitas);
    }
    @Override
    public int biayaSewa(int l) {
        int hargaSewa=1000000*l;
        System.out.println("Biaya sewa kendaraan ini adalah: " + hargaSewa);
        return hargaSewa;
    }
}