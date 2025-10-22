# Operativni Sistemi - Sažeta Skripta

## 1. Uvod u Operativne Sisteme

**Operativni sistem** je softver koji upravlja hardverom računara i pruža usluge aplikacijama.

**Osnovni poslovi:**
- Upravljanje procesorom (raspoređivanje)
- Upravljanje memorijom (alokacija)
- Upravljanje U/I uređajima (drajveri)
- Upravljanje datotekama (organizacija)
- Upravljanje procesima (kreiranje, sinhronizacija)

**Arhitektura:**
- **Slojevita struktura**: hardware → kernel → sistemski pozivi → shell/GUI → aplikacije
- **Mikrokernel**: minimalni kernel + serveri u user space
- **Monolitni kernel**: sve u kernel space

**Interfejsi:**
- **Sistemski pozivi** - programski pristup kernelu
- **Komandni jezik** - shell (CLI) ili GUI
- **Adresni prostori** - korisnički vs. kernel prostor

---

## 2. Datoteke

**Datoteka** = imenovana kolekcija podataka na disku, osnovni mehanizam trajnog skladištenja.

**Ključni pojmovi:**
- **Deskriptor datoteke**: metapodaci (ime, veličina, lokacija, vlasnik, prava, vremena)
- **Operacije**: open → read/write → close
- **Hijerarhija**: root → direktorijumi → datoteke
- **Putanje**: apsolutne (`/home/user/file`) vs. relativne (`./file`)

**Organizacija na disku:**
- **Kontinualne datoteke**: uzastopni blokovi, brz pristup, eksterna fragmentacija
- **Rasute datoteke**: nekontinualni blokovi, tabela pristupa, lako proširenje
- **Blokovi**: jedinica skladištenja (512B-8KB)
- **Interna fragmentacija**: prazan prostor u poslednjem bloku
- **Eksterna fragmentacija**: rasuti slobodni blokovi

**Prava pristupa:**
- **Owner/Group/Others** × **Read/Write/Execute**
- **Matrica zaštite**: korisnici × datoteke → prava
- **UID/GID**: numerički identifikatori
- **SUID**: izvršavanje sa privilegijama vlasnika

**Specijalne datoteke:**
- **Blokovske** (`/dev/sda1`): diskovi
- **Znakovne** (`/dev/tty`): terminali, tastature
- **Pipes/FIFO**: IPC mehanizmi

---

## 3. Procesi i Niti

**Proces** = program u izvršavanju, osnovna jedinica izvršavanja u OS-u.

**Slika procesa:**
- **Kod** (text segment)
- **Podaci** (data segment)
- **Stek** (lokalne promenljive, pozivi funkcija)
- **Heap** (dinamička alokacija)

**Deskriptor procesa (PCB):**
- PID, PPID, UID/GID
- Stanje, prioritet, programski brojač, registri
- Tabele stranica, otvorene datoteke

**Stanja procesa:**
1. **Spreman** (ready) → čeka procesor
2. **Aktivan** (running) → izvršava se na procesoru
3. **Blokiran** (waiting) → čeka U/I ili događaj

**Prelazi:**
- Spreman → Aktivan (dispatch)
- Aktivan → Spreman (istek kvantuma)
- Aktivan → Blokiran (čekanje na U/I)
- Blokiran → Spreman (završetak U/I)

**Raspoređivanje:**
- **Kvantum**: vremenski interval dodeljeni procesu
- **Context switch**: promena aktivnog procesa (čuvanje/učitavanje stanja)
- **Kriterijumi**: prioritet, pravičnost, vreme odziva

**Niti (threads):**
- **Lagane jedinice izvršavanja** unutar procesa
- **Deljeno**: kod, podaci, heap, otvorene datoteke
- **Odvojeno**: stek, programski brojač, registri, stanje
- **Prednosti**: brzo kreiranje, lakša komunikacija (deljene promenljive)

**Tipovi:**
- **Sekvencijalni proces**: jedna nit
- **Konkurentni proces**: više niti, paralelizam

