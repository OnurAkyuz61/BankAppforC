# Basit Banka Uygulaması

Bu proje, C dilinde yazılmış basit bir banka uygulamasıdır. Kullanıcılar hesap oluşturabilir, para yatırabilir, para çekebilir ve bakiye görüntüleyebilir.

## Özellikler
- Hesap oluşturma
- Para yatırma
- Para çekme
- Bakiye görüntüleme

## Kullanım
Programı çalıştırdıktan sonra, kullanıcılar menü aracılığıyla çeşitli işlemleri seçebilirler:
1. Hesap oluştur
2. Para yatır
3. Para çek
4. Bakiye görüntüle
5. Çıkış

## Fonksiyonlar
- `void createAccount(Account accounts[], int *numAccounts)`: Yeni bir hesap oluşturur.
- `void deposit(Account *account, double amount)`: Hesaba para yatırır.
- `void withdraw(Account *account, double amount)`: Hesaptan para çeker.
- `void displayAccount(const Account *account)`: Hesap bilgilerini görüntüler.
- `Account* findAccount(Account accounts[], int numAccounts, int accountNumber)`: Hesap numarasına göre hesabı bulur.

## Derleme ve Çalıştırma
Bu projeyi derlemek ve çalıştırmak için aşağıdaki adımları izleyin:

### Gerekli Araçlar
- GCC (GNU Compiler Collection)

### Derleme
1. Proje dosyasını indirin veya klonlayın.
2. Terminal veya komut istemcisini açın.
3. Aşağıdaki komutu kullanarak projeyi derleyin:
    ```sh
    gcc -o bankApp main.c
    ```

### Çalıştırma
1. Aşağıdaki komutu kullanarak uygulamayı başlatın:
    ```sh
    ./bankApp
    ```
