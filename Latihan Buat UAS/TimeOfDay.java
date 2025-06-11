public class TimeOfDay {
    int h,m,s;

    public TimeOfDay(int seconds) throws IllegalArgumentException {
        if (seconds < 0 || seconds > 86399) { throw new IllegalArgumentException("Input harus antara 0 sampai 86399 detik"); }

        h = seconds / 3600;
        int rem = seconds % 3600;
        m = rem / 60;
        s = rem % 60;

        assert (h * 3600 + m * 60 + s == seconds);
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d:%02d", h, m, s);
    }

    public static void main(String[] args) {
        try {
            TimeOfDay t = new TimeOfDay(0);
            System.out.println(t);
            t = new TimeOfDay(77777);
            System.out.println(t);
            t = new TimeOfDay(99999);
            System.out.println(t);
        } catch (IllegalArgumentException e) {
            System.out.println("Input tidak valid!");
        } 
    }

}
