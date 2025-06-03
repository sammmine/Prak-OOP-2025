import java.lang.reflect.*; // Reflection adalah API Java yang memungkinkan kita untuk mengakses informasi tentang kelas, method, field, dan konstruktor pada runtime.
import java.util.ArrayList;
import java.util.List;

public class Reflection {
    // TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    // BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    // DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

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

// Tugas anda adalah implementasi ke empat method tersebut dengan ketentuan sebagai berikut

// Terdapat sebuah kelas Ghost yang memiliki N method, dan semua method tersebut adalah private. Sesuai namanya, yaitu Ghost,
// maka isi kelas tersebut adalah misterius dan tidak diketahui baik nama method maupun return dari method tersebut (dipastikan
// return dari Ghost antara Integer dan String saja).

// Implementasi method getMethod() dimana akan membaca seluruh method yang dimiliki oleh kelas Ghost dan menyimpan nama method
// tersebut ke dalam ArrayList

// Implementasi method sumGhost() dimana akan menjumlahkan seluruh return dari method dari kelas Ghost yang memiliki kembalian Integer

// Implementasi method letterGhost() dimana akan mengembalikan concat dari seluruh method di kelas Ghost yang memiliki kembalian
// String. (Ketika concat langsung concat aja, gausah di kasih spasi atau pemisah lainnya).

// Terdapat kelas lain yang bernama Secret

// Implementasi method findSecretId(List<Secret> sl, String email) yang berfungsi akan mencari Secret
// sesuai dengan email yang hendak dicari. Apabila Secret dengan email yang dimaksud ada, maka kembalikan uniqueId dari email tersebut,
// jika tidak kembalikan NaN sesuai dengan template yang ada diatas.

// Tips, gunakan setAccessible(true) untuk mengakses method maupun attribut private / protected.

// Untuk implementasi no. 6, manfaatkan method isThis(String email)

// Untuk debugging di local teman-teman bisa membuat kelas Secret sesuai dengan template diatas, lalu memberikan uniqueId dengan String random, dan kelas Ghost dengan membuat beberapa method private yang mengembalikan Integer dan String.