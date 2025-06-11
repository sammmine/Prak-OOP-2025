import java.lang.reflect.*;

public class MobilDecoder {
    Mobil m;

    MobilDecoder(Mobil m) {
        this.m = m;
    }

    public void tambahMobil(String name) throws Exception {
        Method method = Mobil.class.getDeclaredMethod("tambahMobil", String.class);
        method.setAccessible(true);
        method.invoke(m, name);
    }

    public int getHarga() throws Exception {
        Field field = Field.class.getDeclaredField("harga");
        field.setAccessible(true);
        return (int) field.get(m);
    }
}
