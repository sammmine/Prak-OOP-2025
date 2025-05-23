import java.util.LinkedList;
import java.util.List;

/**
 * Implementasi dari interface SistemMasukSekolahList menggunakan LinkedList
 * PETUNJUK:
 * - Gunakan LinkedList sebagai struktur data utama
 * - Manfaatkan fitur Java Collections
 */
public class SistemMasukSekolahListImpl implements SistemMasukSekolahList {
    
    // Atribut: gunakan LinkedList<Student> untuk menyimpan data siswa
    private LinkedList<Student> students;
    
    /**
     * Constructor: inisialisasi LinkedList students
     */
    public SistemMasukSekolahListImpl() {
        this.students = new LinkedList<>();
    }
    
    @Override
    public void addStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa ke dalam list
        this.students.add(student);
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di awal list
        this.students.addFirst(student);
    }
    
    @Override
    public void addLastStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di akhir list
        this.students.addLast(student);
    }
    
    @Override
    public Student getFirstStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa pertama di list
        if (!students.isEmpty()) {
            return students.getFirst();
        }
        return null;
    }
    
    @Override
    public Student getLastStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa terakhir di list
        if (!students.isEmpty()) {
            return students.getLast();
        }
        return null;
    }
    
    @Override
    public Student removeFirstStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa pertama di list
        if (!students.isEmpty()) {
            return students.removeFirst();
        }
        return null;
    }
    
    @Override
    public Student removeLastStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa terakhir di list
        if (!students.isEmpty()) {
            return students.removeLast();
        }
        return null;
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus
        int initialSize = students.size();
        students.removeIf(student -> student.getGpa() < minGpa);
        return initialSize - students.size();
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan GPA >= minGpa
        List<Student> highGpaStudents = new LinkedList<>();
        for (Student student : students) {
            if (student.getGpa() >= minGpa) {
                highGpaStudents.add(student);
            }
        }
        return highGpaStudents;
    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan umur tertentu
        List<Student> ageStudents = new LinkedList<>();
        for (Student student : students) {
            if (student.getAge() == age) {
                ageStudents.add(student);
            }
        }
        return ageStudents;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        List<String> youngHighAchieverNames = new LinkedList<>();
        for (Student student : students) {
            if (student.getAge() < maxAge && student.getGpa() >= minGpa) {
                youngHighAchieverNames.add(student.getName());
            }
        }
        return youngHighAchieverNames;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // TODO: Implementasikan method ini
        // Mengembalikan seluruh siswa dalam list
        return new LinkedList<>(students);
    }
}