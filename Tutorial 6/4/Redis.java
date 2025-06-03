import java.util.Objects;

public class Redis<K, V>{
    private K key;
    private V value;
    private long ttl; // Time To Live dalam detik

    public Redis(K key, V value, long ttl) {
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.key = key;
        this.value = value;
        this.ttl = ttl;
    }

    // Getter Key
    public K getKey() {
        return key;
    }

    // Setter Key
    public void setKey(K key) {
        this.key = key;
    }

    // Setter Value
    public void setVal(V value) {
        this.value = value;
    }

    // Getter Value dengan cek expired
    public V getVal(long elapsedSeconds) {
        if (elapsedSeconds >= ttl) {
            throw new TtlExpiredException(key + " expired");
        }
        return value;
    }

    // Mengembalikan sisa TTL
    public long getRemainingTtl(long elapsedSeconds) {
        long remaining = ttl - elapsedSeconds;
        return remaining > 0 ? remaining : 0;
    }

    // Refresh TTL (reset waktu)
    public void refresh(long newTtl) {
        if (newTtl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.ttl = newTtl;
    }

    // Perbandingan key & value sama
    public boolean isEqual(Redis<?, ?> c) {
        return Objects.equals(this.key, c.key) && Objects.equals(this.value, c.value);
    }

    // nearEQ sesuai tabel
    public int nearEQ(Redis<?, ?> c) {
        boolean keyEqual = Objects.equals(this.key, c.key);
        boolean valEqual = Objects.equals(this.value, c.value);

        if (keyEqual && valEqual) return 3;
        if (!keyEqual && valEqual) return 2;
        if (keyEqual && !valEqual) return 1;
        return 0;
    }
}
