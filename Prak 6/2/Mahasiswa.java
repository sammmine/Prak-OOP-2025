import java.util.*;

class Mahasiswa {
    private int NIM;
    private double IPK;
    private List<String> matkul; // Tambah <String>

    Mahasiswa(int NIM, double IPK) {
        this.NIM = NIM;
        this.IPK = IPK;
        this.matkul = new ArrayList<>(); // Koreksi <>
    }

    private void addMatkul(String matkul) {
        this.matkul.add(matkul);
    }
}