**Sistemske operacije:**
- `fork()` - kreiranje procesa (kopija roditelja)
- `exec()` - zamena slike procesa novim programom
- `exit()` - terminacija
- `wait()` - čekanje na child proces

---

## 4. Konkurentnost i Sinhronizacija

**Konkurentnost** = istovremeno izvršavanje više niti/procesa.

**Preplitanje:**
- Nedeterministički redosled instrukcija
- Uzrokuje **race conditions** - rezultat zavisi od tajminga
- **Deljene promenljive**: pristup od više niti

**Problemi:**
- **Race condition**: niti se "utrkuju" za resurs
- **Nekozistentnost podataka**: nesinhroniovan pristup

**Kritična sekcija:**
- Deo koda koji pristupa deljenim resursima
- Mora se izvršavati **atomski** (nedeljivo)
- **Međusobna isključivost** (mutual exclusion): samo jedna nit u kritičnoj sekciji

**Mehanizmi sinhronizacije:**

### Propusnice (Mutex)
- **Zaključavanje** deljenog resursa
- Operacije: `lock()`, `unlock()`
- Nit koja ne dobije mutex → blokirana

### Semafori
- **Celobrojna promenljiva** za sinhronizaciju
- Operacije: `wait()/P()` (čekaj), `signal()/V()` (oslobodi)
- **Binarni semafor** (0/1): kao mutex
- **Generalni semafor** (0..N): ograničavanje pristupa pool-u resursa

### Condition Variables
- **Uslovljena sinhronizacija**: čekanje na ispunjenje uslova
- `wait()`, `notify_one()`, `notify_all()`
- Koristi se sa mutex-om

### C++ mehanizmi:
- `std::mutex` - propusnica
- `std::unique_lock` - RAII wrapper (automatsko otključavanje)
- `std::condition_variable` - uslovljena sinhronizacija

**Lockless programiranje:**
- Bez lock-ova, koristi atomske operacije (CAS - compare-and-swap)
- **Prednosti**: bez deadlock-a, bolje performanse
- **Mane**: složeno, ABA problem

---

## 5. Klasični Problemi Sinhronizacije

### Problem Pet Filozofa
- 5 filozofa, 5 viljuški (između filozofa)
- Filozof treba 2 viljuške za jelo
- **Deadlock**: svi uzmu levu viljušku
- **Rešenja**: numerisanje resursa, arbitrar, timeout

### Problem Čitanja i Pisanja (Readers-Writers)
- Više čitalaca može istovremeno, pisac ekskluzivno
- **Izazov**: pravičnost, starvation

### Producer-Consumer
- Producer generiše podatke → bafer → Consumer konzumira
- **Ograničen bafer**: sinhronizacija preko semafora

---

## 6. Mrtva Petlja (Deadlock)

**Deadlock** = procesi međusobno čekaju jedni na druge, nijedan ne može napredovati.

**Coffman-ovi uslovi** (sva 4 moraju biti ispunjena):
1. **Mutual exclusion** - resursi ne mogu biti deljeni
2. **Hold and wait** - proces drži resurse i čeka na druge
3. **No preemption** - resursi se ne mogu oduzeti
4. **Circular wait** - kružni lanac čekanja

**Pristupi:**
- **Sprečavanje** (prevention): eliminacija jednog uslova
- **Izbegavanje** (avoidance): Banker's algoritam, sigurna stanja
- **Otkrivanje i oporavak**: detekcija ciklusa, terminacija procesa
- **Ignorisanje**: "Ostrich algorithm" (najčešći u praksi)

**Livelock** = procesi aktivni ali ne napreduju (ustupaju resurse jedni drugima).

---

## 7. Upravljanje Memorijom

**Logički adresni prostor** = adrese koje vidi proces.  
**Fizički adresni prostor** = stvarna RAM memorija.  
**Translacija** = preslikavanje logičkih u fizičke adrese.

### Tipovi Logičkog Adresnog Prostora

