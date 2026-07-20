# Bank Account System

Aplikasi CLI (Command Line Interface) sistem perbankan sederhana yang dibangun dengan C++17.

## Fitur

- **Create Account** - Buat rekening baru dengan setoran awal
- **Deposit** - Setor uang ke rekening
- **Withdraw** - Tarik uang dari rekening
- **Transfer** - Transfer antar rekening
- **Check Balance** - Cek saldo rekening
- **Transaction History** - Lihat riwayat transaksi lengkap
- **List All Accounts** - Lihat semua rekening yang terdaftar

## Struktur Project

```
bank-system/
├── CMakeLists.txt
├── .gitignore
├── README.md
└── src/
    ├── include/
    │   ├── Transaction.h
    │   ├── BankAccount.h
    │   └── Bank.h
    ├── BankAccount.cpp
    ├── Bank.cpp
    └── main.cpp
```

## Cara Build & Jalankan

### Menggunakan g++ (MinGW)

```bash
g++ -std=c++17 -o bank-system.exe src/main.cpp src/BankAccount.cpp src/Bank.cpp -I src
```

### Menggunakan CMake

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Menjalankan

```bash
./bank-system.exe
```

## Contoh Penggunaan

```
========================================
      BANK ACCOUNT SYSTEM
========================================
  1. Create New Account
  2. Deposit
  3. Withdraw
  4. Transfer
  5. Check Balance
  6. Transaction History
  7. List All Accounts
  0. Exit
========================================
  Choose: 1

--- Create New Account ---
Owner name: Budi Santoso
Initial deposit (Rp): 1000000

[SUCCESS] Account created!
  ACC-0001 | Budi Santoso | Balance: Rp 1000000.00
```

## Tech Stack

- **Language:** C++17
- **Compiler:** g++ (MinGW) / MSVC
- **Build:** CMake (optional)
