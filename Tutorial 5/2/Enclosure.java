import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        // Inisialisasi ArrayList animals kosong
        this.animals = new ArrayList<Animal>();
    } 

    public int getAnimalCount() {
        // Mengembalikan jumlah hewan dalam this.animals
        return this.animals.size();
    }

    public void addAnimal(Animal animal) {
        // menambahkan seekor hewan ke dalam this.animals
        this.animals.add(animal);
    }

    public Animal getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
        return this.animals.get(i);
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
        this.animals.remove(i);
    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
        return this.animals.isEmpty();
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
        if (this.animals.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            System.out.println("Kandang berisi " + this.animals.size() + " ekor hewan:");
            for (int i=0; i<this.animals.size(); i++) {
                Animal animal = this.animals.get(i);
                System.out.println((i+1) + ". " + animal.getName() + ", spesies " + animal.getSpecies() + ", umur " + animal.getAge() + " tahun");
            }
        }
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
        if (this.animals.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            for (int i=0; i<this.animals.size(); i++) {
                Animal animal = this.animals.get(i);
                // System.out.print(animal.getName() + " ");
                animal.eat();
            }
        }
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
        for (int i=0; i<this.animals.size(); i++) {
            if (!this.animals.get(i).isFriendly()) {
                return false;
            }
        }
        return true;
    }

    // public static void main(String[] args) {
    //     // Buatlah objek Enclosure dengan nama myEnclosure
    //     Enclosure myEnclosure = new Enclosure();

    //     // Buatlah objek Animal dengan nama panda1, panda2, dan panda3
    //     Animal panda1 = new Panda("Panda1", 10);
    //     Animal lion1 = new Lion("Lion1", 5);
    //     Animal panda2 = new Panda("Panda2", 10);

    //     // Tambahkan panda1, panda2, dan panda3 ke dalam myEnclosure
    //     myEnclosure.addAnimal(panda1);
    //     myEnclosure.addAnimal(panda2);
    //     myEnclosure.addAnimal(lion1);

    //     // Tampilkan jumlah hewan dalam myEnclosure
    //     System.out.println("Jumlah hewan dalam kandang: " + myEnclosure.getAnimalCount());

    //     // Tampilkan deskripsi kandang
    //     myEnclosure.describe();

    //     // Beri makan semua hewan dalam kandang
    //     myEnclosure.feed();

    //     // Tampilkan apakah kandang aman untuk dijamah
    //     System.out.println("Kandang aman untuk dijamah: " + myEnclosure.safeForPetting());
    // }
}