**1. Kontinualni:**
- Linearan prostor adresa
- Translacija: `fizička = baza + logička`
- Eksterna fragmentacija

**2. Segmentirani:**
- Podela na logičke segmente (kod, podaci, stek, heap)
- Tabela segmenata: baza + limit
- Eksterna fragmentacija

**3. Stranični (Paging):**
- Podela na stranice fiksne veličine (tipično 4KB)
- **Tabela stranica**: logička stranica → fizički frame
- **Nema eksterne fragmentacije**
- Interna fragmentacija (poslednja stranica)

**4. Stranično-segmentirani:**
- Kombinacija: segmenti podeljeni na stranice
- Dvostepena translacija

### Elementi Tabele Stranica
- **PFN** (Page Frame Number) - broj fizičke stranice
- **Present bit** - da li je u RAM-u
- **Dirty bit** - da li je modifikovana
- **Referenced bit** - da li je pristupana
- **Protection bits** - prava (r/w/x)

### Virtuelna Memorija
- **Adresni prostor veći od fizičke memorije**
- Stranice skladištene na disku (swap)
- **Demand paging**: učitavanje stranica po potrebi
- **Page fault**: stranični prekid kada stranica nije u RAM-u

**Algoritmi zamene stranica:**
- **FIFO** (First-In-First-Out)
- **LRU** (Least Recently Used)
- **Clock** (Second Chance)
- **Working Set**

**Working set** = skup aktivnih stranica procesa.  
**Thrashing** = konstanto swap-ovanje, loše performanse.

---

## 8. Raspoređivanje (Scheduling)

**Cilj**: efikasna raspodela procesorskog vremena.

**Ciljevi:**
- **Propusnost** (throughput): broj završenih procesa
- **Vreme odziva**: brza reakcija (interaktivni sistemi)
- **Pravičnost**: svi procesi dobijaju šansu
- **Iskorišćenost CPU**: procesor stalno aktivan

### Algoritmi Raspoređivanja

**1. FCFS** (First-Come-First-Served):
- Red čekanja, najprostiji
- **Mana**: convoy effect (kratki čekaju duge)

**2. Round-Robin:**
- Svi procesi dobijaju **kvantum** (10-100ms)
- Kružna rotacija
- **Dobar za interaktivne sisteme**

**3. Prioritetno:**
- Proces sa najvišim prioritetom prvi
- **Mana**: starvation niskih prioriteta
- **Rešenje**: aging (povećanje prioriteta tokom čekanja)

**4. Multi-Level Feedback Queue:**
- Više redova sa različitim prioritetima
- Procesi se pomeraju između redova
- Adaptivno raspoređivanje

**5. Real-Time:**
- **Hard real-time**: apsolutni rokovi
- **Soft real-time**: poželjni rokovi
- Deadline scheduling

**Multiprocessor Scheduling:**
- **Load balancing**: ravnomerna raspodela na jezgra
- **Processor affinity**: preferiranje istog procesora (keš)

---

## 9. Ulazno-Izlazni Sistemi

**Drajver** = softver koji upravlja hardverom, apstrakcija uređaja.

**Operacije:**
- Inicijalizacija U/I operacije
- **Interrupt handler**: obrada prekida
- **DMA** (Direct Memory Access): transfer bez CPU intervencije

**Primeri:**

**Drajver tastature:**
- **Cirkularni bafer** za znakove
- Prazan bafer → čitanje blokira
- Pun bafer → gubici znakova

**Drajver diska:**
- Blokovski pristup
- Interrupt po završetku operacije
- Buđenje čekajuće niti

---

## 10. Distribuirani Sistemi

**Distribuirani sistem** = više računara povezanih mrežom, dele resurse.

**Karakteristike:**
- **Transparentnost**: lokacije, pristupa, replikacije
- **Skalabilnost**: dodavanje resursa
- **Fault tolerance**: otpornost na greške

### RPC (Remote Procedure Call)
- **Poziv funkcije na udaljenoj mašini**
- Izgleda kao lokalni poziv
- **Marshalling**: pakovanje parametara
- **Client stub**: šalje zahtev
- **Server skeleton**: prima zahtev, poziva funkciju

