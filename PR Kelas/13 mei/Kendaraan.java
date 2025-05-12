class Kendaraan {
    protected int nomor;
    protected int tahun_keluaran;
    protected String merk;
    protected String kategori;
    public Kendaraan() {
        this.nomor=0;
        this.tahun_keluaran=0;
        this.merk="XXX";
        this.kategori="kendaraan";
    }
    public Kendaraan(int n, int t, String m, String k) {
        this.nomor=n;
        this.tahun_keluaran=t;
        this.merk=m;
        this.kategori=k;
    }
    public Kendaraan(Kendaraan k) {
        this.nomor=k.nomor;
        this.tahun_keluaran=k.tahun_keluaran;
        this.merk=k.merk;
        this.kategori=k.kategori;
    }
    // Tidak punya operator overloading
    // Tidak punya destruktor
    public void printInfo() {
        System.out.println("Nomor Kendaraan: " + this.nomor);
        System.out.println("Tahun Keluaran: " + this.tahun_keluaran);
        System.out.println("Merk Kendaraan" + this.merk);
        System.out.println("Kategori Kendaraan: " + this.kategori);
    }
    public int biayaSewa(int l) {
        int hargaSewa=0;
        if (this.kategori.equals("bus")) {
            hargaSewa=1000000*l;
        } else if (this.kategori.equals("minibus")) {
            if (l <= 5) {
                hargaSewa=5000000;
            } else {
                hargaSewa=5000000+500000*(l-5);
            }
        } else if (this.kategori.equals("mobil")) {
            hargaSewa=500000*l;
        }
        System.out.println("Biaya sewa kendaraan ini adalah: " + hargaSewa);
        return hargaSewa;
    }
}