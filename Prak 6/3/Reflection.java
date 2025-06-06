import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.List;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    private Object createGhostInstance() throws Exception {
        Class<?> ghostClass = Class.forName("Ghost");
        return ghostClass.getDeclaredConstructor().newInstance();
    }

    private Class<?> getGhostClass() throws Exception {
        return Class.forName("Ghost");
    }

    public ArrayList<String> ghostMethods() throws Exception {
        // Tujuan: Mendapatkan nama-nama method yang ada di kelas Ghost
        ArrayList<String> methods = new ArrayList<>();
        Class<?> ghostClass = getGhostClass();
        Method[] declaredMethods = ghostClass.getDeclaredMethods(); // Mendapatkan semua method yang dideklarasikan dalam kelas Ghost
        for (Method method : declaredMethods) {
            methods.add(method.getName()); // Menambahkan nama method ke dalam ArrayList
        }
        return methods;
    }

    public Integer sumGhost() throws Exception {
        // Tujuan: Menghitung jumlah dari semua method di kelas Ghost yang mengembalikan Integer
        int sum = 0;
        Class<?> ghostClass = getGhostClass();
        Object ghostObject = createGhostInstance();
        Method[] declaredMethods = ghostClass.getDeclaredMethods(); // Mendapatkan semua method yang dideklarasikan dalam kelas Ghost
        for (Method method : declaredMethods) {
            method.setAccessible(true); // Mengizinkan akses ke method private
            Object result = method.invoke(ghostObject); // Memanggil method pada objek Ghost
            if (result instanceof Integer) { // Memeriksa apakah hasilnya adalah Integer
                sum += (Integer) result; // Jika ya, tambahkan ke jumlah
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception {
        // Tujuan: Menggabungkan hasil dari semua method di kelas Ghost yang mengembalikan String
        StringBuilder sb = new StringBuilder();
        Class<?> ghostClass = getGhostClass();
        Object ghostObject = createGhostInstance();
        Method[] declaredMethods = ghostClass.getDeclaredMethods();
        for (Method method : declaredMethods) {
            method.setAccessible(true); // Mengizinkan akses ke method private
            Object result = method.invoke(ghostObject); // Memanggil method pada objek Ghost
            if (result instanceof String) { // Memeriksa apakah hasilnya adalah String
                sb.append((String) result); // Jika ya, tambahkan ke StringBuilder
            }
        }
        return sb.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        // Tujuan: Mencari Secret berdasarkan email dan mengembalikan uniqueId jika ditemukan, atau "NaN" jika tidak
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                Field field = Secret.class.getDeclaredField("uniqueId"); // Mengakses field private uniqueId dari kelas Secret
                field.setAccessible(true); // Mengizinkan akses ke field private
                return (String) field.get(secret); // Mengambil nilai uniqueId dari objek Secret
            }
        }
        return "NaN";
    }
}