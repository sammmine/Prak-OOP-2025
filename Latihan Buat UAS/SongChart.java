// Chart lagu di radio, dimana urutan lagu berubah setiap minggu. Sebuah lagu bisa menempati posisi
// tertentu, kemudian minggu berikutnya bisa naik posisinya atau terlempar dari chart. Radio bisa
// memutar lagu berdasarkan urutan posisi chart tersebut dan bisa mencari posisi lagu tersebut di
// chart minggu ini.

// Memanfaatkan List karena Chart harus punya urutan tertentu.

import java.util.*;

public class SongChart {
    public static void main(String[] args) {
        List<String> chart = new ArrayList<>();

        chart.add("Better Than Revenge - Taylor Swift");
        chart.add("Nirwana - Adikara");
        chart.add("Untitled - Maliq & The Essentials");
        chart.add("Apa Kabar - Radhini");

        // Urutan sekarang
        // 1. Better Than Revenge
        // 2. Nirwana
        // 3. Untitled
        // 4. Apa Kabar

        // Misal, di minggu setelahnya
        // Lagu 4 naik ke posisi pertama

        chart.remove(3);
        chart.add(0, "Apa Kabar - Radhini");

        for (int i=0; i<chart.size(); i++) {
            System.out.println(chart.get(i));
        }

        // Urutannya menjadi
        // 1. Apa Kabar
        // 2. Better Than Revenge
        // 3. Nirwana
        // 4. Untitled
    }
}