**Problemi:**
- Mrežne greške (timeout, retry)
- Heterogenost (različite arhitekture)
- Semantika: at-least-once, at-most-once, exactly-once

### Mikrokernel
- **Minimalni kernel**: IPC, scheduling, osnovna memorija
- **Serveri u user space**: file system, drajveri, network
- **Prednosti**: modularnost, stabilnost
- **Mane**: performanse (više context switch-ova)

### Distribuirana Sinhronizacija
- **Logički satovi** (Lamport timestamps)
- **Vektorski satovi** - causality
- **Consensus protokoli** (Paxos, Raft)

---

## 11. Sigurnost i Zaštita

**Sigurnost** = zaštita od neovlašćenog pristupa, integritet, dostupnost.

### Autentifikacija
- **Lozinke**: heš funkcije (SHA-256), salt
- **Multi-factor**: nešto što znaš + imaš + jesi

### Autorizacija
- **ACL** (Access Control Lists): lista prava uz datoteku
- **Capabilities**: lista prava uz korisnika
- **SUID/SGID**: izvršavanje sa privilegijama vlasnika

### Kriptografija

**Heš funkcije:**
- Jednosmerne, deterministički
- SHA-256, SHA-3
- Koristi: lozinke, integritet

**Simetrična kriptografija:**
- Isti ključ za enkripciju/dekripciju
- AES, ChaCha20
- Brza, problem razmene ključa

**Asimetrična kriptografija:**
- Par ključeva: javni + privatni
- RSA, ECC
- Spora, rešava razmenu ključa
- Digitalni potpis: autentičnost, integritet

**Kerckhoffs-ov princip:**
- Sigurnost u **tajnosti ključa**, ne algoritma
- Algoritam javno poznat i testiran

---

## 12. Komandni Jezici i Shell

**Shell** = interpreter komandi, interfejs prema OS-u.

**Znakovni (CLI):**
- Komande: `program [opcije] [argumenti]`
- **Preusmeravanje**: `>` (izlaz), `<` (ulaz), `>>` (append)
- **Pipes**: `cmd1 | cmd2` - povezivanje komandi
- **Background**: `cmd &` - pozadinski proces

**Skriptovanje:**
- Bash, sh, Python skripte
- Kontrola toka: if, for, while
- Automatizacija zadataka

**Grafički (GUI):**
- Klik, drag-drop, meniji
- Intuitivniji, manje moćan za automatizaciju

**Korisničke komande**: ls, cp, mv, grep, sed  
**Administratorske komande**: useradd, systemctl, apt (zahtevaju root)

---

## 13. Praktični Koncepti

### Copy-on-Write (COW)
- Nakon `fork()`, stranice se dele dok se ne modifikuju
- Kopiranje tek pri pisanju
- Efikasnije od pune kopije

### Demand Paging
- Stranice se učitavaju u memoriju tek kad se zatraže
- Brže pokretanje procesa

### Buffer Cache
- Keš nedavno korišćenih disk blokova u RAM-u
- Read-ahead, write-behind
- Ubrzava pristup datotekama

### TLB (Translation Lookaside Buffer)
- Keš za tabelu stranica
- Hardware keš, veoma brz
- Smanjuje troškove translacije adresa

### Defragmentacija
- Spajanje rasutih slobodnih blokova
- Povećava performanse kod kontinualnih datoteka
- Sporo, periodično održavanje

---

## Zaključak

Operativni sistem je **posrednik između hardvera i aplikacija**, obezbeđujući:
- **Apstrakciju**: procesi, datoteke, virtuelna memorija
- **Multipleksiranje**: deljenje resursa između više korisnika
- **Izolaciju**: zaštita procesa jednih od drugih
- **Efikasnost**: optimalno korišćenje resursa

**Ključne oblasti**: procesi/niti, konkurentnost, memorija, U/I, datoteke, bezbednost.