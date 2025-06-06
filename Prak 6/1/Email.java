public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */

        // 1. Memeriksa apakah kosong
        if (email == null || email.isEmpty()) {
            throw new InvalidEmailException("Email tidak boleh kosong");
        }

        // 2. Memeriksa apakah ada karakter '@'
        int atCount = 0;
        for (char c : email.toCharArray()) {
            if (c == '@') atCount++;
        }
        if (atCount != 1) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        }

        // 3. Memeriksa apakah '@' di awal
        int atIndex = email.indexOf('@');
        if (atIndex == 0) {
            throw new InvalidEmailException("@ tidak boleh di awal email");
        }

        // 4. Memeriksa validitas domain
        // a. Memeriksa apakah setelah '@' ada '.'
        // b. Memeriksa apakah setelah '@' tidak diawali dengan '.' (ex: john@.com) dan tidak diakhiri dengan '.' (ex: john@com.)
        String domain = email.substring(atIndex + 1);
        int dotCount = 0;
        for (char c : domain.toCharArray()) {
            if (c == '.') dotCount++;
        }
        if (dotCount != 1) {
            throw new InvalidDomainException();
        }
        if (domain.startsWith(".") || domain.endsWith(".")) {
            throw new InvalidDomainException();
        }

        return true;
    }
}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        super(message);
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid"
        return "Email harus memiliki domain yang valid";
    }
}