import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa; // Deklarasi variabel mahasiswa

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Class<?> mahasiswaClass = mahasiswa.getClass();
        Method addMatkulMethod = mahasiswaClass.getDeclaredMethod("addMatkul", String.class);
        addMatkulMethod.setAccessible(true);
        addMatkulMethod.invoke(mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Class<?> mahasiswaClass = mahasiswa.getClass();
        Field nimField = mahasiswaClass.getDeclaredField("NIM");
        nimField.setAccessible(true);
        return (int) nimField.get(mahasiswa);
    }

    public double getIPK() throws Exception {
        Class<?> mahasiswaClass = mahasiswa.getClass();
        Field ipkField = mahasiswaClass.getDeclaredField("IPK");
        ipkField.setAccessible(true);
        return (double) ipkField.get(mahasiswa);
    }

    // public static void main(String[] args) {
    //     try {
    //         Mahasiswa mahasiswa = new Mahasiswa(123456, 3.75);
    //         MahasiswaDecoder decoder = new MahasiswaDecoder(mahasiswa);
    //         decoder.addMatkul("Matematika");
    //         System.out.println("NIM: " + decoder.getNIM());
    //         System.out.println("IPK: " + decoder.getIPK());
    //     } catch (Exception e) {
    //         e.printStackTrace();
    //     }
    // }
}
